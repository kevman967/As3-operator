//
//  DerivedGraph.cpp
//  40211626_40176793_Assignment2
//
//  Created by Scott McDonald on 2022-07-20.
//

#include "DerivedGraph.h"
#include <iostream>
#include <string>
using namespace std;


//constructors and destructor
DerivedGraph::DerivedGraph() {

}

DerivedGraph::~DerivedGraph() {
	
}

DerivedGraph::DerivedGraph(const DerivedGraph& original) {
	numVert = original.numVert;
	numEdge = original.numEdge;
	for (int i = 0; i < capacity; i++) {
		E[i] = original.E[i];
		N[i] = original.N[i];
	}
}


//derived member functions
bool DerivedGraph::addVertex(Vertex& v) {

	if (numVert == capacity) return false;

	else {
		N[numVert] = v;
		numVert = numVert + 1;
		return true;
	}
}

bool DerivedGraph::addVertices(Vertex* vArray, int size) {
	
	if ((numVert + size) > capacity)	return false;

	else {
		for (int i = 0; i < size; i++) {
			N[numVert + i] = vArray[i];
		}
		numVert = numVert + size;
		return true;
	}
}

bool DerivedGraph::removeVertex(Vertex& vert) {
	//check if the vertex exists in the graph and at what position
	int exists = (*this).searchVertex(vert);		

	//if it doesn't exist, it can't be removed
	if (exists == -1)return false;					

	//if it does exist...
	else {	

		//remove the vertex from vertex array
		for (int b = exists; b < (numVert - 1); b++) {	
			N[b] = N[b + 1];
		}
		numVert--;
				
		//remove the edges that have this vertex from edge array
		for (int c = numEdge - 1; c >= 0; c--) {			
			if ((E[c].getStart() == &vert) || (E[c].getEnd() == &vert)) {
				(*this).remove(E[c]);
			}
		}
		return true;
	}
}

bool DerivedGraph::addEdge(Edge& e) {
	if (numEdge == capacity) { return false; }
	else {
		E[numEdge] = e;
		numEdge++;
		return true;
	}
}

bool DerivedGraph::remove(Edge& e) {
	
	//find where the edge is in the array
	int index = (*this).searchEdge(e);

	//if the edge doesn't exist in array, can't remove it
	if (index == -1)return false;	

	//if the edge exists in the array, remove it
	else {
		for (int i = index; i < (numEdge - 1); i++) {
			E[i] = E[i + 1];
		}
		numEdge--;
		return true;
	}
}

int DerivedGraph::searchVertex(Vertex& v) {
	for (int a = 0; a < numVert; a++) {
		if ((N[a].getId() == v.getId()) && (N[a].getValue() == v.getValue())) {
			return a;
		}
	}
	return -1;
}

int DerivedGraph::searchEdge(Edge& e) {
	for (int i = 0; i < numEdge; i++) {
		if ((E[i].getWeight()==e.getWeight()) && (E[i].getStart()==e.getStart()) && (E[i].getEnd() == e.getEnd())) {
			return i;
		}
	}
	return -1;
}

void DerivedGraph::toString() const {
	cout << "\nVERTICES\n";
	for (int i = 0; i < numVert; i++) {
		cout << N[i].getValue() << ", ";
	}
	cout << "\nEDGES\n";
	for (int i = 0; i < numEdge; i++) {
		cout << "(w=" << E[i].getWeight() << " , " << (E[i].getStart())->getId() 
			<< " , " << (E[i].getEnd())->getId() << ")\n";
	}
	
}

bool DerivedGraph::clean() {
	numVert = 0;
	numEdge = 0;
	return true;
}

// operator overloading (Assignment 3)


// this overloads the == operator to compare g1 and g2 for vertices and edges
bool DerivedGraph::operator==(const DerivedGraph& right) {

    if (numVert != right.numVert)    return false;
    if (numEdge != right.numEdge)    return false;

    for (int i = 0; i < numVert; i++) {
        if (N[i].getId() != right.N[i].getId()) { return false; }
        if (N[i].getValue() != right.N[i].getValue()) { return false; }
    }

    for (int i = 0; i < numEdge; i++) {
        if (E[i].getWeight() != right.E[i].getWeight()) { return false; }
        if (E[i].getStart() != right.E[i].getStart()) { return false; }
        if (E[i].getEnd() != right.E[i].getEnd()) { return false; }

    }
    return true;
}

// this overloads the = operator to assign g2 to g1
const DerivedGraph& DerivedGraph::operator=(const DerivedGraph& right) {
    if (&right != this) {
        
      // the arrays will be copied here
        for (int i = 0; i < capacity; i++) {
            N[i] = right.N[i];
            E[i] = right.E[i];
        }

    // vertices and edges will be copied here
        numVert = right.numVert;
        numEdge = right.numEdge;
    }
    return *this;
}

// this overloads the ++ operator to increase the weight of the edges by 1
DerivedGraph& DerivedGraph::operator++() {
    for (int a = 0; a < numEdge; a++) {
        E[a].setWeight(E[a].getWeight() + 1); // adds one based on the number of edges 'a'
    }
    return *this;
}

DerivedGraph DerivedGraph::operator++(int) {
    DerivedGraph temp = *this;
    ++(*this);
    return temp;
}

// this overloads the + operator so it returns all the vertices and edges from g1 and g2
DerivedGraph DerivedGraph::operator+(const DerivedGraph& G) const {
    DerivedGraph sum;

    //puts the vertices from both graphs into temp
    for (int a = 0; a < this->numVert; a++) {
        sum.N[a] = this->N[a];
    }
    for (int b = 0; b < G.numVert; b++) {
        sum.N[this->numVert + b] = G.N[b];
    }
    sum.numVert = this->numVert + G.numVert;

    //puts the edges from both graphs into temp
    for (int a = 0; a < this->numEdge; a++) {
        sum.E[a] = this->E[a];
    }
    for (int b = 0; b < G.numEdge; b++) {
        sum.E[this->numEdge + b] = G.E[b];
    }
    sum.numEdge = this->numEdge + G.numEdge;

    return sum;
}

// this overloads the [] operator to return the vertex at its position or update the position
Vertex DerivedGraph::operator[](int index) {
	if(index<0||index>numVert){
		cout<<"Error: Vertex "<<index<<" is out of rance"<<endl;
		exit(1);
	}
    return N[index];
    
}


// this overloads the string() operator which casts the graph object to a string that encodes all the edges








// overloads the operator << to display the graph
ostream& operator<<(ostream& out, DerivedGraph& graph) {
    string print = "";
    for (int j = 0; j < graph.numEdge; j++) {
        print = print + to_string(graph.N[j].getId()) + ", ";
    }
    out << print;
    return out;
}
