#include <iostream>

#include "Parser.h"
#include "WorkflowExecutor.h"

int main() {
    std::string workflow_filename;

    Parser parser(workflow_filename);
    auto parse_result = parser.GetParseResult();
    if (!parse_result)
    {
        std::cerr << "Unable to parse workflow: " << parser.GetErrorMessage();
        return 1;
    }

    WorkflowExecutor executor(std::move(parse_result));
    if (!executor.Run())
    {
        std::cerr << "Unable to execute workflow: " << executor.GetErrorMessage();
        return 1;
    }

    return 0;
}
