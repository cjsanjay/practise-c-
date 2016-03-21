#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};


struct Database{
	struct Address rows[MAX_ROWS];
};

struct Connection{
	FILE *file;
	struct Database *db;
};

void die(const char *message){
	if(errno){
		perror(message);
	}else{
		printf("Error: %s\n",message);
	}
	exit(1);
}

void Address_print(struct Address *addr){
	printf("%d %s %s\n",addr->id,addr->name,addr->email);
}

void Database_load(struct Connection *conn){
	

}
