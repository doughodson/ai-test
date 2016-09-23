
#include "AgentData.hpp"

#include "soar/sml_Client.h"

AgentData::AgentData(sml::Agent* _agent): agent(_agent)
{
   // establish input link
   inputLink = agent->GetInputLink();
   // create and initialize working memory elements
   wmeFront = agent->CreateStringWME(inputLink, "front", "empty");
}

