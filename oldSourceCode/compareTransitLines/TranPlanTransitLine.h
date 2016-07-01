//---------------------------------------------------------------------------
#ifndef TranPlanTransitLineH
#define TranPlanTransitLineH

#include <vcl/system.hpp>
#include <iostream.h>
#include <math.h>
#include "DynamArrays.h"

class TranPlanTransitLine{
   public:

      TranPlanTransitLine(void);

      void initialize(void);
      void printHeader(FILE *ptr, char *s);
      void printRoute(FILE *ptr);
      void setLine(int i);
      void setCompany(int i);
      void setMode(int i);
      void setHeadway(float f);
      void setRg(int i);
      void setId(char *c);
      void setIdentical(bool b);
      void computeUniqueId(void);
      int getLine(void);
      int getMode(void);
      int getUniqueId(void);
      int getNumberOfNodes(void);
      int getNode(int k);
      float getHeadway(void);
      bool getIdentical(void);
      void printNodes(FILE *ptr);
      void printHeadway(FILE *ptr);
      void addNode(int i);



      protected:
         int line;
         int company;
         int mode;
         int uniqueId;
         int numberOfNodes;
         float headway;
         int rg;
         bool oneway;
         bool identical;
         char id[40];
         T1DIntArray nodes;
         

};

//---------------------------------------------------------------------------
#endif
