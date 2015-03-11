#include "mutex.h"

namespace chidouhu {

MutexLock::MutexLock() {
    int ret = pthread_mutex_init(&m_mutex, NULL);
    if (ret < 0) {
        DSTREAM_FATAL("pthread_mutex_init(%p) failed(%s)", &m_mutex, strerror(ret));
    }
}

MutexLock::~MutexLock() {
    int ret = pthread_mutex_destroy(&m_mutex);
    if (ret < 0) {
        DSTREAM_FATAL("pthread_mutex_destroy(%p) failed(%s)", &m_mutex, strerror(ret));
    }
}

void MutexLock::lock() {
    int ret = pthread_mutex_lock(&m_mutex);
    if (ret < 0) {
        DSTREAM_FATAL("pthread_mutex_lock(%p) failed(%s)", &m_mutex, strerror(ret));
    }
}

int MutexLock::trylock() {
    int ret = pthread_mutex_trylock(&m_mutex);
    if (ret < 0) {
        DSTREAM_FATAL("pthread_mutex_trylock(%p) failed(%s)", &m_mutex, strerror(ret));
        return ret;
    }
    return ret;
}

void MutexLock::unlock() {
    int ret = pthread_mutex_unlock(&m_mutex);
    if (ret < 0) {
        DSTREAM_FATAL("pthread_mutex_unlock(%p) failed(%s)", &m_mutex, strerror(ret));
    }
}

pthread_mutex_t* MutexLock::getPthreadMutex() {
    return &m_mutex;
}

} // chidouhu
