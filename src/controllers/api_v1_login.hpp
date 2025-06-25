//
// Created by eloide-novela on 24-06-2025.
//

#pragma once

#include <drogon/drogon.h>

using namespace drogon;

namespace api {
    namespace v1 {
        class api_v1_login final : public  HttpSimpleController<api_v1_login> {
            auto get_service();
            public:
                PATH_LIST_BEGIN
                    PATH_ADD("/login", Post, "api::api_token_filter");
                PATH_LIST_END
                void asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) override;
        };
    }
}