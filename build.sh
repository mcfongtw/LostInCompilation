#!/bin/bash - 
#===============================================================================
#
#          FILE: build.sh
# 
#         USAGE: ./build.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2016年10月13日 20時14分28秒
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

rm -rf ./build/
mkdir -p ./build/
cd ./build
cmake ../
make googletestsuite
make


