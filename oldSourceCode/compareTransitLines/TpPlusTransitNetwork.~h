//---------------------------------------------------------------------------
#ifndef TpPlusTransitNetworkH
#define TpPlusTransitNetworkH

#include <vcl/system.hpp>
#include <iostream.h>
#include <stdio.h>
#include <math.h>

#include "TpPlusTransitLine.h"

class TpPlusTransitNetwork
{
   public:

      TpPlusTransitNetwork(void);

      TpPlusTransitNetwork(char *n);

      void addLine(void);
      void readLines(bool debug, FILE *optr);
      void compareItineraries(TpPlusTransitNetwork *compare, FILE *ptr);
      int getNumberOfLines(void);

      protected:
      
         int numberOfLines;
         DynamicArray<TpPlusTransitLine> Lines;
         char name[40];
         FILE *fptr;

};

//---------------------------------------------------------------------------
#endif
