#include<iostream>

using namespace std;

int partition(int *array,int start,int end){
	int pivot=array[end];
	int cur_place=0;
	int flag=0;
	cur_place=start-1;
	for(int i=start;i<=end-1;i++){
		if(array[i]<=pivot){
			cur_place=cur_place+1;
			int temp=array[cur_place];			
			array[cur_place]=array[i];
			array[i]=temp;
		}
	}
	cur_place=cur_place+1;
	int temp=array[cur_place];			
	array[cur_place]=array[end];
	array[end]=temp;
	return cur_place;
}

void display(int *array,int size){
	for(int i=0;i<=size;i++){
		cout<<" "<<array[i];
	}
	cout<<endl;
}

void quickSort(int *array,int start,int end){
	int p;
	if(start<end){		
		p=partition(array,start,end);		
		cout<<"after partition:"<<start<<" :"<<end;
		display(array,10);
		quickSort(array,start,p-1);
		quickSort(array,p+1,end);
		
	}
}



int main(int argc, char *argv[]){
	int array[]={9,4,3,2,1,6,7,8,4,5,67};
	display(array,10);
	quickSort(array,0,10);
	display(array,10);	
}
