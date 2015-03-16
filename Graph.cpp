#include"Graph.h"

void Graph::addNode(GraphNode *gn)
{
	this->nodes.push_back(gn);
	this->queue.push_back(gn);
}

bool Graph::isParentExisting(GraphNode *gn)
{
	for(unsigned int i=0;i<nodes.size();i++)
	{
		if(this->nodes[i]->nodeName == gn->nodeName) 
		return true;
	}
	return false;
}
void Graph::MSTPrim()
{
	MinPriority priorityQueue;
	int shortestPath = 0;
	for(unsigned int i = 0; i<nodes.size();i++)
	{
		nodes[i]->parent = NULL;
		nodes[i]->key = MAXIMUM;
	}
			
	GraphNode *startNode = nodes[0];
	startNode->key = 0;
	/*for(int j=((queue.size()) / 2)-1;j>=0;j--)
	{
			priorityQueue.minHeapify(j,queue.size(),queue);
	}*/

			

		   
	while(!queue.empty())
	{
		priorityQueue.minHeapify(0,queue.size(),queue);
		GraphNode *u = priorityQueue.heapExtractMin(queue);//queue[0];
		string name;
		if(u->parent==NULL)
		{
			name = "NIL";
		}
		else
		{
			name = u->parent->nodeName;
		}
		cout<<u->nodeName<<" "<<name<<" "<<u->key<<endl;
		shortestPath+=u->key;
		//queue = priorityQueue.rearrangeQueue(queue);
		for(unsigned int i = 0;i<u->successorList.size();i++)
		{
			GraphNode *v = u->successorList[i]->succNode; 
			if(priorityQueue.contains(queue,v) && this->weight(u,v) < v->key)
			{
				v->parent = u;
				priorityQueue.heapDecreaseKey(queue,v,this->weight(u,v));
			}
		}		
	}
	cout<<shortestPath;

}

		
int Graph::weight(GraphNode *gn1,GraphNode *gn2)
{
	int index = -1;
	for(unsigned int i = 0; i<this->nodes.size();i++)
	{
		if(this->nodes[i]->nodeName == gn1->nodeName)
		{
			index = i;
			for(unsigned int j=0;j < this->nodes[i]->successorList.size();j++)
			{
					GraphNode *node = this->nodes[i]->successorList[j]->succNode;  
					if(node->nodeName == gn2->nodeName)
					{
							return this->nodes[i]->successorList[j]->distance;	
					}
			}
		}
	}
	return MAXIMUM;
}