# Check for python interpreter
find_package(PythonInterp)
find_package(Python)

set(PYSCRIPTS_DIR ${CMAKE_SOURCE_DIR}/tools/scripts)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/out/include)

macro(amalgamate_headers base_header output_header)
    if (PYTHON_FOUND)
        execute_process(COMMAND ${Python3_EXECUTABLE} ${PYSCRIPTS_DIR}/acme.py ${CMAKE_CURRENT_SOURCE_DIR}/${base_header} -o ${OUTPUT_DIR}/${output_header})
    endif()
endmacro()