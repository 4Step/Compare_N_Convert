//---------------------------------------------------------------------------
#pragma hdrstop

#include "TranPlanTransitLine.h"

TranPlanTransitLine::TranPlanTransitLine(void)
{
   
   initialize();

}



void TranPlanTransitLine::initialize(void)
{
   line = 0;
   company = 0;
   mode = 0;
   headway = 0.0;
   rg = 0;
   nodes.Length = 0;
   strcpy(id,"Blank");
   numberOfNodes = 0;
   identical = false;

}

void TranPlanTransitLine::computeUniqueId(void)
{
   uniqueId = mode*1000+line;

}

void TranPlanTransitLine::printHeader(FILE *ptr, char *s)
{
   fprintf(ptr,"\n\n   Debug Routine Output -- Network: %-40s    \n\n",s);

   fprintf(ptr,"    Line    Comp    Mode  Headwy      Rg     "
               "                 Id Name                       Nodes-->\n");
   fprintf(ptr," ------- ------- ------- ------- -------     "
               "----------------------------------------      -------->\n");

}

void TranPlanTransitLine::printRoute(FILE *ptr)
{
   fprintf(ptr,"%8d%8d%8d%8.1f%8d     %-40s     ",line,company,mode,headway,rg,id);

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



void TranPlanTransitLine::setLine(int i)
{
   this->line=i;
}

int TranPlanTransitLine::getNumberOfNodes(void)
{
   return(numberOfNodes);
}

bool TranPlanTransitLine::getIdentical(void)
{
   return(identical);
}

int TranPlanTransitLine::getLine(void)
{
   return(line);
}

float TranPlanTransitLine::getHeadway(void)
{
   return(headway);
}

int TranPlanTransitLine::getMode(void)
{
   return(mode);
}

void TranPlanTransitLine::setCompany(int i)
{
   company=i;
}

void TranPlanTransitLine::setMode(int i)
{
   mode = i;
}

int TranPlanTransitLine::getUniqueId(void)
{
   return(uniqueId);
}

void TranPlanTransitLine::setHeadway(float f)
{
   headway = f;
}

void TranPlanTransitLine::setIdentical(bool b)
{
   identical = b;
}

void TranPlanTransitLine::setRg(int i)
{
   rg = i;
}

void TranPlanTransitLine::setId(char *s)
{
   strcpy(id,s);
}

void TranPlanTransitLine::addNode(int i)
{
   nodes.Length++;
   nodes[nodes.Length-1] = i;
   numberOfNodes++;
}

int TranPlanTransitLine::getNode(int k)
{
   if(k>=nodes.Length)
   {
      cout<<"\nError in TranPlanTransitLine::getNode --> Call to Node index ("<<k;
      cout<<") greater than number of Nodes ("<<nodes.Length<<")\n";
      cout<<"More Info: Occurred for Line ="<<this->getLine()<<", Mode="<<this->getMode();
      cout<<"\n";
      return(-999999);
   }

   return(nodes[k]);
}

void TranPlanTransitLine::printNodes(FILE *ptr)
{
   for(int k=0;k<numberOfNodes;++k)
   {
      fprintf(ptr,"%8d,",nodes[k]);
   }
}

void TranPlanTransitLine::printHeadway(FILE *ptr)
{
   fprintf(ptr,"%8.2f",headway);
}







//---------------------------------------------------------------------------
#pragma package(smart_init)
