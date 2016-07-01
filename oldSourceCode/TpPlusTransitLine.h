//---------------------------------------------------------------------------
#ifndef TpPlusTransitLineH
#define TpPlusTransitLineH

#include <vcl/system.hpp>
#include <iostream.h>
#include <math.h>
#include "DynamArrays.h"

class TpPlusTransitLine{
   public:

      TpPlusTransitLine(void);

      void initialize(void);
      void printHeader(FILE *ptr, char *s);
      void printRoute(FILE *ptr);
      void printHeadways(FILE *ptr);
      void setMode(int i);
      void setFreq1(float f);
      void setFreq2(float f);
      void setName(char *c);
      void setIdentical(bool b);
      int getMode(void);
      int getNumberOfNodes(void);
      int getNode(int k);
      float getFreq1(void);
      float getFreq2(void);
      bool getIdentical(void);
      char* getName(void);
      void printNodes(FILE *ptr);
      void printFreq1(FILE *ptr);
      void printFreq2(FILE *ptr);
      void addNode(int i);



      protected:
         int line;
         char name[40];
         float timefac;
         int runtime;
         bool oneway;
         int mode;
         char owner[40];
         int color;
         int xyspeed;
         float freq1;
         float freq2;
         int uniqueId;
         int numberOfNodes;
         bool identical;
         T1DIntArray nodes;
         

         

};

//---------------------------------------------------------------------------
#endif
