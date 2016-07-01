//---------------------------------------------------------------------------
#pragma hdrstop

#include "TpPlusTransitLine.h"

TpPlusTransitLine::TpPlusTransitLine(void)
{
   initialize();
}

void TpPlusTransitLine::initialize(void)
{
   line = 0;
   strcpy(name,"Blank");
   timefac = 0.0;
   runtime = 0;
   oneway = 0;
   mode = 0;
   strcpy(owner,"Blank");
   color = 0;
   xyspeed = 0;
   freq1 = 0.0;
   freq2 = 0.0;

   nodes.Length = 0;
   numberOfNodes = 0;
   identical = false;

}


void TpPlusTransitLine::printHeader(FILE *ptr, char *s)
{
   fprintf(ptr,"\n\n   Debug Routine Output -- Network: %-40s    \n\n",s);

   fprintf(ptr,"              Line Name                     Mode   Hdwy1   Hdwy2     Nodes-->\n");
   fprintf(ptr," --------------------------------------- ------- ------- -------");
   fprintf(ptr,"     ------------------------------------------------------>\n");

}

void TpPlusTransitLine::printRoute(FILE *ptr)
{
   fprintf(ptr,"%-40s%8d%8.2f%8.2f",name,mode,freq1, freq2);

   if(nodes.Length>0)
   {
      fprintf(ptr," %8d",nodes[0]);

      for(int i=1;i<nodes.Length;++i)
      {
         fprintf(ptr,",%8d",nodes[i]);
      }

      fprintf(ptr,"\n");
   }
   else
   {
      fprintf(ptr," No Nodes\n");
   }

   fflush(ptr);

}

int TpPlusTransitLine::getNumberOfNodes(void)
{
   return(numberOfNodes);
}

bool TpPlusTransitLine::getIdentical(void)
{
   return(identical);
}

float TpPlusTransitLine::getFreq1(void)
{
   return(freq1);
}

float TpPlusTransitLine::getFreq2(void)
{
   return(freq2);
}

int TpPlusTransitLine::getMode(void)
{
   return(mode);
}

char* TpPlusTransitLine::getName(void)
{
   return(name);
}

void TpPlusTransitLine::setMode(int i)
{
   mode = i;
}

void TpPlusTransitLine::setFreq1(float f)
{
   freq1 = f;
}
void TpPlusTransitLine::setFreq2(float f)
{
   freq2 = f;
}

void TpPlusTransitLine::setIdentical(bool b)
{
   identical = b;
}

void TpPlusTransitLine::setName(char *s)
{
   strcpy(name,s);
}

void TpPlusTransitLine::addNode(int i)
{
   nodes.Length++;
   nodes[nodes.Length-1] = i;
   numberOfNodes++;
}

int TpPlusTransitLine::getNode(int k)
{
   if(k>=nodes.Length)
   {
      cout<<"\n\nError in TpPlusTransitLine::getNode --> Call to Node index ("<<k;
      cout<<") greater than number of Nodes ("<<nodes.Length<<")\n";
      cout<<"More Info: Occurred for Line Name="<<this->getName()<<", Mode="<<this->getMode();
      cout<<"\n";
      return(-999999);
   }

   return(nodes[k]);
}

void TpPlusTransitLine::printNodes(FILE *ptr)
{
   for(int k=0;k<numberOfNodes;++k)
   {
      fprintf(ptr,"%8d,",nodes[k]);
   }
}

void TpPlusTransitLine::printFreq1(FILE *ptr)
{
   fprintf(ptr,"%8.2f",freq1);
}

void TpPlusTransitLine::printFreq2(FILE *ptr)
{
   fprintf(ptr,"%8.2f",freq2);
}

void TpPlusTransitLine::printHeadways(FILE *ptr)
{
   fprintf(ptr,"%8.2f,%8.2f",freq1,freq2);
}







//---------------------------------------------------------------------------
#pragma package(smart_init)
