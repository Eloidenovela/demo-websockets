#include "api_v1_message.hpp"

#include "../models/subscriber.hpp"

namespace api
{
namespace v1
{
    void api_v1_message::handleNewMessage(const WebSocketConnectionPtr& wsConnPtr, std::string &&message, const WebSocketMessageType &type)
    {
        // LOG_INFO << "new websocket message: " << message;
        if (type == WebSocketMessageType::Ping) {
            LOG_INFO << "Ping";
        } else if (type == WebSocketMessageType::Text) {
            const auto &s = wsConnPtr->getContext<model::subscriber>();
            chat_rooms.publish(s->chat_room_name, message);
        }
    }

    void api_v1_message::handleNewConnection(const HttpRequestPtr &req, const WebSocketConnectionPtr& wsConnPtr)
    {
        LOG_INFO << "new connection";
        wsConnPtr->send("Hello");
        model::subscriber subscriber;
        subscriber.chat_room_name = req->getParameter("room_name");
        subscriber.id = chat_rooms.subscribe(subscriber.chat_room_name,
            [wsConnPtr](const std::string &topic, const std::string & message) {
                (void)topic;
                wsConnPtr->send(message);
            });
        wsConnPtr->setContext(std::make_shared<model::subscriber>(std::move(subscriber)));
    }

    void api_v1_message::handleConnectionClosed(const WebSocketConnectionPtr& wsConnPtr)
    {
        LOG_INFO << "websocket closed";
        const auto &s = wsConnPtr->getContext<model::subscriber>();
        chat_rooms.unsubscribe(s->chat_room_name, s->id);
    }
}
}
