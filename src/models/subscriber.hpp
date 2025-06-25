//
// Created by eloide-novela on 23-06-2025.
//
#pragma once
#include <string>
#include <drogon/PubSubService.h>

namespace model
{
    struct subscriber
    {
        std::string chat_room_name;
        drogon::SubscriberID id;
    };
}
