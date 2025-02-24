#!/bin/bash

# Create include directory if it doesn't exist
mkdir -p include

# Download httplib.h
curl -o include/httplib.h https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h 