#pragma once

#include "Fwd.h"
#include <string>

struct ParseResult {
    WorkflowDescriptorPtr workflow_descriptor;
    std::string error_message;
};