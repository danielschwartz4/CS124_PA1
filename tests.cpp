#include "functions.h"
#include <iostream>

int main(void) {
  // Test 1 non-complete graph------------------------------------------
  // Add dist_graph
  graph g1;
  dist_graph d1;
  d1.insert(std::pair<double, std::vector<edge> > (0, std::vector<edge>()));
  d1.insert(std::pair<double, std::vector<edge> > (1, std::vector<edge>()));
  d1.insert(std::pair<double, std::vector<edge> > (2, std::vector<edge>()));
  d1.insert(std::pair<double, std::vector<edge> > (3, std::vector<edge>()));
  d1.insert(std::pair<double, std::vector<edge> > (4, std::vector<edge>()));
  d1[0].push_back(edge (1, 2)); 
  d1[0].push_back(edge (3, 5)); 
  d1[0].push_back(edge (5, 0));
  d1[1].push_back(edge (2, 3));
  d1[1].push_back(edge (3, 4));
  d1[2].push_back(edge (1, 3)); 
  d1[3].push_back(edge (2, 5));
  d1[4].push_back(edge (4, 5));
  g1.d_graph = d1;
  
  // Add edges
  std::vector<double> v1;
 
  v1.push_back(0);
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(4);
  g1.edges = v1;

  double w1 = kruskal_weight(g1, 6);
  std::cout << "weight 1: " << w1 << "\n";

  // Test 2 complete Graph------------------------------------------
  graph g2;
  dist_graph d2;
  d2.insert(std::pair<double, std::vector<edge> > (1, std::vector<edge>()));
  d2.insert(std::pair<double, std::vector<edge> > (2, std::vector<edge>()));
  d2.insert(std::pair<double, std::vector<edge> > (3, std::vector<edge>()));
  d2.insert(std::pair<double, std::vector<edge> > (4, std::vector<edge>()));
  d2.insert(std::pair<double, std::vector<edge> > (5, std::vector<edge>()));
  d2[1].push_back(edge (0, 1));
  d2[2].push_back(edge (1, 2));
  d2[3].push_back(edge (2, 3));
  d2[4].push_back(edge (3, 0));
  d2[5].push_back(edge (1, 3));
  g2.d_graph = d2;
  // Add edges
  std::vector<double> v2;
 
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(3);
  v2.push_back(4);
  v2.push_back(5);
  g2.edges = v2;

  double w2 = kruskal_weight(g2, 4);
  std::cout << "weight 1: " << w2 << "\n";

  // Test 3 two nodes------------------------------------------
  graph g3;
  dist_graph d3;
  d3.insert(std::pair<double, std::vector<edge> > (4, std::vector<edge>()));

  d3[4].push_back(edge (0, 1));

  g3.d_graph = d3;
  // Add edges
  std::vector<double> v3;
 
  v3.push_back(4);

  g3.edges = v3;

  double w3 = kruskal_weight(g3, 2);
  std::cout << "weight 1: " << w3 << "\n";

  // Test 4 triangle------------------------------------------
  graph g4;
  dist_graph d4;
  d4.insert(std::pair<double, std::vector<edge> > (4, std::vector<edge>()));
  d4.insert(std::pair<double, std::vector<edge> > (5, std::vector<edge>()));
  d4.insert(std::pair<double, std::vector<edge> > (6, std::vector<edge>()));


  d4[4].push_back(edge (0, 1));
  d4[5].push_back(edge (1, 2));
  d4[6].push_back(edge (2, 0));

  g4.d_graph = d4;
  // Add edges
  std::vector<double> v4;
 
  v4.push_back(4);
  v4.push_back(5);
  v4.push_back(6);

  g4.edges = v4;

  double w4 = kruskal_weight(g4, 3);
  std::cout << "weight 1: " << w4 << "\n";

  // Test 4 triangle------------------------------------------
  graph g4;
  dist_graph d4;
  d4.insert(std::pair<double, std::vector<edge> > (4, std::vector<edge>()));


  d4[4].push_back(edge (0, 1));
  d4[5].push_back(edge (1, 2));
  d4[6].push_back(edge (2, 0));

  g4.d_graph = d4;
  // Add edges
  std::vector<double> v4;
 
  v4.push_back(4);
  v4.push_back(5);
  v4.push_back(6);

  g4.edges = v4;

  double w4 = kruskal_weight(g4, 3);
  std::cout << "weight 1: " << w4 << "\n";
}
