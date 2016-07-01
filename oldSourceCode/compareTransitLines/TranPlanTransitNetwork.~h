//---------------------------------------------------------------------------
#ifndef TranPlanTransitNetworkH
#define TranPlanTransitNetworkH

#include <vcl/system.hpp>
#include <iostream.h>
#include <stdio.h>
#include <math.h>

#include "TranPlanTransitLine.h"

class TranPlanTransitNetwork
{
   public:

      TranPlanTransitNetwork(void);

      TranPlanTransitNetwork(char *n);

      void addLine(void);
      void readLines(bool debug, FILE *optr);
      void readLines(void);
      void compareItineraries(TranPlanTransitNetwork *compare, FILE *ptr);
      int getNumberOfLines(void);

      protected:
      
         int numberOfLines;
         DynamicArray<TranPlanTransitLine> Lines;
         char name[40];
         FILE *fptr;

};

//---------------------------------------------------------------------------
#endif
