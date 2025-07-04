# this is the build file for project 
# it is autogenerated by the xmake build system.
# do not edit by hand.

# project
cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0091 NEW)
project(demo-websocketsd LANGUAGES CXX)

# target
add_executable(demo-websocketsd "")
set_target_properties(demo-websocketsd PROPERTIES OUTPUT_NAME "demo-websocketsd")
set_target_properties(demo-websocketsd PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/linux/x86_64/release")
target_include_directories(demo-websocketsd SYSTEM PRIVATE
    /home/eloide-novela/.xmake/packages/d/drogon/v1.9.8/5421a13032b946ae97865412c8c4ec1f/include
    /home/eloide-novela/.xmake/packages/j/jsoncpp/1.9.6/ec31d39f1e07482da649befb0d975378/include
    /usr/include/uuid
    /home/eloide-novela/.xmake/packages/t/trantor/v1.5.22/2975020a386f447fb56d67b9200fd940/include
    /home/eloide-novela/.xmake/packages/o/openssl/1.1.1-w/6c51ab6278e2479b883dffafac69fdaf/include
    /home/eloide-novela/.xmake/packages/c/c-ares/1.34.4/9556091e47b04feda1b2c9684aabeabc/include
    /home/eloide-novela/.xmake/packages/s/sqlite_orm/v1.9.1/7e37f76f8ef24e7eb517a01a12580cb6/include
    /home/eloide-novela/.xmake/packages/s/sqlite3/3.49.0+100/f46f322288074a479268a2e040d212a6/include
    /home/eloide-novela/.xmake/packages/g/glog/v0.7.1/99fdb614db3440a2b3aee6077200beea/include
    /home/eloide-novela/.xmake/packages/g/gflags/v2.2.2/0f545414272c459b907061d5e923ed20/include
)
target_compile_definitions(demo-websocketsd PRIVATE
    CARES_STATICLIB
)
target_compile_options(demo-websocketsd PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-m64>
    $<$<COMPILE_LANGUAGE:CXX>:-m64>
    $<$<COMPILE_LANGUAGE:C>:-DNDEBUG>
    $<$<COMPILE_LANGUAGE:CXX>:-DNDEBUG>
    $<$<COMPILE_LANGUAGE:CUDA>:-DNDEBUG>
)
set_target_properties(demo-websocketsd PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(demo-websocketsd PRIVATE)
if(MSVC)
    target_compile_options(demo-websocketsd PRIVATE $<$<CONFIG:Release>:-O2>)
else()
    target_compile_options(demo-websocketsd PRIVATE -O3)
endif()
if(MSVC)
else()
    target_compile_options(demo-websocketsd PRIVATE -fvisibility=hidden)
endif()
if(MSVC)
    set_property(TARGET demo-websocketsd PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_link_libraries(demo-websocketsd PRIVATE
    drogon
    jsoncpp
    brotlidec
    brotlienc
    brotlicommon
    z
    uuid
    trantor
    ssl
    crypto
    cares
    sqlite3
    glog
    gflags
    pthread
    dl
)
target_link_directories(demo-websocketsd PRIVATE
    /home/eloide-novela/.xmake/packages/d/drogon/v1.9.8/5421a13032b946ae97865412c8c4ec1f/lib
    /home/eloide-novela/.xmake/packages/j/jsoncpp/1.9.6/ec31d39f1e07482da649befb0d975378/lib
    /home/eloide-novela/.xmake/packages/t/trantor/v1.5.22/2975020a386f447fb56d67b9200fd940/lib
    /home/eloide-novela/.xmake/packages/o/openssl/1.1.1-w/6c51ab6278e2479b883dffafac69fdaf/lib
    /home/eloide-novela/.xmake/packages/c/c-ares/1.34.4/9556091e47b04feda1b2c9684aabeabc/lib
    /home/eloide-novela/.xmake/packages/s/sqlite3/3.49.0+100/f46f322288074a479268a2e040d212a6/lib
    /home/eloide-novela/.xmake/packages/g/glog/v0.7.1/99fdb614db3440a2b3aee6077200beea/lib
    /home/eloide-novela/.xmake/packages/g/gflags/v2.2.2/0f545414272c459b907061d5e923ed20/lib
)
target_link_options(demo-websocketsd PRIVATE
    -m64
)
target_sources(demo-websocketsd PRIVATE
    src/main.cpp
    src/util/hash.cpp
    src/util/util.cpp
    src/configurations/boot.cpp
    src/configurations/configuration.cpp
    src/controllers/api_v1_user.cpp
    src/controllers/api_v1_logout.cpp
    src/controllers/api_v1_login.cpp
    src/controllers/api_v1_message.cpp
    src/filters/api_token_filter.cpp
    src/filters/api_session_filter.cpp
    lib/SHA256.cpp
)

