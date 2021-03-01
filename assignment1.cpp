#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.14159265

using namespace std;

float RandomNumber(float Min, float Max); // use for produce radom number for desired range

int main(){
	
	srand(time(NULL)); // use for different random algorthim
	
	float o1x,o1y,o2x,o2y;
	o1x=RandomNumber(15.0,47.0); // define for first location other 1 and other 2, left and down 0, rigth and up 63
	o1y=RandomNumber(15.0,47.0);
	o2x=RandomNumber(15.0,47.0);
	o2y=RandomNumber(15.0,47.0);
	
	float k1x,k1y,k2x,k2y; // these are determine others location for another time
	
	float r1,r2; // radius for red circle
	
	float theta1,theta2; // theta for red cirle
	
	float yx,yy; // use for you's location
	
	float diso1,diso2,disy; // use for distance calculation
	
	for(int i=0; i<25 ; i++){
	
	r1=RandomNumber(0,4.0);
	r2=RandomNumber(0,4.0);
	
	theta1=RandomNumber(0,360);
	theta2=RandomNumber(0,360);
	
	k1x=r1*cos(theta1*(PI/180));
	k1y=r1*sin(theta1*(PI/180));
	k2x=r1*cos(theta2*(PI/180));
	k2y=r1*sin(theta2*(PI/180));
	
	o1x=o1x+k1x;
	o1y=o1y+k1y;
	o2x=o2x+k2x;
	o2y=o2y+k2y;
	
	while(o1x<15)
	o1x=o1x+(RandomNumber(-4.0,4.0)*cos(RandomNumber(0,360)*(PI/180))); // use for not overflow red square
	
	while(o1y<15)
	o1y=o1y+(RandomNumber(-4.0,4.0)*sin(RandomNumber(0,360)*(PI/180))); // use for not overflow red square
	
	while(o2x<15)
	o2x=o2x+(RandomNumber(-4.0,4.0)*cos(RandomNumber(0,360)*(PI/180))); // use for not overflow red square
	
	while(o2y<15)
	o2y=o2y+(RandomNumber(-4.0,4.0)*sin(RandomNumber(0,360)*(PI/180))); // use for not overflow red square
	
	while(o1x>47)
	o1x=o1x+(RandomNumber(-4.0,4.0)*cos(RandomNumber(0,360)*(PI/180))); // use for not overflow red square
	
	while(o1y>47)
	o1y=o1y+(RandomNumber(-4.0,4.0)*sin(RandomNumber(0,360)*(PI/180))); // use for not overflow red square
	
	while(o2x>47)
	o2x=o2x+(RandomNumber(-4.0,4.0)*cos(RandomNumber(0,360)*(PI/180))); // use for not overflow red square
	
	while(o2y>47)
	o2y=o2y+(RandomNumber(-4.0,4.0)*sin(RandomNumber(0,360)*(PI/180))); // use for not overflow red square
	
	yx=31+(31-o1x)+(31-o2x); // you's location 
	yy=31+(31-o1y)+(31-o2y);	
	
	diso1=sqrt((fabs(31-o1x)*fabs(31-o1x))+(fabs(31-o1y)*fabs(31-o1y))); // others's and you's distance from orgin
	diso2=sqrt((fabs(31-o2x)*fabs(31-o2x))+(fabs(31-o2y)*fabs(31-o2y)));
	disy=sqrt((fabs(31-yx)*fabs(31-yx))+(fabs(31-yy)*fabs(31-yy)));
	
	cout<<"Time="<<i+1<<endl; // print all outputs we need 
	cout<<"other1(x="<<o1x-31<<",y="<<o1y-31<<")"<<" other1's distance from the center="<<diso1<<endl; // convert 0-63 to (-32)-(+32)
	cout<<"other2(x="<<o2x-31<<",y="<<o2y-31<<")"<<" other2's distance from the center="<<diso2<<endl; // convert 0-63 to (-32)-(+32)
	cout<<"you(x="<<yx-31<<",y="<<yy-31<<")"<<" you's distance from the center="<<disy<<"\n"<<endl; // convert 0-63 to (-32)-(+32)
	
	}
}
	float RandomNumber(float Min, float Max) // use for produce radom number for desired range
{
    return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

