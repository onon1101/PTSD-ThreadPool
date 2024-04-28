//
// Created by adven on 2024/4/28.
//

#ifndef PRACTICALTOOLSFORSIMPLEDESIGN_ENGINE_H
#define PRACTICALTOOLSFORSIMPLEDESIGN_ENGINE_H

#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <functional>

class ThreadPool {
public:
    void Start();
    void QueueJob(const std::function<void()> &job);
    void Stop();
    bool busy();

private:
    void ThreadLoop();

    bool should_terminate = false;           // Tells threads to stop looking for jobs
    std::mutex queue_mutex;                  // Prevents data races to the job queue
    std::condition_variable mutex_condition; // Allows threads to wait on new jobs or termination
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> jobs;
};

#endif // PRACTICALTOOLSFORSIMPLEDESIGN_ENGINE_H
