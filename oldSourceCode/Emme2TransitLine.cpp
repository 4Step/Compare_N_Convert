//---------------------------------------------------------------------------
#pragma hdrstop

#include "Emme2TransitLine.h"

Emme2TransitLine::Emme2TransitLine(void)
{
   initialize();
}

void Emme2TransitLine::initialize(void)
{
   strcpy(shortName,"Blank");
   strcpy(mode,"XX");
   typeOfMode = 0;
   headway = 0.0;
   avgSpeed = 0.0;
   strcpy(longName,"Blank");
   ttf = 0;
   intMode=999;

   Nodes.Length = 0;
   numberOfNodes = 0;
   identical = false;

}


void Emme2TransitLine::printHeader(FILE *ptr, char *s)
{
   fprintf(ptr,"\n\n   Debug Routine Output -- Network: %-40s    \n\n",s);

   fprintf(ptr,"              Line Name                          Mode (#)    Hdwy  AvgSpd   Nodes (characteristics)-->\n");
   fprintf(ptr," -------------------------------------------- ----------- ------- -------");
   fprintf(ptr,"   ------------------------------------------------------>\n");

}

void Emme2TransitLine::printRoute(FILE *ptr)
{

   int counter=0;

   fprintf(ptr,"  %-10s%-38s%-3s(%2d)%8.2f%8.2f",shortName,longName,mode,intMode,headway,avgSpeed);

   if(Nodes.Length>0)
   {
      Nodes[0].printYourself(ptr);

      for(int i=1;i<Nodes.Length;++i)
      {
         fprintf(ptr,",");

         if(counter>100)
         {
            fprintf(ptr,"\n%73s"," ");
            counter = 0;
         }

         Nodes[i].printYourself(ptr);

         counter++;


      }

      fprintf(ptr,"\n");
   }
   else
   {
      fprintf(ptr," No Nodes\n");
   }

   fflush(ptr);

}

void Emme2TransitLine::setNodeDwellTime(int nodeNumber, String dwt)
{
    // add to the last node
    int place = Nodes.Length-1;
    if(place>=0 && place<Nodes.Length)
    {
       Nodes[place].setDwellTime(dwt);
    }
}

void Emme2TransitLine::setNodeTravelTimeFactor(int nodeNumber, String ttf)
{
    // add to the last node
    int place = Nodes.Length-1;
    if(place>=0 && place<Nodes.Length)
    {
       Nodes[place].setTravelTimeFactor(ttf);
    }
}

void Emme2TransitLine::setNodeLayover(int nodeNumber, String lay)
{
    // add to the last node
    int place = Nodes.Length-1;
    if(place>=0 && place<Nodes.Length)
    {
       Nodes[place].setLayover(lay);
    }
}

void Emme2TransitLine::setNodeCongestionFactor(int nodeNumber, String us1)
{
    // add to the last node
    int place = Nodes.Length-1;
    if(place>=0 && place<Nodes.Length)
    {
       Nodes[place].setCongestionFactor(us1);
    }
}

int Emme2TransitLine::getNumberOfNodes(void)
{
   return(numberOfNodes);
}

int Emme2TransitLine::getIntMode(void)
{
   return(intMode);
}

bool Emme2TransitLine::getIdentical(void)
{
   return(identical);
}

float Emme2TransitLine::getHeadway(void)
{
   return(headway);
}

float Emme2TransitLine::getUserAttribute01(void)
{
   return(userAttribute01);
}
float Emme2TransitLine::getUserAttribute02(void)
{
   return(userAttribute02);
}
float Emme2TransitLine::getUserAttribute03(void)
{
   return(userAttribute03);
}

float Emme2TransitLine::getAvgSpeed(void)
{
   return(avgSpeed);
}

char* Emme2TransitLine::getMode(void)
{
   return(mode);
}

char* Emme2TransitLine::getShortName(void)
{
   return(shortName);
}

char* Emme2TransitLine::getLongName(void)
{
   return(longName);
}

void Emme2TransitLine::setMode(char* s)
{
   strcpy(mode,s);
}

void Emme2TransitLine::setHeadway(float h)
{
   headway = h;
}
void Emme2TransitLine::setUserAttribute01(float u)
{
   userAttribute01 = u;
}
void Emme2TransitLine::setUserAttribute02(float u)
{
   userAttribute02 = u;
}
void Emme2TransitLine::setUserAttribute03(float u)
{
   userAttribute03 = u;
}
void Emme2TransitLine::setAvgSpeed(float s)
{
   avgSpeed = s;
}

void Emme2TransitLine::setIdentical(bool b)
{
   identical = b;
}

void Emme2TransitLine::setIntMode(int i)
{
   intMode = i;
}

void Emme2TransitLine::setTypeOfMode(int i)
{
   typeOfMode = i;
}

void Emme2TransitLine::setShortName(char *s)
{
   strcpy(shortName,s);
}

void Emme2TransitLine::setLongName(char *s)
{
   strcpy(longName,s);
}

void Emme2TransitLine::addNode(int i)
{
   Nodes.Length++;

   Emme2TransitNode *tempNode = new Emme2TransitNode(i);
   Nodes[Nodes.Length-1] = *tempNode;

   numberOfNodes++;
}

Emme2TransitNode Emme2TransitLine::getNode(int k)
{
   if(k>=Nodes.Length)
   {
      cout<<"\n\nError in Emme2TransitLine::getNode --> Call to Node index ("<<k;
      cout<<") greater than number of Nodes ("<<Nodes.Length<<")\n";
      cout<<"More Info: Occurred for Line Name="<<this->getShortName()<<this->getLongName();
      cout<<", Mode="<<this->getMode();
      cout<<"\n";
      return(-999999);
   }

   return(Nodes[k]);
}

void Emme2TransitLine::printNodes(FILE *ptr)
{
   for(int k=0;k<numberOfNodes;++k)
   {
      Nodes[k].printYourself(ptr);
   }
}

void Emme2TransitLine::printHeadway(FILE *ptr)
{
   fprintf(ptr,"%8.2f",headway);
}

void Emme2TransitLine::printUserAttribute01(FILE *ptr)
{
   fprintf(ptr,"%8.2f",userAttribute01);
}

void Emme2TransitLine::printUserAttribute02(FILE *ptr)
{
   fprintf(ptr,"%8.2f",userAttribute02);
}

void Emme2TransitLine::printUserAttribute03(FILE *ptr)
{
   fprintf(ptr,"%8.2f",userAttribute03);
}

void Emme2TransitLine::printAvgSpeed(FILE *ptr)
{
   fprintf(ptr,"%8.2f",avgSpeed);
}









//---------------------------------------------------------------------------
#pragma package(smart_init)
