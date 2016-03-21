#include <stdio.h>

int main(int argc,char *argv[]){
	int areas[]={10,11,12,13,14};
	char name[]="san";
	char full_name[]={'S','A','N',' ','A','.','s','i','n','g','h','\0'};
	
	printf("size of an int:%d \n",sizeof(int));
	printf("size of areas:%d \n",sizeof(areas));
	printf("The number of ints in areas: %d \n",sizeof(areas)/sizeof(int));
	
	printf("size of a char:%d\n",sizeof(char));
	printf("size of name:%d\n",sizeof(name));
	printf("The number of chars in name: %d\n",sizeof(name)/sizeof(char));
	
	printf("size of full name:%d\n",sizeof(full_name));
	printf("The number of ints in areas: %d\n",sizeof(full_name)/sizeof(char));
	
	return 0;

}
