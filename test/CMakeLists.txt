cmake_minimum_required(VERSION 3.14)
project(spscqueue_test)

# GoogleTest requires at least C++14  

include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)




