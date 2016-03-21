#include<iostream>
#include<string>
using namespace std;

void removeSpace(string str){
    int index=-1;
    for(int i=0;str[i]!='\0';i++){
        if(index!=-1 && str[i]!=' '){
            char temp=str[index];
            str[index]=str[i];
            str[i]=temp;
            index=index+1;
        }
        if(str[i]==' ' and index==-1){
            index=i;
        }               
    }
    str[index]='\0';
    cout<<str<<"\n";
}


int main(int argc, char *argv[]){
    string str="g  eeks   for ge  eeks  ";    
    removeSpace(str);
    return 0;
}
