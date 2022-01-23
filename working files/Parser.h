#pragma once

#include "Fwd.h"

#include <string>
#include <string_view>

class Parser {
public:
    explicit Parser(std::string & file_name);
    WorkflowDescriptorPtr GetParseResult();
    std::string_view GetErrorMessage();
private:
    WorkflowDescriptorPtr parse_result_;
    std::string error_message_;
};


