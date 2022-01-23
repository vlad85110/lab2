#include "WorkerFactoryCreator.h"

#include "WorkerFactory.h"
#include "Reader.h"

WorkerFactoryPtr CreateWorkerFactory()
{
    WorkerFactory factory;

    factory.RegisterWorkerCreator("reader", CreateWorker<Reader>);
//    factory.RegisterWorkerCreator("writer", CreateWorker<Writer>);

    return std::make_shared<WorkerFactory>(std::move(factory));
}