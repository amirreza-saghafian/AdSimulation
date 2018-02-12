cmake_minimum_required(VERSION 3.9)
project(AdSimulation)

include_directories(/Users/saghafian/Documents/CLionProjects/AdSimulation)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdSimulation
        src/action/action_strategy.h
        src/action/text_action_strategy.cc
        src/action/text_action_strategy.h
        src/analysis/user_analysis.h
        src/common/ad.h
        src/common/ad_with_action.cc
        src/common/ad_with_action.h
        src/common/item.cc
        src/common/item.h
        src/common/user.cc
        src/common/user.h
        src/container/lru_cache.h
        src/tool/load_data.cc
        src/tool/load_data.h
        test/test_items.cc
        test/test_items.h
        test/test_string_int.cc
        test/test_string_int.h
        CMakeLists.txt
        main.cpp src/analysis/user_analysis.cc)
