#include "WorkflowExecutor.h"

#include "WorkflowDescriptor.h"
#include "WorkerFactory.h"
#include "WorkerFactoryCreator.h"

WorkflowExecutor::WorkflowExecutor(
    WorkflowDescriptorPtr workflow_descriptor)
    : workflow_descriptor_{std::move(workflow_descriptor)}
    , factory_{CreateWorkerFactory()}
{}

bool WorkflowExecutor::Run() {
    if (workflow_descriptor_->workflow.empty()) return true;

    auto worker_it = workflow_descriptor_->workflow.begin();


    return true;
}

std::string_view WorkflowExecutor::GetErrorMessage() {
    return error_message_;
}
