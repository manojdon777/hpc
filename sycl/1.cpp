#include <CL/sycl.hpp>
#include <iostream>
using namespace std;
 constexpr int N = 16;
 int main() {
    if (!sycl::queue::get_device().has(sycl::aspect::shared_memory)) {
        std::cerr << "Device does not support shared memory!\n";
        return 1;
    }
     sycl::queue q;
    std::unique_ptr<int[]> data(new int[N], [](int* ptr) { free(ptr, queue{}); });
     for (int i = 0; i < N; i++) {
        data[i] = 10;
    }
     auto e1 = q.submit([&](sycl::handler& h) {
        h.parallel_for(N, [=](sycl::id<1> i) {
            data[i] += 2;
        });
    });
     auto e2 = q.submit([&](sycl::handler& h) {
        h.depends_on(e1);
        h.parallel_for(N, [=](sycl::id<1> i) {
            data[i] += 3;
        });
    });
     q.submit([&](sycl::handler& h) {
        h.depends_on(e2);
        h.parallel_for(N, [=](sycl::id<1> i) {
            data[i] += 5;
        });
    }).wait();
     for (int i = 0; i < N; i++) {
        std::cout << data[i] << " ";
    }
     std::cout << std::endl;
     return 0;
}
