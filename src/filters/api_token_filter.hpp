//
// Created by eloide-novela on 24-06-2025.
//

#pragma once
#include "drogon/HttpFilter.h"

using namespace drogon;

namespace api
{
    class api_token_filter final: public HttpFilter<api_token_filter>
    {
        auto get_service();
    public:
        void doFilter(const HttpRequestPtr& req, FilterCallback&& fcb, FilterChainCallback&& fccb) override;
    };
}