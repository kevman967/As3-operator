//
//  Graph.h
//  40211626_40176793_Assignment2
//
//  Created by Scott McDonald on 2022-07-20.
//

#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"


class Graph
{
protected:

	Vertex* N;
	Edge* E;
	int numVert;
	int numEdge;
	const int capacity = 10;

public:
	Graph();
	virtual ~Graph();

	//add in one vertex; bool returns true if it is added successfully.
	virtual bool addVertex(Vertex& v) = 0;
	virtual bool addVertices(Vertex* vArray, int size) = 0;
	
	//the edges that has connection with this vertex need to be removed;
	virtual bool removeVertex(Vertex& vert) = 0;
	
	//remove a edge; as a result, some node may remain as orphan.
	virtual bool addEdge(Edge& e) = 0;
	
	// remove the edge
	virtual bool remove(Edge& e) = 0;
	
	// return bool if a vertex exists in a graph;
	virtual int searchVertex(Vertex& v) = 0;
	
	// return bool if a Edge exists in a graph;
	virtual int searchEdge(Edge& e) = 0;
	
	// define your own format of a string representation of the graph.
	virtual void toString() const = 0;
	
	//remove all the vertices and edges;
	virtual bool clean() = 0;

};

#endif //GRAPH_H



