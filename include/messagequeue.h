#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <queue>
#include <condition_variable>
#include <mutex>
#include <memory>
#include "service.h"

class MessageQueue
{
public:
    void pushService(std::shared_ptr<Service> srv)
    {
        std::lock_guard<std::mutex> lock(mtx_);
        if (!isClosed_)
        {
            queue_.push(srv);
            cv_.notify_one();
        }
    }

    bool popService(std::shared_ptr<Service> &srv)
    {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this]
                 { return !queue_.empty() || isClosed_; });

        if (isClosed_ && queue_.empty())
            return false;

        if (!queue_.empty())
        {
            srv = queue_.front();
            queue_.pop();
            return true;
        }
        return false;
    }

    void close(bool drain = true)
    {
        std::lock_guard<std::mutex> lock(mtx_);
        isClosed_ = true;
        if (!drain)
        {
            while (!queue_.empty())
                queue_.pop();
        }
        cv_.notify_all();
    }

    bool empty()
    {
        std::lock_guard<std::mutex> lock(mtx_);
        return queue_.empty();
    }

private:
    std::queue<std::shared_ptr<Service>> queue_;
    std::mutex mtx_;
    std::condition_variable cv_;
    bool isClosed_ = false;
};

#endif