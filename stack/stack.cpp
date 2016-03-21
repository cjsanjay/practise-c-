#include<iostream>

using namespace std;

class stack{
	int stack_array[100];
	int top;
	public:
		stack();
		void push(int);
		int pop();
		int isEmpty();
		void display();
};

stack::stack(){
	this->top=-1;
}

void stack::push(int d){
	if(this->top==99){
		cout<<"Stack overflow Pop something !!!\n";
	}else{
		this->top=this->top+1;
		stack_array[top]=d;
	}	
}

int stack::isEmpty(){
	if(this->top==-1){
		return 1;
	}else{
		return 0;
	}
}

int stack::pop(){
	if(this->top==-1){
		cout<<"Stack is empty !!!\n";		
		return -1;
	}else{
		int data=stack_array[this->top];
		this->top=this->top-1;
		return data;
	}
}

void stack::display(){
	for(int i=this->top;i>=0;i--){
		cout<<"\n"<<this->stack_array[i]<<"\n";
	}
}

int main(int argc,char *argv[]){
	stack st;
	int ch,temp;
	cout<<"Choose an operation\n1:Push\n2:Pop\n3:display\n4:Exit:";
	cin>>ch;
	do{
		switch(ch){
			case 1:
					cout<<"Enter the value to be pushed:";
					cin>>temp;
					st.push(temp);
					break;
			case 2: if(!st.isEmpty()){
						temp=st.pop();
						cout<<"Value popped is:"<<temp<<"\n";
					}else{					
						cout<<"Stack is empty\n";
					}
					break;					
			case 3:	st.display();
					break;			
		}
		cout<<"Choose an operation\n1:Push\n2:Pop\n3:display\n4:Exit:";
		cin>>ch;	
	}while(ch!=4);
	return 0;
}
