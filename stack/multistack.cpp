#include<iostream>

using namespace std;

class stack{
	int buffer[20];
	int top;
	public:
	stack(){
		this->top=-1;
	}
	int getTop(){
		return this->top;
	}
	int push(int d){
		if(this->top==19){
			return -1;			
		}else{
			this->top=this->top+1;
			this->buffer[this->top]=d;
			return 0;
		}
	}
	int pop(){
		if(this->top==-1){
			return -1;
		}else{
			int data=this->buffer[this->top];
			this->top=this->top-1;
			return data;
		}
	}
};

class multistack:public stack{
	stack stacks[4];
	int index;
	public:
	multistack();
	void push(int d);
	int pop();
	int popAt(int i);
};

multistack::multistack(){
	this->index=0;
}

void multistack::push(int d){
	if(this->index==4 && this->stacks[this->index].getTop()==19){
		cout<<"All the stacks are full\n";
	}else{
		int retVal=this->stacks[this->index].push(d);
		if(retVal==-1){
			this->index=this->index+1;
			this->stacks[this->index].push(d);
		}		
	}
}

int multistack::pop(){
	if(this->index==0 && this->stacks[this->index].getTop()==-1){
		cout<<"All stack are empty\n";
		return -1;
	}else{
		int retVal=this->stacks[this->index].pop();
		if(retVal==-1){
			this->index=this->index-1;
			retVal=this->stacks[this->index].pop();
			return retVal;
		}
	}
}

int multistack::popAt(int index){
	if(index>this->index){
		cout<<"invalid index!!!\n";
		return -1;
	}
	int retVal=this->stacks[index].pop();
	if(retVal==-1){
		this->index=this->index-1;
		retVal=this->stacks[this->index].pop();
		return retVal;
	}
}

int main(int argc,char *argv[]){
	multistack st;
	
	return 0;
}


