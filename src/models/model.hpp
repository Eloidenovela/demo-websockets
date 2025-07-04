//
// Created by eloide-novela on 24-06-2025.
//

#pragma once

#include <sqlite_orm/sqlite_orm.h>
#include "user.hpp"
#include "../configurations/configuration.hpp"
#include <iostream>

namespace model 
{
    inline auto get_storage()
    {
        static auto storage = sqlite_orm::make_storage(
            configuration::get_db_filename(),
            model::user::make_table()
        );
        storage.sync_schema();
        for (const auto & [name, result]: storage.sync_schema())
        {
            std::cout << "[sync " << name << ": " << result << "]" << std::endl;
        }
        return storage;
    }
}