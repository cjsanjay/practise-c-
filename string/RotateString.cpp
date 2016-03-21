#include<iostream>
using namespace std;

int check(int i,int j,char *str,char *str2){
	int old_i,old_j;
	old_i=i;
	old_j=j;
	for(;str[i]!='\0' && str[j]!='\0';i++,j++){
		if(str[i]!=str2[j]){			
			return 0;
		}
	}
	if(str2[j]=='\0'){
		
		return 0;
	}
	if(str[i]=='\0'){
		for(i=0;i<old_i && str2[j]!='\0';i++,j++){			
				if(str[i]!=str2[j]){					
					return 0;
				}
		}
	}
	if(str2[j]=='\0' && i<old_i){
		return 0;
	}
	if(str2[j]=='\0')
		return 1;
	else
		return 0;
}

void checkRotate(char *str,char *str2){
	int match=-1;
	for(int j=0;str2[j]!='\0';j++){
		for(int i=0;str[i]!='\0';i++){
			if(str[i]==str2[j]){
				if(check(i,j,str,str2)){
					cout << "Equal\n";
					return;				
				}
				
			}
		}
	}
	return;
}

int main(int argc,char* argv[]){

	checkRotate(argv[1],argv[2]);
	return 0;
}
