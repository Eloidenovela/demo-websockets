//
// Created by eloide-novela on 24-06-2025.
//

#pragma once
#include <string>
#include <json/json_features.h>

namespace model {
    struct user {
        long id;
        std::string phone;
        std::string passwd;
        std::string created_at,
                    updated_at;

        static user from_json(const Json::Value &json) {
            model::user new_user;
            new_user.id = json["id"].asInt();
            new_user.phone = json["phone"].asString();
            new_user.passwd = json["passwd"].asString();
            new_user.created_at = json["created_at"].asString();
            new_user.updated_at = json["updated_at"].asString();
            return new_user;
        }

        static Json::Value to_json(const model::user &user) {
            Json::Value json;
            json["id"] = user.id;
            json["phone"] = user.phone;
            json["passwd"] = user.passwd;
            json["created_at"] = user.created_at;
            json["updated_at"] = user.updated_at;
            return json;
        }

        static auto make_table() {
            using namespace sqlite_orm;
            return sqlite_orm::make_table(
                "users",
                make_column("id", &model::user::id, primary_key().autoincrement()),
                make_column("phone", &model::user::phone, unique()),
                make_column("passwd", &model::user::passwd),
                make_column("created_at", &model::user::created_at),
                make_column("updated_at", &model::user::updated_at)
            );
        }
    };
}
