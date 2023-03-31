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

    while [ "" != "" ]; do
        PARAM=
        VALUE=
        case  in
            -h | --help)
                usage
                exit
                ;;
            -r | --run)
                ./build/samples/demo/DEMO
                ;;
            -b | --build)
                ./tools/scripts/buildAndTest.py
                ;;
            *)
                echo "ERROR: unknown parameter \"\""
                usage
                exit 1
                ;;
        esac
        shift
    done

    if [ "" == "" ]
    then
        ./tools/scripts/buildAndTest.py
    fi
