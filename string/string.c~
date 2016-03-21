#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverseString(char *str){
	char ch;
	int i,j,len;
	for(i=0;str[i]!='\0';i++);
	len=i;
	i--;
	for(j=0;j<len/2;j++){
		ch=str[j];
		str[j]=str[i];
		str[i]=ch;
		i--;
	}		
}

void checkReverseString(char *str){
	fprintf(stdout,"Original String:%s\n",str);
	reverseString(str);
	fprintf(stdout,"Reversed String:%s\n",str);
}

int find(char ch,char* str1,int *check){
	int i;
	for (i=0;str1[i]!='\0';i++){
		if(str1[i]==ch && check[i]!=1){
			return i;
		}
	}
	return -1;
}

int checkAnagrams(char *str,char *str1){
	int i,j,*check;
	check=(int *)malloc(sizeof(int)*strlen(str1));
	for (i=0;i<strlen(str1);i++){
		check[i]=0;
	}
	if(strlen(str)==strlen(str1)){
		for(i=0;str[i]!='\0';i++){
			j=find(str[i],str1,check);
			if(j==-1 || check[j]==1){
				printf("\nNot Anagrams !!\n");
				return 0;
			}else{
				check[j]=1;
			}
		}
	}else{
		printf("\nNot Anagrams !!!\n");
		return 0;
	}
	printf("\nAnagrams it is !!!\n");
	return 0;
}

char *replaceSpace(char *str){
	int i,count;
	char *str1;
	count=0;	
	for (i=0;i<strlen(str);i++){
		if(str[i]==' '){
			count=count+1;
		}
	}
	str1=(char *)malloc(sizeof(char)*(strlen(str)+(count*3)));
	int j=0;
	for (i=0;i<strlen(str)-1;i++){
		if(str[i]==' '){			
			str1[j]='%';
			str1[j+1]='2';
			str1[j+2]='0';
			j=j+3;	
		}else{
			str1[j]=str[i];
			j=j+1;
		}
		
	}			
	return str1;
}

int main(int argc, char *argv[]){
	char *str;
	str=(char *)malloc(sizeof(argv[1]));
	strcpy(str,argv[1]);
	
	/*Reversing a string using pointers
		checkReverseString(str);
	*/
	/*Check Anagrams for two strings
		checkAnagrams(argv[1],argv[2]);
	*/
	/*Replacing character in a string		
	printf("\nString:%s\n",str);
	str=replaceSpace(str);
	printf("\nString:%s\n",str);
	*/
	return 0;
}
