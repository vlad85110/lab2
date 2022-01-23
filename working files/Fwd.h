#pragma once

#include <memory>

struct WorkflowDescriptor;
using WorkflowDescriptorPtr = std::shared_ptr<WorkflowDescriptor>;

struct ParseResult;
using ParseResultPtr = std::shared_ptr<ParseResult>;

struct IWorker;
using IWorkerPtr = std::shared_ptr<IWorker>;

struct WorkerFactory;
using WorkerFactoryPtr = std::shared_ptr<WorkerFactory>;