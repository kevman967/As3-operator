//
//  Edge.cpp
//  40211626_40176793_Assignment2
//
//  Created by Scott McDonald on 2022-07-20.
//

#include "Edge.h"
#include <iostream>


Edge::Edge(): weight(0) {
	start = nullptr;
	end = nullptr;
}

Edge::Edge(int w, Vertex* v1, Vertex* v2): weight(w), start(v1), end(v2) {}
Edge::~Edge(){}

int Edge::getWeight() {
	return weight;
}

Vertex* Edge::getStart() {
	return start;
}

Vertex* Edge::getEnd() {
	return end;
}

void Edge::setWeight(int newWeight) {
	weight = newWeight;
}

void Edge::setStart(Vertex* vert) {
	start = vert;
}

void Edge::setEnd(Vertex* verti) {
	end = verti;
}

void Edge::printEdge() {
	std::cout << "Edge weight: " << weight << "\nStart Vertex\n\tid: " << start->getId() << "\n\tvalue: " << start->getValue();
	std::cout << "\nEnd Vertex\n\tid: " << end->getId() << "\n\tvalue: " << end->getValue();
}
