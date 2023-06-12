#!/bin/bash
REPO_DIR=$(realpath $(dirname ${BASH_SOURCE[0]}))

BUILD_DIR=${REPO_DIR}/build

cmake -S $REPO_DIR -B $BUILD_DIR -G Ninja -DQt6_DIR=${HOME}/workspace/Qt/6.5.1/gcc_64/lib/cmake/Qt6 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=/usr/bin/g++
cmake --build $BUILD_DIR -j $(nproc)
