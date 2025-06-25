//
// Created by eloide-novela on 24-06-2025.
//

#include "configuration.hpp"
#include "json/reader.h"
#include "json/value.h"
#include <fstream>
#include <glog/logging.h>

extern Json::Value env;

namespace configuration 
{
    void load_config(Json::Value &env)
    {
        LOG(INFO) << __FUNCTION__;
        const std::string config_filename = "env.json";
        std::ifstream stream(config_filename);
        if (not stream.is_open())
        {
            LOG(WARNING) << "Failed to open configuration file: " << config_filename;
        }
        Json::Value config_json;
        Json::Reader reader;
        reader.parse(stream, config_json);
        env = config_json["demo-websockets"];
    }

    std::string get_db_filename()
    {
        return env["database"]["path"].asString();
    }
}