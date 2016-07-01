//---------------------------------------------------------------------------
#ifndef Emme2TransitNodeH
#define Emme2TransitNodeH

#include <vcl/system.hpp>
#include <iostream.h>
#include <math.h>
#include "DynamArrays.h"

class Emme2TransitNode{
   public:

      Emme2TransitNode();
      Emme2TransitNode(int n);

      void initialize(void);
      void setDwellTime(String dwt);
      void setTravelTimeFactor(String ttf);
      void setLayover(String lay);
      void setCongestionFactor(String us1);

      int getNumber(void);
      String getDwellTime();
      String getTravelTimeFactor();
      String getLayover();
      String getCongestionFactor();

      void printYourself(FILE *ptr);
      bool isDudeLikeMe(Emme2TransitNode);

      protected:
         int number;
         String dwellTime;
         String travelTimeFactor;
         String layover;
         String congestionFactor;
         

};

//---------------------------------------------------------------------------
#endif
