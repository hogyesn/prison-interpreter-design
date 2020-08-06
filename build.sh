#!/bin/bash
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
cd ..
unlink prison
ln -s build/prison prison
