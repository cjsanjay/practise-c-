#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person{
	char *name;
	int age;
	int height;
	int weight;
};

struct person *Person_create(char *name, int age, int height,int weight){
	struct person *who=malloc(sizeof(struct person));
	who->name=strdup(name);
	who->age=age;
	who->height=height;
	who->weight=weight;
	
	return who;
}

void Person_destroy(struct person *who){
	free(who->name);
	free(who);
}

void Person_print(struct person *who){
	printf("\nName:%s",who->name);
	printf("\nAge:%d",who->age);
	printf("\nHeight:%d",who->height);
	printf("\nWeight:%d",who->weight);
}

int main(int argc,char *argv[]){
	struct person *joe=Person_create("joe_alex",32,64,140);
	
	struct person *frank=Person_create("frank_alex",20,72,180);
	
	printf("\njoe is at memory location: %p",joe);
	Person_print(joe);
	
	printf("\njoe is at memory location: %p",frank);
	Person_print(frank);		
	
	return 0;

}
