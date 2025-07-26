#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void threadFunction(int threadId) {
    cout << "Thread " << threadId << " is running\n";
    
    for (int i = 0; i < 3; ++i) {
        cout << "Thread " << threadId << " working... (" << i+1 << "/3)\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    cout << "Thread " << threadId << " finished\n";
}

int main() {
    const int NUM_THREADS = 3;
    vector<thread> threads;

    cout << "Main thread: Creating " << NUM_THREADS << " worker threads\n";

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(threadFunction, i+1);
    }

    cout << "Main thread: Waiting for threads to finish...\n";

    for (auto& t : threads) {
        t.join();
    }

    cout << "Main thread: All threads completed!\n";

    return 0;
}