#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> 
#include <time.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <chrono>
#include <math.h> 
#include <algorithm>
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
	return (double) -.02298154*log2(node_cnt) + 0.07643103*dim+0.2;
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
	double recent_weight;
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

				if(weight<=cutoff_wt && weight != recent_weight){
					res.edges.push_back(weight);
					double recent_weight = weight;
				}
			}
		}
	}
	else{
		// multi-dimension case. Generate vertices coordinates, then compute distances
		double** vertices = create_uniform_vertices(dim, node_cnt, rand_seed);
		printf("uniform vertices created");
		for (int i = 0; i<node_cnt-1; i++){
			for(int j=i+1; j<node_cnt; j++){
				double weight = euclidean_distance(vertices[i], vertices[j], dim);
				if (res.d_graph.find(weight) == res.d_graph.end()){
					res.d_graph.insert(std::pair<double, std::vector<edge> > (weight, std::vector<edge>()));
				}
				// printf("from frunction: weight: %f,i:%d, j:%d\n", weight, i,j);
				res.d_graph[weight].push_back(edge (i,j));
				// Make unique values
				if(weight<=cutoff_wt && weight != recent_weight){
					res.edges.push_back(weight);
					double recent_weight = weight;
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
	// int vertices_accessed = 0;

	double mst_weight = 0;
	// countruct MST
	
	std::sort(g.edges.begin(), g.edges.end());
	int edge_index = 0;
	while (edge_cnt>0){
		// while (vertices_accessed < node_cnt){
		double cur_edge_weight = g.edges.at(edge_index);
		std::vector<edge> vertices = g.d_graph.find(cur_edge_weight)->second;
		std::vector<edge>::iterator it;
		for(it = vertices.begin(); it != vertices.end(); it++){
			printf("cur_edge_weight: %f\n", cur_edge_weight);
			printf("edge_cnt: %d\n", edge_cnt);
			
			int x = it->first;
			int y = it->second;
			int root_x = Find(parent, x);
			printf("root_x: %d\n", root_x);
			int root_y = Find(parent,y);
			printf("root_y: %d\n", root_y);
			if (root_x!=root_y){
				Union(rank, parent, root_x, root_y);
				mst_weight += cur_edge_weight;
				edge_cnt--;
				// vertices_accessed++;
				}
		}
		edge_index++;
		
	}
	return mst_weight;
}

