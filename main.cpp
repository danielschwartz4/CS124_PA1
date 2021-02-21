#include "functions.h"


int main(int argc, char const *argv[])
{
	auto t1 = std::chrono::high_resolution_clock::now();
	int flag =  atoi(argv[1]);
	int node_cnt = atoi(argv[2]);
	int n_trail = atoi(argv[3]);
	int dim = atoi(argv[4]);

	double total = 0;
	for (int i = 0; i<n_trail; i++){
		int rand_seed = rand();
		std::cout << "create graph start" << std::endl;
		auto g1 = std::chrono::high_resolution_clock::now();

		graph g = create_random_graph(dim, node_cnt, rand_seed);

		std::cout << "create graph stop" << std::endl;
		auto g2 = std::chrono::high_resolution_clock::now();
		auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>( g2 - g1 ).count();
    std::cout << duration1 << std::endl;


		std::cout << "sort start" << std::endl;
		auto s1 = std::chrono::high_resolution_clock::now();

		double weight = kruskal_weight(g, node_cnt);

		std::cout << "sort end" << std::endl;
		auto s2 = std::chrono::high_resolution_clock::now();
		auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>( s2 - s1 ).count();
		std::cout << duration2 << std::endl;
		total += weight;
	}

	printf("Average weight: %f\tnumpoints: %d\tnumtrials: %d\tdimensions: %d\n",
	total/n_trail, node_cnt, n_trail, dim);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
	std::cout << "total duration: " << duration2 << std::endl;

 	
	return 0;
}