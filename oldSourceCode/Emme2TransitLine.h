//---------------------------------------------------------------------------
#ifndef Emme2TransitLineH
#define Emme2TransitLineH

#include <vcl/system.hpp>
#include <iostream.h>
#include <math.h>
#include "DynamArrays.h"
#include "Emme2TransitNode.h"

class Emme2TransitLine{
   public:

      Emme2TransitLine(void);

      void initialize(void);
      void printHeader(FILE *ptr, char *s);
      void printRoute(FILE *ptr);
      void printHeadways(FILE *ptr);
      void setMode(char *s);
      void setHeadway(float f);
      void setUserAttribute01(float f);
      void setUserAttribute02(float f);
      void setUserAttribute03(float f);
      void setAvgSpeed(float f);
      void setShortName(char *c);
      void setLongName(char *c);
      void setIdentical(bool b);
      void setTypeOfMode(int m);
      void setIntMode(int i);
      void setNodeDwellTime(int n, String dwt);
      void setNodeTravelTimeFactor(int n, String ttf);
      void setNodeLayover(int n, String lay);
      void setNodeCongestionFactor(int n, String us1);
      char* getMode(void);
      int getNumberOfNodes(void);
      Emme2TransitNode getNode(int k);
      int getIntMode(void);
      float getHeadway(void);
      float getAvgSpeed(void);
      float getUserAttribute01(void);
      float getUserAttribute02(void);
      float getUserAttribute03(void);
      bool getIdentical(void);
      char* getShortName(void);
      char* getLongName(void);
      void printNodes(FILE *ptr);
      void printHeadway(FILE *ptr);
      void printUserAttribute01(FILE *ptr);
      void printUserAttribute02(FILE *ptr);
      void printUserAttribute03(FILE *ptr);
      void printAvgSpeed(FILE *ptr);
      void addNode(int i);



      protected:
         char shortName[20];
         char mode[3];
         int typeOfMode;
         float headway;
         float avgSpeed;
         float userAttribute01;
         float userAttribute02;
         float userAttribute03;
         char longName[40];
         int ttf;

         int intMode;
         int numberOfNodes;
         DynamicArray<Emme2TransitNode> Nodes;
         int uniqueId;
         bool identical;

         

         

};

//---------------------------------------------------------------------------
#endif
