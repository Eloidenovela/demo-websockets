//
// Created by eloide-novela on 24-06-2025.
//

#include "api_token_filter.hpp"
#include "drogon/HttpRequest.h"
#include "../models/model.hpp"
#include "drogon/HttpResponse.h"
#include "drogon/HttpTypes.h"

extern Json::Value env;

namespace api
{
    auto api_token_filter::get_service()
    {
        // static auto storage = model::get_storage();
        // static auto service = service::api_token(storage);
        // return service;
    }

    void api_token_filter::doFilter(const HttpRequestPtr& req, FilterCallback&& fcb, FilterChainCallback &&fccb)
    {
        auto token = req->getHeader("api-token");
        // if (get_service().validate(token))
        if (token == env["api-token"].asString())
        {
            //Passed
            fccb();
            return;
        }
        //Check failed
        fcb(HttpResponse::newHttpResponse(HttpStatusCode::k401Unauthorized, ContentType::CT_NONE));
    }
}