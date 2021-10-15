#!/bin/bash
mkdir build
cd build
cmake -G "Unix Makefiles" ..
cmake --build . --config Release --target all
./Raytracer
