//---------------------------------------------------------------------------
#pragma hdrstop

#include "Emme2TransitNode.h"

Emme2TransitNode::Emme2TransitNode(void)
{
   initialize();
}

Emme2TransitNode::Emme2TransitNode(int passedInNumber)
{
   number = passedInNumber;
}

void Emme2TransitNode::initialize(void)
{
   number = -99999;

}


void Emme2TransitNode::setDwellTime(String dwt)
{
   this->dwellTime = dwt;
}

void Emme2TransitNode::setTravelTimeFactor(String ttf)
{
   this->travelTimeFactor = ttf;
}

void Emme2TransitNode::setLayover(String lay)
{
   this->layover = lay;
}

void Emme2TransitNode::setCongestionFactor(String us1)
{
   this->congestionFactor = us1;
}

int Emme2TransitNode::getNumber(void)
{
   return this->number;
}

String Emme2TransitNode::getDwellTime()
{
   return this->dwellTime;
}

String Emme2TransitNode::getTravelTimeFactor()
{
   return this->travelTimeFactor;
}

String Emme2TransitNode::getLayover()
{
   return this->layover;
}

String Emme2TransitNode::getCongestionFactor()
{
   return this->congestionFactor;
}

bool Emme2TransitNode::isDudeLikeMe(Emme2TransitNode compareNode)
{
   if(this->number!=compareNode.getNumber()) return false;
   if(!this->dwellTime.operator ==(compareNode.getDwellTime())) return false;
   if(!this->travelTimeFactor.operator ==(compareNode.getTravelTimeFactor())) return false;
   if(!this->layover.operator ==(compareNode.getLayover())) return false;
   if(!this->congestionFactor.operator ==(compareNode.getCongestionFactor())) return false;

   return true;

}

void Emme2TransitNode::printYourself(FILE *ptr)
{
   int counter = 0;
   fprintf(ptr,"%8d",this->number);
   if(!dwellTime.IsEmpty())
   {
      if(counter==0) fprintf(ptr,"(");
      fprintf(ptr,"dwt=%s",dwellTime);
      counter++;
   }
   if(!travelTimeFactor.IsEmpty())
   {
      if(counter==0) fprintf(ptr,"(");
      if(counter>0) fprintf(ptr,", ");
      fprintf(ptr,"ttf=%s",travelTimeFactor);
      counter++;
   }
   if(!layover.IsEmpty())
   {
      if(counter==0) fprintf(ptr,"(");
      if(counter>0) fprintf(ptr,", ");
      fprintf(ptr,"lay=%s",layover);
      counter++;
   }
   if(!congestionFactor.IsEmpty())
   {
      if(counter==0) fprintf(ptr,"(");
      if(counter>0) fprintf(ptr,", ");
      fprintf(ptr,"us1=%s",congestionFactor);
      counter++;
   }
   if(counter>0) fprintf(ptr,")");

}







//---------------------------------------------------------------------------
#pragma package(smart_init)
