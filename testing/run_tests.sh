#!/bin/bash

# Build Python wrapper
cd ../PythonWrapper
sh build.sh

# Run tests
cd ..
python3 -m unittest -v
