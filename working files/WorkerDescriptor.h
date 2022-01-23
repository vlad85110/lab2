#pragma once

#include <string>
#include <list>

enum class WorkerTag
{
    Input,
    Output,
    Processor
};

struct WorkerDescriptor
{
    std::string worker_name;
    WorkerTag worker_tag;
    std::list<std::string> args;
};
