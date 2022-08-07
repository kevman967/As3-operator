//
//  DerivedGraph.h
//  40211626_40176793_Assignment2
//
//  Created by Scott McDonald on 2022-07-20.
//


#include "Graph.h"


class DerivedGraph :  public Graph
{
private:

public:
	//constructor & destructor
	DerivedGraph();
	DerivedGraph(const DerivedGraph&);
	~DerivedGraph();

	//virtual member functions
	virtual bool addVertex(Vertex& v);
	virtual bool addVertices(Vertex* vArray, int size);
	virtual bool removeVertex(Vertex& vert);	
	virtual bool addEdge(Edge& e);
	virtual bool remove(Edge& e);
	virtual int searchVertex(Vertex& v);
	virtual int searchEdge(Edge& e);
	virtual void toString() const;
	virtual bool clean();

    //operator overloading
    bool operator==(const DerivedGraph&);
    const DerivedGraph& operator=(const DerivedGraph&);
    DerivedGraph& operator++();
    DerivedGraph operator++(int);
    DerivedGraph operator+(const DerivedGraph&) const;
    Vertex operator[](int );
    //DerivedGraph operator();
    friend ostream& operator<<(ostream&, DerivedGraph&);
};
    
    
    

