#include <thread>
#include <mutex>
#include <condition_variable>
namespace CSC413 {
    class barrier {
        int max_threads;
        int count;
        std::mutex m;
        std::condition_variable condVar;
        bool phase = true;
    public:
        barrier(int nt) :max_threads(nt), count(nt) {}
        void arrive_and_wait() {
            std::unique_lock<std::mutex> lck(m);
            auto p = phase;
            --count;
            if (count == 0)notify_all();
            else condVar.wait(lck, [&]() {return p != phase; });

        }
        void notify_all() {
            phase = !phase;
            count = max_threads;
            condVar.notify_all();
        }
        void arrive_and_drop() {
            std::unique_lock<std::mutex> lck(m);
            --max_threads;
            --count;
            if (count == 0)notify_all();
        }
    };
}
