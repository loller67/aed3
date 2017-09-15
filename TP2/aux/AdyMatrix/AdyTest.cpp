#include "AdyMatrix.h"

void testCreateGraph(){
	AdyMatrix ad(5);
	ad.addEdge(1,3);
	cout<< ad.get(1,1)<<endl;
	ad.print();
}




int main(){
	
	testCreateGraph();	
	return 0;
	}
