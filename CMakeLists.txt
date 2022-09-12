cmake_minimum_required(VERSION 3.13.2)
project(se_termin_3)

set(CMAKE_CXX_STANDARD 14)


if ("${CMAKE_C_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang"
        OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
        message("Building with llvm Code Coverage tools")
        set(CMAKE_CXX_FLAGS "-fprofile-instr-generate -fcoverage-mapping")
   elseif(CMAKE_COMPILER_IS_GNUCXX)
    message("Building with lcov Code Coverage Tools")
    set(CMAKE_CXX_FLAGS "--coverage -Dgtest_disable_pthreads=ON")
    set(LIBCOVERAGE gcov)
endif()

include(CMakeLists.GoogleTest.cmake)

add_executable(zugansage src/prod/main.cpp src/prod/Zugansage.cpp src/prod/Zugansage.h)


find_program(CPPCHECK_EXECUTABLE cppcheck)
if (NOT CPPCHECK_EXECUTABLE MATCHES "NOTFOUND")
find_program(CPPCHECK_HTMLREPORT cppcheck-htmlreport) 
get_target_property(ZUGANSAGE_SOURCES zugansage SOURCES) 
execute_process(COMMAND
${CPPCHECK_EXECUTABLE} --suppress=missingIncludeSystem --enable=all
--language=c++ --std=c++11 --quiet --xml-version=2 ${ZUGANSAGE_SOURCES} WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR} ERROR_FILE err.xml)
execute_process(COMMAND ${CPPCHECK_HTMLREPORT}
--file=${CMAKE_CURRENT_LIST_DIR}/err.xml --report-dir=cppcheckreport --source-dir=${CMAKE_CURRENT_LIST_DIR} )
endif ()
