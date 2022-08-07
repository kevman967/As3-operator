//
//  Edge.h
//  40211626_40176793_Assignment2
//
//  Created by Scott McDonald on 2022-07-20.
//

#ifndef EDGE_H
#define EDGE_H


#include "Vertex.h"

class Edge
{
public:

	Edge();
	Edge(int, Vertex*, Vertex*);
	~Edge();

	int getWeight();
	Vertex* getStart();
	Vertex* getEnd();

	void setWeight(int);
	void setStart(Vertex*);
	void setEnd(Vertex*);

	void printEdge();

private:

	int weight;
	Vertex* start;
	Vertex* end;

};

#endif //EDGE_H
