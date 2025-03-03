#!/bin/bash

project_path="/home/landotech/GitHub/DataStructures-Algorithms/algorithms"

cd "$project_path"
cd build
cmake build ..
make
cd bin
./algorithms
