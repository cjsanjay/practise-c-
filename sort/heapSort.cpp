#include<iostream>
#include<vector>

using namespace std;

class heap{	
	vector<int> data;
	public:
		void buildHeap(int *arr,int);
		void heapifyUp(int,int);
		void sort(int);
		void display();
		void heapifyDown(int,int);
};

void heap::display(){
	for(int i=0;i<=data.size();i++){
		cout<<" "<<data[i];
	}
	cout<<endl;
}

int getParent(int size){
	return ((size)/2);
}

void heap::heapifyUp(int pos,int size){
	int start,left,right;
	start=getParent(pos-1);
	if(start>=0){
		int largest=start;
		left=start*2+1;
		right=start*2+2;
		if(left<size && data[left]>data[largest]){
			largest=left;
		}
		if(right<size && data[right]>data[largest]){
			largest=right;
		}
		if(largest!=start){
			int temp=data[largest];
			data[largest]=data[start];
			data[start]=temp;
			heapifyUp(start,size);
		}
	}
}

void heap::heapifyDown(int pos,int size){
	int start,left,right;
	start=pos;
	if(start>=0){
		int largest=start;
		left=start*2+1;
		right=start*2+2;
		if(left<size && data[left]>data[largest]){
			largest=left;
		}
		if(right<size && data[right]>data[largest]){
			largest=right;
		}
		if(largest!=start){
			int temp=data[largest];
			data[largest]=data[start];
			data[start]=temp;
			heapifyDown(largest,size);
		}
	}
}

void heap::sort(int size){
	while(size>=1){		
		if(data[0]>data[size]){				
			int temp=data[0];
			data[0]=data[size];
			data[size]=temp;			
			cout<<"After Swap:";
			display();
			heapifyDown(0,size);
			cout<<"After adjust down:";
			display();
		}
		size--;		
	}
}
void heap::buildHeap(int *arr,int size){
	for(int i=0;i<size;i++){
		data.push_back(arr[i]);
		heapifyUp(i,data.size());
		display();
	}
}

int main(int argc,char *argv[]){
	int arr[]={-3,78,11,6,4,5,9,8,0,9,17,19,23};
	heap h1;
	h1.buildHeap(arr,13);	
	h1.display();
	h1.sort(13);	
}
