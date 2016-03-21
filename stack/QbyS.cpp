#include<iostream>

using namespace std;

class stack{
	int data[10];
	int top;
	public:
		stack();
		void push(int);
		int pop();
		int getTop();
		int peek(int );
};

class queue{
	stack s1,s2;
	public:
		void enq(int);
		int deq();
		void display();
		
};

stack::stack(){
	this->top=-1;			
}

int stack::getTop(){
	return this->top;
}
int stack::peek(int d){
	if(d<=this->top && d>=0){
		return this->data[d];
	}
}

void stack::push(int data){
	if(this->top==10){
		cout<<"Error stack is full"<<endl;		
	}else{
		this->top=this->top+1;
		this->data[this->top]=data;
	}
}



int stack::pop(){
	int data;
	if(this->top==-1){
		cout<<"Stack is empty"<<endl;		
	}else{
		data=this->data[this->top];
		this->top=this->top-1;
		return data;
	}
}

void queue::enq(int data){
	if(this->s1.getTop()==9){
		cout<<"Queue is Full"<<endl;
	}else{
		int temp;
		while(this->s1.getTop()!=-1){
			temp=this->s1.pop();
			this->s2.push(temp);
		}
		this->s1.push(data);
		while(this->s2.getTop()!=-1){
			temp=this->s2.pop();
			this->s1.push(temp);
		}
	}
	
}

int queue::deq(){
	if(this->s1.getTop()==-1){
		cout<<"Queue is empty"<<endl;		
	}else{
		return this->s1.pop();
	}
}

void queue::display(){
	int i=this->s1.getTop();
	while(i>=0){
		cout<<this->s1.peek(i)<<" ";
		i--;
	}
	cout<<endl;
}



int main(int argc,char *argv[]){
	queue q1;
	cout<<"Enq 1 2 3"<<endl;
	q1.enq(1);
	//q1.display();
	q1.enq(2);
	//q1.display();
	q1.enq(3);
	//q1.display();
	cout<<"Deque"<<endl;
	cout<<q1.deq();
	cout<<q1.deq();
	cout<<q1.deq();
	cout<<endl;
	return 0;
}		
