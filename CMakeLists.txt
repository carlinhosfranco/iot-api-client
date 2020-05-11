cmake_minimum_required(VERSION 3.1)

set(project_name example-api-client) ## rename your project here
set(iot_project iot-client)

project(${project_name})
project(${iot_project})

set(CMAKE_CXX_STANDARD 11)

add_library(${project_name}-lib
        src/AsyncExample.hpp
        src/DemoApiClient.hpp
        src/DemoApiModels.hpp
        src/SimpleExample.hpp
        src/AsyncExample.cpp)

add_library(${iot_project}-lib
        src/IoT/IoTClient.hpp
        src/IoT/HttpRequest.hpp
        src/IoT/RequestModelDto.hpp
        src/IoT/IoTClient.cpp
        )

## link libs

find_package(oatpp      1.0.0 REQUIRED)
find_package(oatpp-curl 1.0.0 REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-curl
)
target_link_libraries(${iot_project}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-curl
)

target_include_directories(${project_name}-lib PUBLIC src)
target_include_directories(${iot_project}-lib PUBLIC src)

## add executables

add_executable(${project_name}-exe
        src/App.cpp
)
add_executable(${iot_project}-exe
        src/IoT/ClientRun.cpp
)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

target_link_libraries(${iot_project}-exe ${iot_project}-lib)
add_dependencies(${iot_project}-exe ${iot_project}-lib)

#add_executable(${project_name}-test
#        test/tests.cpp
#)
#target_link_libraries(${project_name}-test ${project_name}-lib)
#add_dependencies(${project_name}-test ${project_name}-lib)

#enable_testing()
#add_test(project-tests ${project_name}-test)
