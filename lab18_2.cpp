#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *a,Rect *b){
	double ow,oh;
	if(a->x+a->w > b->x)
		ow = min(a->x+a->w,b->x+b->w)-max(a->x,b->x);
	else
		ow=0; 
	oh = min(a->y,b->y)-max(a->y-a->h,b->y-b->h);
	return ow*oh;	
}

double max(double a,double b){
	if(a>b)
		return a;
	else 
		return b;
}

double min(double a,double b){
	if(a>b)
		return b;
	else 
		return a;
}


int main(){
	Rect R1 = {1,1,5,5};
Rect R2 = {2,2,5,5};	
cout << overlap(&R1,&R2) << "\n";
Rect R3 = {1,1,5,5};
Rect R4 = {7,2,3,3};	
cout << overlap(&R3,&R4) << "\n";
Rect R5 = {-1,2,6.9,9.6};
Rect R6 = {0,0,1.2,2.5};	
cout << overlap(&R5,&R6);	
}
