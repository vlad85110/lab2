#pragma once

#include "IWorker.h"

class Reader : public IWorker {
public:
    bool Run(std::list<std::string> args, std::optional<std::string> & return_value) override;
};
