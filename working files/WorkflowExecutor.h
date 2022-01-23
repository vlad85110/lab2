#pragma ocne

#include "Fwd.h"

#include <string>
#include <string_view>

class WorkflowExecutor {
public:
    explicit WorkflowExecutor(WorkflowDescriptorPtr workflow_descriptor);

    bool Run();
    std::string_view GetErrorMessage();

private:
    WorkflowDescriptorPtr workflow_descriptor_;
    WorkerFactoryPtr factory_;
    std::string error_message_;
};
