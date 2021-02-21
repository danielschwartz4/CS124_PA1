#include "functions.h"
#include <iostream>

int main(void) {
  // Test 1------------------------------------------
  // Add d_graph
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
}

  // graph g2;
  // dist_graph d2;
  // d2.insert(std::pair<double, std::vector<edge> > (1, std::vector<edge>()));
  // d2.insert(std::pair<double, std::vector<edge> > (2, std::vector<edge>()));
  // d2.insert(std::pair<double, std::vector<edge> > (3, std::vector<edge>()));

  // d2[1].push_back(edge (1, 2)); 
  // d2[2].push_back(edge (2, 3)); 
  // d2[3].push_back(edge (1, 3));
  // g2.d_graph = d2;
  
  // // Add edges
  // std::vector<double> v2;
 
  // v2.push_back(1);
  // v2.push_back(2);
  // v2.push_back(3);
  // g2.edges = v2;
  

  // double w2 = kruskal_weight(g2, 3);
  // std::cout << "weight 2: " << w2 << "\n";













// // Test 3 complete Graph------------------------------------------
//   graph g2;
//   dist_graph d2;
//   d2.insert(std::pair<double, std::vector<edge> > (1, std::vector<edge>()));
//   d2.insert(std::pair<double, std::vector<edge> > (2, std::vector<edge>()));
//   d2.insert(std::pair<double, std::vector<edge> > (3, std::vector<edge>()));
//   d2.insert(std::pair<double, std::vector<edge> > (4, std::vector<edge>()));
//   d2.insert(std::pair<double, std::vector<edge> > (5, std::vector<edge>()));
//   d2[1].push_back(edge (1, 4)); 
//   d2[2].push_back(edge (3, 4)); 
//   d2[2].push_back(edge (4, 2));
//   d2[3].push_back(edge (1, 2));
//   d2[4].push_back(edge (2, 3));
//   d2[5].push_back(edge (1, 3)); 
//   g2.d_graph = d2;
  
//   // Add edges
//   std::vector<double> v2;
 
//   v2.push_back(1);
//   v2.push_back(2);
//   v2.push_back(2);
//   v2.push_back(3);
//   v2.push_back(4);
//   v2.push_back(5);
//   g2.edges = v2;
  

//   double w2 = kruskal_weight(g2, 4);
//   std::cout << "weight 2: " << w2 << "\n";

// }

// int main(void){
//   graph g1;
//   dist_graph d1;
//   d1.insert(std::pair<double, std::vector<edge> > (0, std::vector<edge>()));
//   d1.insert(std::pair<double, std::vector<edge> > (1, std::vector<edge>()));
//   d1.insert(std::pair<double, std::vector<edge> > (2, std::vector<edge>()));
//   d1.insert(std::pair<double, std::vector<edge> > (3, std::vector<edge>()));
//   d1.insert(std::pair<double, std::vector<edge> > (4, std::vector<edge>()));
//   d1[0].push_back(edge (1, 2)); 
//   d1[0].push_back(edge (3, 5)); 
//   d1[0].push_back(edge (5, 0));
//   d1[1].push_back(edge (2, 3));
//   d1[1].push_back(edge (3, 4));
//   d1[2].push_back(edge (1, 3)); 
//   d1[3].push_back(edge (2, 5));
//   d1[4].push_back(edge (4, 5));
//   g1.d_graph = d1;
  
//   // Add edges
//   std::vector<double> v1;
 
//   v1.push_back(0);
//   v1.push_back(0);
//   v1.push_back(0);
//   v1.push_back(1);
//   v1.push_back(1);
//   v1.push_back(2);
//   v1.push_back(3);
//   v1.push_back(4);
//   g1.edges = v1;

//   double w1 = kruskal_weight(g1, 6);
//   std::cout << "weight 1: " << w1 << "\n";

//   graph g2;
//   dist_graph d2;
//   d2.insert(std::pair<double, std::vector<edge> > (1, std::vector<edge>()));
//   d2.insert(std::pair<double, std::vector<edge> > (2, std::vector<edge>()));
//   d2.insert(std::pair<double, std::vector<edge> > (3, std::vector<edge>()));
//   d2.insert(std::pair<double, std::vector<edge> > (4, std::vector<edge>()));
//   d2[1].push_back(edge (2, 3));
//   d2[1].push_back(edge (3, 4));
//   d2[2].push_back(edge (1, 3)); 
//   d2[3].push_back(edge (2, 5));
//   d2[4].push_back(edge (4, 5));
//   d2[1].push_back(edge (4, 3));
//   g2.d_graph = d2;
  
//   // Add edges
//   std::vector<double> v2;
 
//   v2.push_back(1);
//   v2.push_back(1);
//   v2.push_back(2);
//   v2.push_back(3);
//   v2.push_back(4);
//   g2.edges = v2;

//   double w2 = kruskal_weight(g2, 5);
//   std::cout << "weight 1: " << w2 << "\n";
// }
