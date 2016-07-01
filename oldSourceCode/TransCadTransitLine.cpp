//---------------------------------------------------------------------------
#pragma hdrstop

#include "TransCadTransitLine.h"

TransCadTransitLine::TransCadTransitLine(void)
{ 
   initialize();
}

void TransCadTransitLine::initialize(void)
{
   route = 0;
   strcpy(routeName,"Blank");
   mode = 0;
   headway1 = 0;
   headway2 = 0;
   headway3 = 0;
   stopPenalty = 0.0;
   timeFactor = 0.0;
   fare = 0.0;
   
   numberOfNodes = 0;
   nodes.Length = 0;
   
}


void TransCadTransitLine::printHeader(FILE *ptr, char *s)
{
   fprintf(ptr,"\n\n   Debug Routine Output -- Network: %-40s    \n\n",s);

   /*
   fprintf(ptr,"   Route    Mode   Hdwy1   Hdwy2   Hdwy3   StopPen  TimeFact      Fare "
               "  Route Id                  Nodes -------------------------->\n");
   fprintf(ptr," ------- ------- ------- ------- ------- --------- --------- --------- "
               "  ------------------------- -------------------------------->\n");
   */
   fprintf(ptr,"   Route    Mode   Hdwy1   Hdwy2   Hdwy3"
               "  Route Id                  Nodes -------------------------->\n");
   fprintf(ptr," ------- ------- ------- ------- -------"
               "  ------------------------- -------------------------------->\n");

}

void TransCadTransitLine::printRoute(FILE *ptr)
{
   /*
   fprintf(ptr,"%8d%8d%8d%8d%8d%10.3f%10.3f%10.3f   %-20s  ",
                route, mode, headway1, headway2, headway3,
                stopPenalty, timeFactor, fare, routeName);
   */

   fprintf(ptr,"%8d%8d%8d%8d%8d   %-20s  ",
                route, mode, headway1, headway2, headway3,
                routeName);

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



void TransCadTransitLine::setRoute(int i)
{
   this->route=i;
}

void TransCadTransitLine::setRouteName(char *s)
{
   strcpy(routeName,s);
}

int TransCadTransitLine::getNumberOfNodes(void)
{
   return(numberOfNodes);
}

int TransCadTransitLine::getRoute(void)
{
   return(route);
}

int TransCadTransitLine::getHeadway1(void)
{
   return(headway1);
}

int TransCadTransitLine::getHeadway2(void)
{
   return(headway2);
}

int TransCadTransitLine::getHeadway3(void)
{
   return(headway3);
}

int TransCadTransitLine::getMode(void)
{
   return(mode);
}


void TransCadTransitLine::setMode(int i)
{
   mode = i;
}

void TransCadTransitLine::setHeadway1(int i)
{
   headway1 = i;
}

void TransCadTransitLine::setHeadway2(int i)
{
   headway2 = i;
}

void TransCadTransitLine::setHeadway3(int i)
{
   headway3 = i;
}

void TransCadTransitLine::setStopPenalty(float f)
{
   stopPenalty = f;
}

void TransCadTransitLine::setTimeFactor(float f)
{
   timeFactor = f;
}

void TransCadTransitLine::setFare(float f)
{
   fare = f;
}

float TransCadTransitLine::getStopPenalty(void)
{
   return(stopPenalty);
}

bool TransCadTransitLine::getIdentical(void)
{
   return(identical);
}

void TransCadTransitLine::setIdentical(bool b)
{
   identical = b;
}

float TransCadTransitLine::getTimeFactor(void)
{
   return(timeFactor);
}

float TransCadTransitLine::getFare(void)
{
   return(fare);
}

void TransCadTransitLine::addNode(int i)
{
   nodes.Length++;
   nodes[nodes.Length-1] = i;
   numberOfNodes++;
}

int TransCadTransitLine::getNode(int k)
{
   if(k>=nodes.Length)
   {
      cout<<"\nError in TransCadTransitLine::getNode --> Call to Node index ("<<k;
      cout<<") greater than number of Nodes ("<<nodes.Length<<")\n";
      cout<<"More Info: Occurred for Route ="<<this->getRoute()<<", Mode="<<this->getMode();
      cout<<"\n";
      return(-999999);
   }

   return(nodes[k]);
}

void TransCadTransitLine::printNodes(FILE *ptr)
{
   for(int k=0;k<numberOfNodes;++k)
   {
      fprintf(ptr,"%8d,",nodes[k]);
   }
}

void TransCadTransitLine::printHeadways(FILE *ptr)
{
   fprintf(ptr,"%8d, %8d, %8d",headway1, headway2, headway3);
}





//---------------------------------------------------------------------------
#pragma package(smart_init)
