
#ifndef __AgentData_H__
#define __AgentData_H__

namespace sml { class Agent; class Identifier; class StringElement; }

class AgentData
{
public:
   AgentData(sml::Agent*);

   sml::Agent* agent = {nullptr};
   sml::Identifier* inputLink = {nullptr};
   sml::StringElement* wmeFront = {nullptr};

};

#endif

