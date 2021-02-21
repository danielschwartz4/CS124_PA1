#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> 
#include <time.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <cassert>

typedef std::pair<int, int> edge;
typedef std::unordered_map<double, std::vector<edge> > dist_graph;

struct graph
{
	dist_graph d_graph;
	std::vector<double> edges;
	~graph();
};

graph::~graph(){

}


// HINT function
double cutoff_func(int node_cnt, int dim){
	return (double) 1.44740965e-05*node_cnt + 1.53826169e-01*dim+0.6;
}

// euclidean_distance
double euclidean_distance(double* v1, double * v2, int dim){
	double total_square=0;
	for (int i=0;i<dim; i++){
		total_square += pow(v1[i] - v2[i], 2); 
	}
	return sqrt(total_square);
}


// create vertices coordinates
double** create_uniform_vertices(int dim, int node_cnt, int rand_seed){
	double** vertices;
	vertices = (double**) malloc(node_cnt * sizeof(uintptr_t));
	srand(rand_seed);
	for (int i=0; i< node_cnt; i++){
		vertices[i] = (double*) malloc(dim * sizeof(double));
		for (int j=0; j<dim; j++){
			vertices[i][j] = (double) rand()/RAND_MAX;
		}
	}
	return vertices;
}


// create graph
graph create_random_graph(int dim, int node_cnt, int rand_seed){
	// make usre the input values are positive
	assert(dim>0); 
	assert(node_cnt>0);
	// initiate graph
	graph res;

	double cutoff_wt = cutoff_func(node_cnt, dim);
	if (dim==1){  //one dimension case
		srand(rand_seed);
		for (int i = 0; i<node_cnt-1; i++){
			for(int j=i+1; j<node_cnt; j++){
				double weight = (double) rand()/RAND_MAX;
				if (res.d_graph.find(weight) == res.d_graph.end()){
					res.d_graph.insert(std::pair<double, std::vector<edge> > (weight, std::vector<edge>()));
				}
				// printf("from frunction: weight: %f,i:%d, j:%d\n", weight, i,j);
				res.d_graph[weight].push_back(edge (i,j));

				if(weight<=cutoff_wt){
					res.edges.push_back(weight);
				}
			}
		}
	}
	else{
		// multi-dimension case. Generate vertices coordinates, then compute distances
		double** vertices = create_uniform_vertices(dim, node_cnt, rand_seed);

		for (int i = 0; i<node_cnt-1; i++){
			for(int j=i+1; j<node_cnt; j++){
				double weight = euclidean_distance(vertices[i], vertices[j], dim);
				if (res.d_graph.find(weight) == res.d_graph.end()){
					res.d_graph.insert(std::pair<double, std::vector<edge> > (weight, std::vector<edge>()));
				}
				// printf("from frunction: weight: %f,i:%d, j:%d\n", weight, i,j);
				res.d_graph[weight].push_back(edge (i,j));

				if(weight<=cutoff_wt){
					res.edges.push_back(weight);
				}
			}
		}
		free (vertices);
	}
	return res;
}

int Find(int* parent, int x){
	if (x != parent[x]){
		parent[x] = Find(parent, parent[x]);
	}
	return parent[x];
}

void Union(int* rank, int* parent, int root_x, int root_y){
	if (rank[root_x] > rank[root_y]){
		parent[root_y] = root_x;
	}
	else if (rank[root_x] < rank[root_y]){
		parent[root_x] = root_y;
	}
	else{
		parent[root_x] = root_y;
		rank[root_y]++;
	}
}

// construct MST and compute the total edge cost
double kruskal_weight(graph g, int node_cnt){

	// initiate parent array and rank array
	int parent[node_cnt];
	int rank[node_cnt];
	for (int i = 0; i<node_cnt; i++){
		parent[i] = i;
		rank[i] = 0;
	}

	// MST edge count = |V| -1
	int edge_cnt = node_cnt-1;

	double mst_weight = 0;
	// countruct MST
	
	std::sort(g.edges.begin(), g.edges.end());
	int edge_index = 0;
	while (edge_cnt>0){
		double cur_edge_weight = g.edges.at(edge_index);
		std::vector<edge> vertices = g.d_graph.find(cur_edge_weight)->second;
		std::vector<edge>::iterator it;

		for(it = vertices.begin(); it != vertices.end(); it++){
			int x = it->first;
			int y = it->second;
			int root_x = Find(parent, x);
			int root_y = Find(parent,y);
			if (root_x!=root_y){
				Union(rank, parent, root_x, root_y);
				mst_weight += cur_edge_weight;
				edge_cnt--;
				}
		}
		edge_index++;
		
	}
	return mst_weight;
}

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
