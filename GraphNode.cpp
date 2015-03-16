#include "GraphNode.h"

GraphNode::GraphNode(char nodeName)
{
	this->nodeName  = nodeName;
	this->parent = NULL;
	this->key = MAXIMUM;
}
void GraphNode::insertSuccessor(GraphNode *successorName, int distance)
{
	Successor *successor = new Successor(successorName,distance); 
	this->successorList.push_back(successor);

	Successor *prdecessor = new Successor(this,distance);
	successorName->successorList.push_back(prdecessor);

}

bool GraphNode::isAlreadySuccessor(GraphNode *nodeCheck)
{
	for(unsigned int i = 0; i < this->successorList.size();i++)
	{
		GraphNode *node = this->successorList[i]->succNode;
		if(node->nodeName == nodeCheck->nodeName)
		{
			return true;
		}
	}
	return false;
}