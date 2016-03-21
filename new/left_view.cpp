#include<iostream>
#include<deque>
using namespace std;

typedef struct my_tree{
    int data;
    struct my_tree *left,*right;
}tree;

void printLeftView(tree *root){
    deque<tree *> myq;
    deque<int> level;
    myq.push_back(root);
    level.push_back(1);
    int print_l=-1;
    while(myq.size()!=0){
        tree *temp=myq.front();
        myq.pop_front();
        int l=level.front();
        level.pop_front();
        if(l!=print_l){
            cout<<temp->data<<"\n";
            print_l=l;          
        }        
        if(temp->left!=NULL){
            myq.push_back(temp->left);
            level.push_back(l+1);
        }
        if(temp->right!=NULL){
            myq.push_back(temp->right);
            level.push_back(l+1);
        }
    }        
}

void printLeftView1(tree *root){
    deque<tree *> myq;
    deque<int> level;
    myq.push_back(root);
    while(myq.size()!=0){
        tree *temp=myq.back();
        cout<<temp->data;
        deque<tree *> t_myq;
        while(myq.size()!=0){
            tree *temp=myq.front();            
            myq.pop_front();                               
            if(temp->left!=NULL){
                t_myq.push_back(temp->left);            
            }
            if(temp->right!=NULL){
                t_myq.push_back(temp->right);                
            }
        }       
        myq=t_myq;
    }        
}


int main(int argc, char *argv[]){
    tree *root=NULL;
    tree b,d,c;    
    d.data=10;
    d.left=NULL;
    d.right=NULL;
    c.data=11;
    c.left=NULL;
    c.right=NULL;
    b.data=5;
    b.left=&c;
    b.right=&d;
    root=&b;
    printLeftView1(root);
    return 0;
}
