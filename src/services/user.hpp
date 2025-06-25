//
// Created by eloide-novela on 24-06-2025.
//

#pragma once

#include "crud.hpp"
#include "../models/user.hpp"
#include <optional>

namespace service {
    // @brief S -> storage
    template <typename S>
    class user final: public crud<S, model::user> {
    public:
        explicit user(S & storage) : crud<S, model::user>(storage) {}
        ~user() override {};

        std::optional<model::user> get(const std::string & phone, const std::string & passwd) {
            using namespace sqlite_orm;
            try {
                auto user = this->storage.template get_all<model::user>(
                    where(
                        and_(
                            is_equal(&model::user::phone, phone),
                            is_equal(&model::user::passwd, passwd)
                        )
                    )
                );
                if (not user.empty()) {
                    return user.front();
                }
            } catch (const std::exception & e) {
                LOG_ERROR << e.what();
            }
            return std::nullopt;
        }
    };
}