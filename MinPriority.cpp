#include"MinPriority.h"


void MinPriority::heapDecreaseKey(vector<GraphNode*> &graphNodes, GraphNode *gn , int key)
{
	if(key>gn->key)
	{
		return;
	}
	gn->key = key;
	unsigned int index = this->getIndex(graphNodes,gn);
	while(index>0 && graphNodes[parent(index)]->key > graphNodes[index]->key)
	{
		swap(graphNodes[index],graphNodes[parent(index)]);
		index = parent(index);
	}
}
	 
int MinPriority::getIndex(vector<GraphNode*> graphNodes,GraphNode *gn)
{
	for(unsigned int i =0 ;i<graphNodes.size();i++)
	{
		if(graphNodes[i]->nodeName == gn->nodeName)
		{
			return i;
		}
	}
	return -1;
} 

int MinPriority::parent(int index)
{
	int p_index = (index-1)/2;
	return p_index;
}

int MinPriority::rightChild(int index)
{
	int r_index = 2*index+2;
	return r_index;
}

int MinPriority::leftChild(int index)
{
	int l_index = 2*index+1;
	return l_index;
}

void MinPriority::minHeapify(int i,int heapsize,vector<GraphNode *> &pqueue)
{
	int l = this->leftChild(i);
	int r = this->rightChild(i);
	int smallest;

	if ((l<heapsize) && (pqueue[l]->key < pqueue[i]->key))		//comparing parent with left child
	{
			
		smallest=l;
	}

	else 
	{
		smallest=i;
	}
	int t=smallest;
    
	if ((r<heapsize) && (pqueue[r]->key < pqueue[smallest]->key)) 
	{
		smallest=r;
	}
	if (smallest!=i)							
	{
		swap(pqueue[smallest],pqueue[i]);        		
		minHeapify(smallest,heapsize,pqueue);
	}
}

bool MinPriority::contains(vector<GraphNode*> queue,GraphNode *gn1)
{
	for(unsigned int i = 0;i<queue.size();i++)
	{
		if(queue[i]==gn1)
		{
			return true;
		}
	}
	return false;	
}

GraphNode* MinPriority::heapExtractMin(vector<GraphNode*> &graphNodes)
{
	if(!graphNodes.empty())
	{
		GraphNode *min = min = graphNodes[0];
		graphNodes[0]=graphNodes[graphNodes.size()-1]; // assign might be needed here as well
		graphNodes.pop_back();
		this->minHeapify(0,graphNodes.size(),graphNodes);
		return min;
	}
	return NULL;
}