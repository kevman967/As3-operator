//
//  Test.cpp
//  40211626_40176793_Assignment2
//
//  Created by Scott McDonald on 2022-07-20.
//
	

#include "DerivedGraph.h"
#include <iostream>
using namespace std;


int main() {
	//initializing vertices, edges, and graph
	Vertex v1(1, "one");
	Vertex v2(2, "two");
	Vertex v3(3, "three");
	Vertex v4(4, "four");

	Edge e1(1, &v1, &v2);
	Edge e2(2, &v2, &v3);
	Edge e3(3, &v1, &v3);
	Edge e4(4, &v1, &v4);

	DerivedGraph graph1;

	//testing add functions and toString function
	cout << "\n//testing add functions and toString function";
	graph1.addVertex(v1);
	graph1.addVertex(v2);
	graph1.addVertex(v3);
	graph1.addEdge(e1);
	graph1.addEdge(e2);
	graph1.addEdge(e3);
	graph1.toString();

	//testing search functions
	cout << "\n//testing search functions";
	cout << "\nv1 exists at index " << graph1.searchVertex(v1) << " in graph1. (-1 means does not exist)";
	cout << "\nv4 exists at index " << graph1.searchVertex(v4) << " in graph1. (-1 means does not exist)";
	cout << "\ne1 exists at index " << graph1.searchEdge(e1) << " in graph1. (-1 means does not exist)";
	cout << "\ne4 exists at index " << graph1.searchEdge(e4) << " in graph1. (-1 means does not exist)";

	//testing remove function
	cout << "\n\n//testing remove function";
	graph1.remove(e2);
	graph1.toString();

	//testing removeVertex function
	cout << "\n//testing removeVertex function";
	graph1.removeVertex(v1);
	graph1.toString();

	//adding back edges
	cout << "\n//adding back edges";
	graph1.addEdge(e1);
	graph1.addEdge(e2);
	graph1.addEdge(e3);
	graph1.addEdge(e4);
	graph1.toString();

	//testing addVertices function
	cout << "\n//testing addVertices function";
	Vertex* vertArray = new Vertex[2];
	vertArray[0] = v1;
	vertArray[1] = v4;
	graph1.addVertices(vertArray, 2);
	graph1.toString();

	//testing clean function
	cout << "\n//testing clean function";
	graph1.clean();
	graph1.toString();

}

