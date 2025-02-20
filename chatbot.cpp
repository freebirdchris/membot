/>home>workspace>CppND-Memory-Management-Chatbot>src
DESKTOP
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
​
#include "chatlogic.h"
#include "graphnode.h"
#include "graphedge.h"
#include "chatbot.h"
​
// constructor WITHOUT memory allocation
ChatBot::ChatBot()
{
    // invalidate data handles
    _image = nullptr;
    _chatLogic = nullptr;
    _rootNode = nullptr;
}
​
// constructor WITH memory allocation
ChatBot::ChatBot(std::string filename)
{
+
BASH
×
No Open Terminals
NEW TERMINAL
