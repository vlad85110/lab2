cmake_minimum_required(VERSION 3.21)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 "working files/main.cpp" "working files/Parser.cpp" "working files/Parser.h" "working files/WorkflowDescriptor.h" "working files/ParseResult.h" "working files/Fwd.h" "working files/WorkerDescriptor.h" "working files/WorkflowExecutor.cpp" "working files/WorkflowExecutor.h" "working files/WorkerFactory.cpp" "working files/WorkerFactory.h" "working files/IWorker.h" "working files/Reader.cpp" "working files/Reader.h" "working files/WorkerFactoryCreator.cpp" "working files/WorkerFactoryCreator.h")
