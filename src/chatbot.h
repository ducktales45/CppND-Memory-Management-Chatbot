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
    // Task 2: Implement Rule of 5 for chatbot object.
    // copy constructor
    ChatBot (const ChatBot &source)
    {        
        _image = new wxBitmap(*source._image); 
        
        _currentNode = source._currentNode;
        _rootNode = source._rootNode;        
        _chatLogic = source._chatLogic;
        std::cout << "Chatbot Copy Constructor" << std::endl;
    }
    // copy assignment operator override
    ChatBot &operator=(const ChatBot &source)
    {
        if (this == &source)
        {
            return *this;
        }
        delete _image;
        *_image = *source._image;

        _currentNode = source._currentNode;
        _rootNode = source._rootNode;
        _chatLogic = source._chatLogic;
        std::cout << "Chatbot Copy Assignment Operator" << std::endl;
    
    }
    
    // move constructor
    ChatBot (ChatBot &&source)
    {
        _image = source._image;        
        _currentNode = source._currentNode;
        _rootNode = source._rootNode;
        _chatLogic = source._chatLogic;

        source._image = NULL;
        source._currentNode = nullptr;
        source._rootNode = nullptr;
        source._chatLogic = nullptr;
        std::cout << "Chatbot Move Constructor" << std::endl;
    }

    // move assignment Operator overide
    ChatBot &operator=(ChatBot &&source)
    {
        if(this == &source)
        {
            return *this;
        }
        delete _image;
        _image = source._image;
        _currentNode = source._currentNode;
        _rootNode = source._rootNode;
        _chatLogic = source._chatLogic;

        source._image = NULL;
        source._currentNode = nullptr;
        source._rootNode = nullptr;
        source._chatLogic = nullptr;
    }

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */