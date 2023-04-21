#!/bin/bash

function usage()
{
    echo "Build command arguments"
    echo ""
    echo "./builtTemplate"
    echo "-h --help     | Gives list of arguments"
    echo "-r --run      | Only runs the demo program"
    echo "-b --build    | Only builds"
    echo ""
}

while [ "$1" != "" ]; do
    PARAM=`echo $1 | awk -F= '{print $1}'`
    VALUE=`echo $1 | awk -F= '{print $2}'`
    case $PARAM in
        -h | --help)
            usage
            exit
            ;;
        -r | --run)
            ./out/bin/DEMO
            exit
            ;;
        -b | --build)
            ./tools/scripts/buildAndTest.py
            exit
            ;;
        *)
            echo "ERROR: unknown parameter \"$PARAM\""
            usage
            exit 1
            ;;
    esac
    shift
done

if [ "$1" == "" ]; then
    ./tools/scripts/buildAndTest.py
fi
