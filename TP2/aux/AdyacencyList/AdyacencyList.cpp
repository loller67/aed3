#include "AdyacencyList.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <assert.h>     /* assert */

using namespace std;

AdyacencyList::AdyacencyList(): edgesQ(0), nodesQ(0), settedEdges(0), edges(),peso(0),calles(0){}

AdyacencyList::AdyacencyList(int n, int m): edgesQ(m), nodesQ(n), settedEdges(0),peso(0),calles(0),
											edges(new vector<AdyacencyList::Edge>(m)){}


AdyacencyList::~AdyacencyList() {
	delete edges;
}



void AdyacencyList::addEdge(int n1, int n2){
	(*edges)[settedEdges] = Edge(n1,n2);
	settedEdges++;
}

void AdyacencyList::addEdge(int n1, int n2, int w){

	(*edges)[settedEdges] = Edge(n1,n2,w);
	settedEdges++;
}

void AdyacencyList::print(){
	for(int i = 0; i < edgesQ; i++){
		cout << "Edge " << i << ": " << (*edges)[i].node1 << " " << (*edges)[i].node2 << " " << (*edges)[i].weigth << endl;
	}
};

void AdyacencyList::printSets(std::vector<UnionDisjointSet>& v){
	for(unsigned int i = 0; i < v.size(); i++){
		cout << "Set " << i <<"{\n\tFather: " << v[i].father << "\n\tComponent: " << "[";
		for(list<int>::iterator it = v[i].component.begin(); it != v[i].component.end(); it++){
			cout << *it << ",";
		}
		cout << "]\n}" << endl;
	}
}

int AdyacencyList::getAGMWeigth(){

	vector<UnionDisjointSet> sets(nodesQ);
	int treeWeight = kruskal(sets);
	return treeWeight;
}

int AdyacencyList::kruskal(vector<UnionDisjointSet>& sets){

	int treeWeight = 0;

	//print();
	sort(edges->begin(), edges->end());

	initSets(sets);
	for(int i = 0; i < edgesQ; i++){
		Edge e = (*edges)[i];
		if(find(e.node1, sets) != find(e.node2, sets)){
			origen.push_back(e.node1);
			destino.push_back(e.node2);
			if(e.weigth>0){
				this->peso= this->peso+e.weigth;

			}
			this->calles++;
			treeWeight += e.weigth;
			join(e.node1, e.node2, sets);
		}else{
			if(e.weigth<0){
				this->peso= this->peso-e.weigth;
			}

		}
	}

	return treeWeight;
}
void AdyacencyList::initSets(vector<UnionDisjointSet>& sets){
	for(unsigned int i = 0; i < sets.size(); i++){
		sets[i].component.push_back(i);
		sets[i].father = i;
	}
}

int AdyacencyList::find(int x, vector<UnionDisjointSet>& sets){
	//cout << "Find " << 	x << ": " << sets[x].father << endl;
	return sets[x].father;
};

void AdyacencyList::join(int x, int y, vector<UnionDisjointSet>& sets){
	x = find(x, sets);
	y = find(y, sets);

	if(sets[x].component.size() < sets[y].component.size()){
		swap(x,y);
	}

	list<int>::iterator it = sets[x].component.begin();

	while(it != sets[x].component.end()){
		sets[*it].father = y;
		sets[y].component.push_back(*it);
		it++;
	}

	sets[x].component.clear();

}
void AdyacencyList::matrixToList(vector <vector < int > > &m){

	for(int i=0;i<m.size();i++){

		for(int j=i;j<m.size();j++){

				if(i!=j){

					this->addEdge(i,j,m[i][j]);

				}

			}


	}


};
