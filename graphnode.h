#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory> //changed
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    //std::vector<GraphEdge *> _childEdges;  // edges to subsequent nodes // changed
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes // changed

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    ChatBot *_chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() const { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    //GraphEdge *GetChildEdgeAtIndex(int index); // changed
    std::unique_ptr<GraphEdge> GetChildEdgeAtIndex(int index); // changed
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    //void AddEdgeToChildNode(GraphEdge *edge); changed
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge); //changed
    

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot *chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */