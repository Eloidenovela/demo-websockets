#pragma once

#include "../services/user.hpp"
#include "json/value.h"

namespace migration 
{
namespace user 
{   
    template <typename Storage>
    inline void apply(Storage& storage, const Json::Value& m)
    {
        auto service = service::user(storage);
        for (auto &user: m) 
        {   
            auto created_user = model::user::from_json(user);
            if (service.create(created_user) == (-1))
                LOG(WARNING) << "user with: " << created_user.phone << " was not created";
        }
    }
}
}