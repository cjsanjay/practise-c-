#include<iostream>

using namespace std;


class parkingSpace{
	int type;
	int flag;
	public:
		parkingSpace();
		parkingSpace(int n): type(n)
		{}
		int getType();
		void setFlag(int n);
		int getFlag();
};

class parkingLot{
	parkingSpace *a,*b,*c;
	int free_a,free_b,free_c;
	int avail_a,avail_b,avail_c;
	public:
		parkingLot(int a1,int b1,int c1): free_a(a1), free_b(b1),free_c(c1) ,avail_a(0), avail_b(0) ,avail_c(0)
		{
			a= new parkingSpace[a1];
			b=new parkingSpace[b1];
			c=new parkingSpace[c1];					
		}
		int getFreeParkingSpace(int);
		int assignParkingSpace(int);
		void freeParkingSpace(int type,int n);
};

class guest{
	parkingSpace assigned_space;
	char car_number[20];
	int duration_used;
};


int main(int argc,char *argv[]){
	return 0;
}
