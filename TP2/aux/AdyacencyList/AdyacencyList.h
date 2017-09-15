#ifndef _ADYACENCY_LIST_H_
#define _ADYACENCY_LIST_H_

#include <vector>
#include <list>
#include <iostream>
using namespace std;

class AdyacencyList {
public:
	AdyacencyList();
	AdyacencyList(int n, int m);
	~AdyacencyList();

	void addEdge(int n1, int n2);
	void addEdge(int n1, int n2, int w);

	int getAGMWeigth();
	void print();
	void matrixToList(vector <vector < int > >& m);
	int peso;
	int calles;
	vector<int> origen;
	vector<int> destino;

private:

	struct Edge {
		int node1;
		int node2;
		int weigth;

		Edge(): node1(0), node2(0), weigth(0){};
		Edge(int n1, int n2):node1(n1), node2(n2), weigth(0){};
		Edge(int n1, int n2, int p):node1(n1), node2(n2), weigth(p){};

		bool operator<(const Edge& other) const {
    		if(weigth != other.weigth)
    			return (weigth < other.weigth);
    		else if(node1 != node2)
    			return node1 > node2;

    		return node2 > node2;
		}
	};

	struct UnionDisjointSet{
		int father;
		list<int> component;
	};

	int kruskal(vector<UnionDisjointSet>& sets);
	int find(int x, vector<UnionDisjointSet>& v);
	void initSets(vector<UnionDisjointSet>& v);
	void join(int x, int y, vector<UnionDisjointSet>& v);

	void printSets(std::vector<UnionDisjointSet>& v);

	int edgesQ;
	int nodesQ;
	int settedEdges;

	vector<Edge>* edges;

};

#endif
