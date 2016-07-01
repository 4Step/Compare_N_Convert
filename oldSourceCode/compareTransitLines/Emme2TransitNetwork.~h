//---------------------------------------------------------------------------
#ifndef Emme2TransitNetworkH
#define Emme2TransitNetworkH

#include <vcl/system.hpp>
#include <iostream.h>
#include <stdio.h>
#include <math.h>

#include "Emme2TransitLine.h"

class Emme2TransitNetwork
{
   public:

      Emme2TransitNetwork(void);

      Emme2TransitNetwork(char *n);

      void addLine(void);
      void readLines(bool debug, FILE *optr);
      void compareItineraries(Emme2TransitNetwork *compare, FILE *ptr);
      int getNumberOfLines(void);

      protected:
      
         int numberOfLines;
         DynamicArray<Emme2TransitLine> Lines;
         char name[40];
         DynamicArray<String> modeToInt;
         FILE *fptr;

};

//---------------------------------------------------------------------------
#endif
