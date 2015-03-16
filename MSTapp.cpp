//bool isParentExisting(vector<GraphNode*> nodes, GraphNode *gn);
//void addEdge(Graph *gr,GraphNode *gn1, GraphNode *gn2,int distance);
#include <iostream>
#include <fstream>
#include <string>
#include "MSTapp.h"

using namespace std;

void MSTapp::processApp()
{
	  Graph *graph_obj = new Graph();  

	  char vertex, edge;
	  int weight;

	  //gets first line
	  while(cin.peek() != '\n') 
	  {
		cin >> vertex;
		GraphNode *gn = new GraphNode(vertex);
		graph_obj->addNode(gn);
	  }

	  //Populate adjacency list
	  while(cin >> vertex) 
	  {
		cin >> edge;
		cin >> weight;

		GraphNode *gn1 =this->findVertex(graph_obj,vertex);
		GraphNode *gn2 =this->findVertex(graph_obj,edge);
		
		if(gn1!=NULL&& gn2!=NULL)
		{
			this->addEdge(graph_obj,gn1,gn2,weight);
		}

		//graph_obj->MSTPrim();
		//GraphNode *a = new  GraphNode('a');
		//GraphNode *b = new  GraphNode('b');
		//GraphNode *c = new  GraphNode('c');
		//GraphNode *d = new  GraphNode('d');
		//GraphNode *e = new  GraphNode('e');
		//GraphNode *f = new  GraphNode('f');
		//GraphNode *g = new  GraphNode('g');
		////GraphNode *g = new  GraphNode('');
		///*GraphNode *h = new  GraphNode('b');
		//GraphNode *i = new  GraphNode('a');*/
	
		//Graph *gr = new Graph();
		//
		//gr->addNode(a); //a
		//gr->addNode(b); //b
		//gr->addNode(c); //c
		//gr->addNode(d); //d 
		//gr->addNode(e); //e
		//gr->addNode(f); //f
		//gr->addNode(g); //g
		////gr->addNode(h); //h
		////gr->addNode(i); //i
		////gr->addNode();
	
		//addEdge(gr,a,b,3);
		//addEdge(gr,a,e,4);
		//addEdge(gr,b,c,7);
		//addEdge(gr,b,e,6);
		//addEdge(gr,b,f,5);
		//addEdge(gr,c,d,9);
		//addEdge(gr,c,f,8);
		//addEdge(gr,d,e,9);
		//addEdge(gr,d,g,4);
		//addEdge(gr,e,f,6);
		//addEdge(gr,f,g,8);
		////addEdge(gr,d,f,14);
		////addEdge(gr,d,e,9);
		////addEdge(gr,f,e,10);
		//////addEdge(gr,f,e,10);
	
		//gr->MSTPrim();
	  }

	  //Calls Prim's MST
	  graph_obj->MSTPrim(); 
	}
    
	GraphNode* MSTapp::findVertex(Graph *gr,char name)
	{
		for(unsigned int i =0 ;i<gr->nodes.size();i++)
		{
			if(name==gr->nodes[i]->nodeName)
			{
				return gr->nodes[i];
			}
		}
		return NULL;
	}
    void MSTapp::addEdge(Graph *gr,GraphNode *gn1, GraphNode *gn2,int distance)
	{
		if(gr->isParentExisting(gn1))
		{
			gn1->insertSuccessor(gn2, distance);
		}
    }

int main()
{
  MSTapp mstapp_obj;
  mstapp_obj.processApp();
}



//int main()
//{
//	GraphNode *j = new  GraphNode('j');
//	GraphNode *i = new  GraphNode('i');
//	GraphNode *h = new  GraphNode('h');
//	GraphNode *g = new  GraphNode('g');
//	GraphNode *f = new  GraphNode('f');
//	GraphNode *e = new  GraphNode('e');
//	GraphNode *d = new  GraphNode('d');
//	GraphNode *c = new  GraphNode('c');
//	GraphNode *b = new  GraphNode('b');
//	GraphNode *a = new  GraphNode('a');
//
//	Graph *gr = new Graph();
//	
//	gr->addNode(j); //a
//	gr->addNode(i); //b
//	gr->addNode(h); //c
//	gr->addNode(g); //d 
//	gr->addNode(f); //e
//	gr->addNode(e); //f
//	gr->addNode(d); //g
//	gr->addNode(c); //h
//	gr->addNode(b); //i
//	gr->addNode(a);
//
//	addEdge(gr,a,b,1);
//	addEdge(gr,a,c,1);
//	addEdge(gr,a,d,1);
//	addEdge(gr,e,a,1);
//	addEdge(gr,f,a,1);
//	addEdge(gr,g,a,1);
//	addEdge(gr,h,a,1);
//	addEdge(gr,i,a,1);
//	addEdge(gr,a,j,1);
//	//addEdge(gr,g,h,1);
//	//addEdge(gr,g,f,2);
//	//addEdge(gr,d,f,14);
//	//addEdge(gr,d,e,9);
//	//addEdge(gr,f,e,10);
//	////addEdge(gr,f,e,10);
//
//	gr->MSTPrim();
//	return 0;
//}
//
