#include"DerivedGraph.h"
#include <iostream>
using namespace std;
int main(){
    Vertex v1(1, "one");
	Vertex v2(2, "two");
	Vertex v3(3, "three");
	Vertex v4(4, "four");
    Vertex v5(5,"five");

	Edge e1(1, &v1, &v2);
	Edge e2(2, &v2, &v3);
	Edge e3(3, &v1, &v3);
	Edge e4(4, &v1, &v4);

	DerivedGraph graph1;
    graph1.addVertex(v1);
	graph1.addVertex(v2);
	graph1.addVertex(v3);
	graph1.addEdge(e1);
	graph1.addEdge(e2);
	graph1.addEdge(e3);
    cout<<"\nTesting vertex v5\n";
    v5.printVertex();
    cout<<"\nTesting [] operator\n";
    v5 = graph1[0];
    v5.printVertex();

}