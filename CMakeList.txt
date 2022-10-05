cmake_minimum_required(VERSION 3.15)
project(ConcordanceOfDoc VERSION 1.2)

add_executable(${PROJECT_NAME} src/main.cpp src/wordList.cpp)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_BINARY_DIR} 
)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC
)
