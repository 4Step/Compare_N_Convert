//---------------------------------------------------------------------------
#ifndef TransCadTransitNetworkH
#define TransCadTransitNetworkH

#include <vcl/system.hpp>
#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include "ReadDB.h"

#include "TransCadTransitLine.h"

class TransCadTransitNetwork
{
   public:

      TransCadTransitNetwork(void);

      TransCadTransitNetwork(char *infoFile, char *nodeFile, FILE *optr, bool debug);
      
      void addLine(void);
      void readLines(bool debug, FILE *optr);
      void readLines(void);
      void compareItineraries(TransCadTransitNetwork *compare, FILE *ptr);
      int getNumberOfLines(void);

      protected:
      
         // dbf header for info and node
         DBHead infoDbHeader;
         DBHead nodeDbHeader; 
         
         FILE *infoFptr;
         FILE *nodeFptr;

         int numberOfLines;
         DynamicArray<TransCadTransitLine> Lines;
         char name[40];
         FILE *fptr;

};

//---------------------------------------------------------------------------
#endif
