cmake_minimum_required(VERSION 3.25)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  include(FetchContent)
  FetchContent_Declare(
    vcpkg
    GIT_REPOSITORY https://github.com/microsoft/vcpkg.git
    GIT_TAG master
    GIT_SHALLOW TRUE
  )
  FetchContent_MakeAvailable(vcpkg)
  set(CMAKE_TOOLCHAIN_FILE
    ${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake
    CACHE FILEPATH "Vcpkg toolchain file"
  )
  set(VCPKG_ROOT_DIR ${vcpkg_SOURCE_DIR} CACHE PATH "Vcpkg Root Directory")
endif()

if(DEFINED VCPKG_ROOT_DIR)
  add_custom_target(UpdateVcpkgBaseline
    ${VCPKG_ROOT_DIR}/vcpkg x-update-baseline
  )
endif()

project(week-three-lab)

enable_testing()

find_package(nyu-cmake CONFIG REQUIRED)

add_executable(exercise1 dv/exercise1.cpp)
target_compile_features(exercise1 PRIVATE cxx_std_20)
nyu_add_sv(exercise1 rtl/Exercise1.sv)
nyu_target_verilate(exercise1 TOP_MODULES Exercise1)
add_test(NAME exercise1 COMMAND exercise1)

add_executable(exercise2 dv/exercise2.cpp)
target_compile_features(exercise2 PRIVATE cxx_std_20)
nyu_add_sv(exercise2 rtl/Exercise2.sv)
nyu_target_verilate(exercise2 TOP_MODULES Exercise2)
add_test(NAME exercise2 COMMAND exercise2)

add_executable(exercise3 dv/exercise3.cpp)
target_compile_features(exercise3 PRIVATE cxx_std_20)
nyu_add_sv(exercise3
  rtl/Exercise3.sv rtl/Mysteries/Mystery1.sv rtl/Mysteries/Mystery2.sv
)
nyu_target_verilate(exercise3 TOP_MODULES Exercise3)
add_test(NAME exercise3 COMMAND exercise3)

add_executable(exercise4 dv/exercise4.cpp)
target_compile_features(exercise4 PRIVATE cxx_std_20)
nyu_add_sv(exercise4 rtl/Exercise4.sv)
nyu_target_verilate(exercise4 TOP_MODULES Exercise4)
add_test(NAME exercise4 COMMAND exercise4)
