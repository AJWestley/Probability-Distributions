#!/bin/bash

# Build Python wrapper
cd ../PythonWrapper
sh build.sh
cd ../testing

# Run tests
python3 -m unittest -v
