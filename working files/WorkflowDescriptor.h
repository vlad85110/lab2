#pragma once

#include "WorkerDescriptor.h"

#include <unordered_map>
#include <vector>

using WorkerId = int;

struct WorkflowDescriptor {
    std::unordered_map<WorkerId, WorkerDescriptor> workers;
    std::vector<WorkerId> workflow;
};

