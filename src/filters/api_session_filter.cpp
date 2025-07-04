//
// Created by eloide-novela on 24-06-2025.
//

#include "api_session_filter.hpp"
#include "drogon/HttpRequest.h"
#include "drogon/HttpResponse.h"
#include "drogon/HttpTypes.h"

namespace api
{
    void api_session_filter::doFilter(const HttpRequestPtr& req, FilterCallback&& fcb, FilterChainCallback &&fccb)
    {
        if (auto & session = req->getSession())
        {
            if (*session->getOptional<bool>("is_verified")) {
                fccb();
                return;
            }
        }

        fcb(HttpResponse::newHttpResponse(HttpStatusCode::k401Unauthorized, ContentType::CT_NONE));
    }
}
