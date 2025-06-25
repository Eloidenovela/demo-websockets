//
// Created by eloide-novela on 24-06-2025.
//
#include "boot.hpp"
#include "configuration.hpp"
#include "json/value.h"
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <glog/logging.h>
#include <drogon/drogon.h>
#include "../migrations/migration.hpp"

Json::Value env;

namespace configuration
{
    void setup_directories(const Json::Value &env) try {
        LOG(INFO) << __FUNCTION__;
        for (const auto& dir: env)
        {
            if (not std::filesystem::create_directories(dir.asString())) 
            {
                LOG(WARNING) << dir << " not created";
            }
        }
    } catch (const std::filesystem::filesystem_error & e) {
        LOG(ERROR) << e.what();
    } catch (const std::exception & e) {
        LOG(ERROR) << e.what();
    }

    void setup_server(const Json::Value &env)
    {
        LOG(INFO) << __FUNCTION__;
        try {
            using namespace drogon;
            const auto addr = env["addr"].asString();
            const auto port = env["port"].asInt();
            LOG(INFO) << "access api at http://" << addr << ":" << port;
            app()
                .addListener(addr, port)
                .enableSession(300) // 5 minutes
                .run();
        } catch (const std::exception& e) {
            LOG(FATAL) << e.what();
        }
    }

    void boot() try
    {   
        load_config(env);

        setup_directories(env["directories"]);

        migration::migrate(env["migrations"]);

        LOG(INFO) << "starting api";

        setup_server(env["server"]);

        LOG(INFO) << "stoping api";
    } catch (const std::exception & e) {
        LOG(FATAL) << e.what();
    } 
}