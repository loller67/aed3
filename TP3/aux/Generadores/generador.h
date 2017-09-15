#ifndef _GENERADOR_H_
#define _GENERADOR_H_

#include "../AdyMatrix/AdyMatrix.h"
#include <list>
#include <time.h>
using namespace std;


AdyMatrix createCompleteGraph(int nodes_quantity);
AdyMatrix createBipartiteGraph(int nodes_quantity);
AdyMatrix createStarGraph(int nodes_quantity);
AdyMatrix createPathGraph(int nodes_quantity);
AdyMatrix createCicleGraph(int nodes_quantity);
AdyMatrix createBinaryTreeBalanced(int nodes_quantity);
AdyMatrix createMixGraph(int nodes_quantity); // cliques unidas por un nodo
AdyMatrix createMagicGraph(int nodes_quantity, int cliques);// clique de cliques
AdyMatrix createBadGraphForGreedy(int kn_size);
AdyMatrix createBadGraphForGreedyVersion2(int kn_size);
AdyMatrix createKRegularRandomGraph(int k, int n);

#endif
