#include<iostream>
using namespace std;

class node{	
	public:
		node *next;
		int data;
		node(int);	
		
	
};

node::node(int d)
{
		this->data=d;
		this->next=NULL;
}

class LinkList{
	node *head,*tail;
	public:
	LinkList();
	void display();
	void insert(node *);
	void removeDuplicate();
};

LinkList::LinkList(){
		this->head=NULL;
		this->tail=NULL;
}

void LinkList::display(){
		node *temp;
		temp=this->head;
		while(temp->next!=NULL){
			cout << temp->data <<" ->";
			temp=temp->next;
		}
		cout << temp->data<<"\n";
}	

void LinkList::insert(node *d){
		if(head==NULL){
			this->head=d;
			this->tail=d;
		}else{
			(this->tail)->next=d;
			this->tail=(this->tail)->next;
			this->tail->next=NULL;
		}
}

node *sortInsert(node *temp,node *head){
	node *temp2;
	temp2=head;
	if(head==NULL){
		head=temp;
		temp->next=NULL;
		return head;
	}else{
		while(temp2->next!=NULL){
			if(temp->data==temp2->data){
				return head;
			}
			temp2=temp2->next;
		}
		temp2->next=temp;
		temp->next=NULL;
		return head;
	}
}

void LinkList::removeDuplicate(){
	node *temp=this->head;
	node *temp2=NULL;
	node *head2=NULL;
	node *duplicate=NULL;
	while(temp->next!=NULL){
		temp2=temp->next;
		head2=sortInsert(temp,head2);
		temp=temp2;
	}
	this->head=head2;
	temp=head2;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	this->tail=temp;
}

int main(int argc,char *argv[]){
		
	LinkList l;
	int choice=0;
	int count=1;
	cout <<"Enter your choice\n1:insert\n2:Display\n3:Exit\n4:Remove Duplicate\n5:Specific Insert\n";
	cin>>choice;
	do{
		
		switch(choice){
			case 1:
				l.insert(new node(count++));
				break;
			case 2:
				l.display();
				break;
			case 5:
				int check;
				cout<<"Enter the node to be inserted:\n";
				cin>>check;
				l.insert(new node(check));
				break;
			case 4:
				l.removeDuplicate();
				break;
				
		}		
		cout <<"Enter your choice\n1:insert\n2:Display\n3:Exit\n4:Remove Duplicate\n5:Specific Insert\n";
		cin>>choice;
	}while(choice!=3);
	
	return 0;
}
