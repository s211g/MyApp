#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

int main() {
    //uint64_t size = 500 * 1024 * 1024;
    uint64_t size = 1 * 1024 * 1024;
    int i=0;

    uint64_t total = 0;
    while (true) {
        try {
            auto start = std::chrono::system_clock::now();
            char* c    = new char[size];
            if (c) {
                memset(c, 0, size);
                auto end = std::chrono::system_clock::now();
                total += size;
                std::chrono::duration<double> elapsed_seconds = end-start;
                std::cout << ">" << total / (1024 * 1024) << "mb, "<< elapsed_seconds.count() << " sec" << std::endl;
            }
            else {
                std::cout << "err new " << std::endl;
                break;
            }
        }
        catch (std::exception& ex) {
            std::cout << "ex: " << ex.what() << std::endl;
            break;
        }
        catch (...) {
            std::cout << "unknown ex" << std::endl;
            break;
        }

        std::chrono::duration dur(std::chrono::seconds(1));
        std::this_thread::sleep_for(dur);

        if(++i == 10)
        {
            volatile int* v = nullptr;
            *v = 100;
        }          
    }

    std::cout << "exit ... wait 10 sec " << std::endl;
    std::chrono::duration dur(std::chrono::seconds(10));
    std::this_thread::sleep_for(dur);
    std::cout << "exit " << std::endl;

    return 0;
}
