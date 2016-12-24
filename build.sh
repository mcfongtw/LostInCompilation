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
#        AUTHOR: Michael Fong (mcfongtw),
#  ORGANIZATION: 
#       CREATED: 2016/10/13/ 20:14:28
#      REVISION: 0.1
#===============================================================================

set -o nounset                              # Treat unset variables as an error

rm -rf ./build/
mkdir -p ./build/
cd ./build

#TODO: Improve w/ case insensitive equality check
if [ "$1" = "Release" ];
then
    cmake -DCMAKE_BUILD_TYPE=Release ../
else
    cmake ../
fi
make googletestsuite
make


