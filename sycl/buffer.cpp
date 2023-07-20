#include <CL/sycl.hpp>
constexpr int N=16;
using namespace sycl;
using namespace std;
int main() {
	vector<int> data(N);
	{
		buffer A(data);
		queue q;
		q.submit([&](handler& h){
			accessor out(A, h, write_only);
			h.parallel_for(N, [=](auto i){
				out[i] = i;
			});
		});
	}
	for(int i=0; i<N; i++)
		cout << data[i] << " ";
	cout << std::endl;
	return 0;
}