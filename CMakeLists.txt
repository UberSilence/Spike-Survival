cmake_minimum_required(VERSION 3.0) 

project(SpikeSurvival)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} 
    PRIVATE
    ${PROJECT_SORUCES_DIR}/include)