#pragma once

#include <list>
#include <string>
#include <optional>

class IWorker {
public:
    virtual ~IWorker() = default;

    virtual bool Run(std::list<std::string> args, std::optional<std::string> & return_value) = 0;
};
