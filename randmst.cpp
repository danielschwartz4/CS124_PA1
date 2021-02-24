#include "functions.h"
#include <ctime>

// Included comments below so you can see our process of timing parts of the program
int main(int argc, char const *argv[])
{  
	auto t1 = std::chrono::high_resolution_clock::now();
	int flag =  atoi(argv[1]);
	int node_cnt = atoi(argv[2]);
	int n_trail = atoi(argv[3]);
	int dim = atoi(argv[4]);

	double total = 0;
	for (int i = 0; i<n_trail; i++){
    // std::cout << "iteration start" << std::endl;
		// auto i1 = std::chrono::high_resolution_clock::now();

    // Seed with current time in microseconds
		int rand_seed = (unsigned) time(0);
		// std::cout << "FULL graph start" << std::endl;
		// auto g1 = std::chrono::high_resolution_clock::now();

		graph g = create_random_graph(dim, node_cnt, rand_seed);
		// auto g2 = std::chrono::high_resolution_clock::now();
		// auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>( g2 - g1 ).count();
		// std::cout << "FULL graph duration: " << duration1 << std::endl;

    // std::cout << "Kruskal start" << std::endl;
		auto k1 = std::chrono::high_resolution_clock::now();
		double weight = kruskal_weight(g, node_cnt);
		// auto k2 = std::chrono::high_resolution_clock::now();
		// auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>( k2 - k1 ).count();
		// std::cout << "Kruskal duration: " << duration2 << std::endl;

		total += weight;
		// auto i2 = std::chrono::high_resolution_clock::now();
		// auto durationi = std::chrono::duration_cast<std::chrono::microseconds>( i2 - i1 ).count();
		// std::cout << "Iteration i duration: " << durationi << std::endl;
	}

  printf("Average weight: %f\t%d\t%d\t%d\n", total/n_trail, node_cnt, n_trail, dim);

	// auto t2 = std::chrono::high_resolution_clock::now();
	// auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
	// std::cout << "total duration: " << duration2 << std::endl;

 	
	return 0;
}