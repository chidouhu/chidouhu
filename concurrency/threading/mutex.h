#ifndef __CHIDOUHU_CONCURRNECY_MUTEX_H__
#define __CHIDOUHU_CONCURRNECY_MUTEX_H__

#include <pthread.h>

namespace chidouhu {

class MutexLock {
public:
    MutexLock();
    ~MutexLock();
    void lock();
    int trylock();
    void unlock();
    pthread_mutex_t* getPthreadMutex();

private:
    pthread_mutex_t mutex_;
};

class MutexLockGuard {
public:
    explicit MutexLockGuard(MutexLock& mutex)
        : mutex_(mutex) {
        mutex_.lock();
    }

    ~MutexLockGuard() {
        mutex_.unlock();
    }

private:
    MutexLock& mutex_;
};

#define MutexLockGuard(x) error "Missing guard object name"

}

#endif
