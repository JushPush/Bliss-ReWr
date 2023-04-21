add_executable("DEMO" "main.cpp")
#target_link_libraries("DEMO" Bliss::Bliss)

target_include_directories("DEMO" PRIVATE ${CMAKE_SOURCE_DIR}/external/include)
target_include_directories("DEMO" PRIVATE ${CMAKE_SOURCE_DIR}/out/include)
target_link_directories("DEMO" PRIVATE ${CMAKE_SOURCE_DIR}/external/lib)
target_link_directories("DEMO" PRIVATE ${CMAKE_SOURCE_DIR}/out/lib)

target_link_libraries("DEMO" bliss_core bliss_graphics)