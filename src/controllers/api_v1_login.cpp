//
// Created by eloide-novela on 24-06-2025.
//

#include "api_v1_login.hpp"
#include "../models/model.hpp"
#include "../services/user.hpp"

namespace api
{
namespace v1
{
    auto api_v1_login::get_service() {
        static auto storage = model::get_storage();
        static auto service = ::service::user(storage);
        return service;
    }

    void api_v1_login::asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
        if (auto & body = req->getJsonObject()) {
            const auto & [phone, passwd] = std::make_tuple(
                (*body)["phone"].asString(),
                (*body)["passwd"].asString()
            );

            if (const auto & user = get_service().get(phone, passwd)) {
                const auto & res = HttpResponse::newHttpJsonResponse(model::user::to_json(*user));
                HttpStatusCode status_code = HttpStatusCode::k200OK;

                if (auto & session = req->getSession()) {
                    session->insert("is_verified", true);
                    status_code = HttpStatusCode::k200OK;
                } else {
                    status_code = HttpStatusCode::k503ServiceUnavailable;
                }
                res->setStatusCode(status_code);

                return callback(res);
            }
            return callback(HttpResponse::newHttpResponse(HttpStatusCode::k401Unauthorized, ContentType::CT_NONE));
        }
        return callback(HttpResponse::newHttpResponse(HttpStatusCode::k400BadRequest, ContentType::CT_NONE));
    }
}
}
