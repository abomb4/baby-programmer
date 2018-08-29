#!/bin/bash

BASEDIR=$(dirname "$0")

PWD=`pwd`

cd $BASEDIR/build
cmake ..

if [ $? -eq 0 ]; then
    echo -e "\033[92mBuild success.\033[0m"
else
    echo -e "\033[91mBuild failed.\033[0m"
fi

cd $PWD



