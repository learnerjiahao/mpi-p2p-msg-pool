#!/bin/bash
# download google/googletest
mkdir -p vendor/src && cd vendor/src
git clone https://github.com/google/googletest
#mkdir -p ../cache/googletest && cd ../cache/googletest
#cmake ../../src/googletest/ -DCMAKE_INSTALL_PREFIX=../../
#make && make install
