#include "graphedge.h"
#include "graphnode.h"
#include <memory> //changed

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

//void GraphNode::AddEdgeToChildNode(GraphEdge *edge) //changed
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) //changed
{
    //_childEdges.push_back(edge); //changed
    _childEdges.push_back(std::move(edge)); //changed
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

//GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) //changed
std::unique_ptr<GraphEdge> GraphNode::GetChildEdgeAtIndex(int index) //changed
{
    //// STUDENT CODE
    ////

    //return _childEdges[index]; //changed
    return std::move(_childEdges[index]); // changed

    ////
    //// EOF STUDENT CODE
}