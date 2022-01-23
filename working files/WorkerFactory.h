#pragma once

#include "Fwd.h"
#include "WorkerDescriptor.h"

#include <map>
#include <functional>

template <typename WorkerType>
IWorkerPtr CreateWorker() {
    return std::make_shared<WorkerType>();
}

using WorkerCreator = std::function<IWorkerPtr ()>;

class WorkerFactory {
public:
    void RegisterWorkerCreator(std::string worker_name, WorkerCreator worker_creator);
    IWorkerPtr CreateWorker(std::string worker_name);

private:
    std::map<std::string, WorkerCreator> workers_factory_map;
};
