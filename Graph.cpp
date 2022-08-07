//
//  Graph.cpp
//  40211626_40176793_Assignment2
//
//  Created by Scott McDonald on 2022-07-20.
//

#include "Graph.h"


Graph::Graph(): numEdge(0), numVert(0) {
	N = new Vertex[capacity];
	E = new Edge[capacity];
}

Graph::~Graph() {
	delete[] N;
	delete[] E;
}
