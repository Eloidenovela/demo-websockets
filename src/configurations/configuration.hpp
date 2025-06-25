//
// Created by eloide-novela on 24-06-2025.
//

#pragma once

#include "json/value.h"

namespace configuration 
{
    void load_config(Json::Value& config);
    std::string get_db_filename();
}