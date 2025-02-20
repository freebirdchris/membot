#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    // copy assignment constructor
    ChatBot& operator=(ChatBot& rhs) {
        std::cout << "ChatBot copy assignment constructor" << std::endl;
        _currentNode = rhs._currentNode;
        _rootNode = rhs._rootNode;
        _chatLogic = rhs._chatLogic;
        _image = rhs._image;
        return *this;
    };

    // copy assignment constructor
    ChatBot &operator=(const ChatBot& rhs) {
        std::cout << "ChatBot copy assignment constructor" << std::endl;
        if (this == &rhs)
        	return *this;
        _currentNode = rhs._currentNode;
        _rootNode = rhs._rootNode;
        _chatLogic = rhs._chatLogic;
        _image = rhs._image;
        return *this;
    };

    // move constructor
    ChatBot(ChatBot&& rhs) noexcept {
        std::cout << "ChatBot move constructor" << std::endl;
        _currentNode = rhs._currentNode;
        _rootNode = rhs._rootNode;
        _chatLogic = rhs._chatLogic;
        _image = rhs._image;
        rhs._currentNode = nullptr;
        rhs._rootNode = nullptr;
        rhs._chatLogic = nullptr;
        rhs._image = nullptr;
    }

    // move assignment operator
    ChatBot& operator=(ChatBot&& rhs) noexcept {
        std::cout << "ChatBot move assignment operator" << std::endl;
        if (this == &rhs)
        	return *this;
        _currentNode = rhs._currentNode;
        _rootNode = rhs._rootNode;
        _chatLogic = rhs._chatLogic;
        _image = rhs._image;
        rhs._currentNode = nullptr;
        rhs._rootNode = nullptr;
        rhs._chatLogic = nullptr;
        rhs._image = nullptr;
        return *this;
    }

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
