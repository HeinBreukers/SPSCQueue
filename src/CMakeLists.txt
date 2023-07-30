cmake_minimum_required(VERSION 3.2)
project(spscqueue_src)

# --- Fetch KafkaWrapper --------------------------------------------------------------
include(FetchContent)


FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.0.0
        )

FetchContent_MakeAvailable(fmt)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SPSCQueue)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/examples)

set(SOURCE
examples/main.cpp

)

set(HEADER
SPSCQueue/SPSCQueue.hpp
)

add_executable(example
      ${HEADER}
      ${SOURCE}
)
target_link_libraries(example fmt pthread)
target_compile_options(example PRIVATE -Werror -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion -Wformat=2)
# if GCC
#target_compile_options(SQLiteCPP PRIVATE -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast)
target_include_directories(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/SPSCQueue)
