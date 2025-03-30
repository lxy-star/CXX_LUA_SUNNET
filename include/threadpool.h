// #ifndef THREADPOOL_H
// #define THREADPOOL_H

// #include <thread>
// #include <queue>
// #include <mutex>
// #include <atomic>
// #include <memory>
// #include <condition_variable>
// #include "service.h"

// class Threadpool
// {
// private:
//     /* data */
//     std::queue<std::shared_ptr<Service>> globalQueue;
//     std::vector<std::thread> threads;
//     std::mutex mtx;
//     std::condition_variable cv;
//     std::atomic<bool> isClosed;
//     int prossNums_;
//     void CheckAndPutGlobal(std::shared_ptr<Service> srv);
// public:
//     Threadpool(int MaxSize = 4,int prossNums = 1);
//     ~Threadpool();
//     void pushService(std::shared_ptr<Service> srv);
// };

// #endif