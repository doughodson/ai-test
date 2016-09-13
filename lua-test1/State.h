
#ifndef __State_H__
#define __State_H__

class State
{
public:
   State();
   virtual ~State();

   // set/get
   virtual void setAlive(const bool x)                 { alive = x; return; }
   virtual bool isAlive() const                        { return alive; }

   virtual void setRoll(const double x)                { roll = x; return; }
   virtual double getRoll() const                      { return roll; }

   virtual void setPitch(const double x)               { pitch = x; return; }
   virtual double getPitch() const                     { return pitch; }

private:

   bool alive;
   double roll;
   double pitch;

};

#endif
