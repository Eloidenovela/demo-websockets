#pragma once

#include <drogon/WebSocketController.h>
#include <drogon/PubSubService.h>

using namespace drogon;

namespace api
{
namespace v1
{
    class api_v1_message : public drogon::WebSocketController<api_v1_message>
    {
        PubSubService<std::string> chat_rooms;

    public:
        void handleNewMessage(const WebSocketConnectionPtr&, std::string &&, const WebSocketMessageType &) override;
        void handleNewConnection(const HttpRequestPtr &, const WebSocketConnectionPtr&) override;
        void handleConnectionClosed(const WebSocketConnectionPtr&) override;
        WS_PATH_LIST_BEGIN
        WS_PATH_ADD("/chat", Post, Get, "api::api_token_filter", "api::api_session_filter");
        WS_PATH_LIST_END
    };
}
}