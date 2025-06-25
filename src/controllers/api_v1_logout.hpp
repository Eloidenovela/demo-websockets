//
// Created by eloide-novela on 24-06-2025.
//

#pragma once

#include <drogon/drogon.h>
using namespace drogon;

namespace api
{
namespace v1
{
    class api_v1_logout final : public HttpSimpleController<api_v1_logout>
    {
      public:
        PATH_LIST_BEGIN
            PATH_ADD("/logout", Post, "api::api_token_filter", "api::api_session_filter");
        PATH_LIST_END
        void asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) override;
    };
}
}
