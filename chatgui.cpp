/>home>workspace>CppND-Memory-Management-Chatbot>src
DESKTOP
#include <wx/filename.h>
#include <wx/colour.h>
#include <wx/image.h>
#include <string>
#include "chatbot.h"
#include "chatlogic.h"
#include "chatgui.h"
​
​
​
// size of chatbot window
const int width = 414;
const int height = 736;
​
// wxWidgets APP
IMPLEMENT_APP(ChatBotApp);
​
std::string dataPath = "../";
std::string imgBasePath = dataPath + "images/";
​
bool ChatBotApp::OnInit()
{
+
BASH
×
No Open Terminals
NEW TERMINAL
