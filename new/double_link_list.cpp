#include<iostream>
#include<stdlib.h>

using namespace std;
class node{
    public:
    node *next,*prev;
    void *data;    
        node(void *d): next(NULL),prev(NULL),data(d)
        {}                
};

class double_link{
    node *start;
    public:
        double_link(): start(NULL)
        {}
        void insert(void *);
        void *removeFromHead();
};

void double_link::insert(void *data){
    if(start==NULL){
        node *n=new node(data);               
        n->next=n;
        n->prev=n;
        start=n;
    }else{
        node* temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        node *n=new node(data);
        temp->next=n;
        n->prev=temp;
        n->next=start;
    }
}

void * double_link::removeFromHead(){
    if(start==NULL){
        return (void *)NULL;
    }else{
        node *temp=start;
        if(start->next!=start){
            start=start->next;
        }else{
            start=NULL;
        }
        return temp->data;
    }
}

int main(int argc,char* argv[]){
    double_link d;
    int x=1;
    double y=1.1;
    char z='c';
    d.insert(&y);
    d.insert(&x);    
    d.insert(&z);
    y=*((double *)d.removeFromHead());
    x=*((int *)d.removeFromHead());
    char c=*((char *)d.removeFromHead());
    cout<<x<<" "<<y<<" "<<c<<"\n";
    return 0;
}
