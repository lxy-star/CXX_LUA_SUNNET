#ifndef WORKERTHREADS_H
#define WORKERTHREADS_H

#include <vector>
#include "worker.h"

class WorkerThreads
{
private:
    MessageQueue msgQueue_;
    std::vector<Worker> workers_;
    int prossNums_;

public:
    WorkerThreads(int prossNums, int threadNums) : msgQueue_(), prossNums_(prossNums)
    {
        for (int i = 0; i < threadNums; ++i)
        {
            workers_.emplace_back(msgQueue_, prossNums_);
        }
    }
    ~WorkerThreads()
    {
        msgQueue_.close(true); // 允许排空队列
        while (!msgQueue_.empty())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        workers_.clear(); // 自动 join 所有线程
    }
    void pushService(std::shared_ptr<Service> srv)
    {
        msgQueue_.pushService(srv);
    }
};

#endif