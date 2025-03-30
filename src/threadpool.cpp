// #include "../include/threadpool.h"

// Threadpool::Threadpool(int maxSize, int prossNums) : prossNums_(prossNums)
// {
//     for (int i = 0; i < maxSize; ++i)
//     {
//         threads.emplace_back([this]()
//                              {
//             while(true){
//                 std::shared_ptr<Service> srv;
//                 std::unique_lock<std::mutex> locker(this->mtx,std::defer_lock);
//                 {
//                     locker.lock();
//                     cv.wait(locker,[this](){
//                         return !this->globalQueue.empty()||this->isClosed;
//                     });
//                     if(isClosed&&globalQueue.empty()){
//                         break;
//                     }
//                     srv = globalQueue.front();
//                     globalQueue.pop();
//                     locker.unlock();
//                 }
//                 if(srv){
//                     srv->ProcessMsgs(prossNums_);
//                     CheckAndPutGlobal(srv);
//                 }
//             } });
//     }
// }

// Threadpool::~Threadpool()
// {
//     isClosed = true;
//     cv.notify_all();
//     for (auto &thread : threads)
//     {
//         if (thread.joinable())
//         {
//             thread.join();
//         }
//     }
// }

// void Threadpool::pushService(std::shared_ptr<Service> srv)
// {
//     std::lock_guard<std::mutex> locker(mtx);
//     globalQueue.push(srv);
//     cv.notify_one(); // 唤醒一个线程来处理任务
// }

// void Threadpool::CheckAndPutGlobal(std::shared_ptr<Service> srv)
// {
//     if (srv->isExiting)
//     {
//         return;
//     }

//     pthread_spin_lock(&srv->queueLock);
//     {
//         if (!srv->msgQueue.empty())
//         {
//             pushService(srv);
//         }
//         else
//         {
//             srv->SetInGlobal(false);
//         }
//     }
//     pthread_spin_unlock(&srv->queueLock);
// }