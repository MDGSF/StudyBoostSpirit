#!/usr/bin/env bash

export VENDOR_LINUX_HOME="/home/huangjian/git/huangjian/vendor_linux"
export MYPLATFORM="ubuntu2004_gcc9.4.0"

mkdir -p build
cd build

cmake -DCMAKE_SYSTEM_NAME=Linux \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_CXX_COMPILER=g++ \
  -DCMAKE_C_COMPILER=gcc \
  -DVENDOR_LINUX_HOME=$VENDOR_LINUX_HOME \
  ..

# make
make -j 4
# make VERBOSE=1
