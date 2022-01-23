#include "WorkerFactory.h"

void WorkerFactory::RegisterWorkerCreator(std::string worker_name, WorkerCreator worker_creator) {
    workers_factory_map[worker_name] = std::move(worker_creator);
}

IWorkerPtr WorkerFactory::CreateWorker(std::string worker_name) {
    auto worker_creator_it = workers_factory_map.find(worker_name);
    return worker_creator_it != workers_factory_map.end()
        ? worker_creator_it->second()
        : nullptr;
}
