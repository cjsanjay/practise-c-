#include<iostream>


using namespace std;

struct listNode{
	struct listNode *next;
	int data,wt;
};

listNode *createNode(int d,int wt){
	listNode *temp=new listNode;
	temp->data=d;
	temp->next=NULL;
	temp->wt=wt;
	return temp;
}

listNode* insertList(listNode *head,listNode *temp1){
	listNode *temp=head;
	if(head==NULL){
		head=temp1;		
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=temp1;
	}
	return head;
}

void dfs(listNode** list,int currentNode,int *visited){
	if(visited[currentNode]!=1){
		cout<<currentNode;
		visited[currentNode]=1;		
		for(listNode* temp=list[currentNode]->next;temp!=NULL;temp=temp->next){
			dfs(list,temp->data,visited);	
		}
	}
}

void initVisit(int *visited,int n){
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
}

int findMin(int *dist,int curNode,int *visited){
	int min=80;
	int min_node=-1;
	for(int i=0;i<10;i++){
		if(dist[i]<min && visited[i]!=1){
			min=dist[i];
			min_node=i;			
		}
	}	
	visited[min_node]=1;
	return min_node;
}

void updateDist(listNode**list, int *dist,int nextNode,int *visited){
	listNode *temp=list[nextNode];
	while(temp!=NULL){
		if(dist[temp->data]>(dist[nextNode]+temp->wt)){
			dist[temp->data]=dist[nextNode]+temp->wt;
			visited[temp->data]=0;
		}
		temp=temp->next;
	}
}

void dijkstra(listNode** list,int start,int end){
	int dist[10];
	int total_cost=0;
	int parent[10];
	int visited[10];
	listNode *temp;
	for(int i=0;i<10;i++){
		dist[i]=99;
		parent[i]=0;
		visited[i]=0;
	}	
	temp=list[start];
	while(temp!=NULL){
		dist[temp->data]=temp->wt;
		temp=temp->next;
	}
	int nextNode,oldNode;
	visited[start]=1;
	nextNode=findMin(dist,start,visited);
	parent[nextNode]=start;
	while(nextNode!=end){				
		if(nextNode!=-1){
			updateDist(list,dist,nextNode,visited);
		}
		oldNode=nextNode;
		nextNode=findMin(dist,oldNode,visited);
		parent[nextNode]=oldNode;
	}
	int v=nextNode;
	total_cost=dist[end];
	while(v!=start){
		cout<<v<<"->";
		v=parent[v];
	}
	cout<<"start"<<endl;
	cout<<total_cost;
}

void graphsUsingAdjacencyList(int n){
	listNode **list;
	listNode *temp=NULL;
	int *visited;
	list= new listNode*[n+1];
	visited=new int[n+1];
	char answer;
	int d,wt;
	for(int i=1;i<=n;i++){		
		cout<<"Enter the data for node "<<i<<endl;
		do{
			cout<<"Enter the data of node for adjacency:";
			cin>>d;
			cout<<"Enter the weight";
			cin>>wt;
			temp=createNode(d,wt);
			list[i]=insertList(list[i],temp);
			cout<<"Enter y to add more:"<<endl;
			cin>>answer;			
		}while(answer=='y');
	}
	//initVisit(visited,n);
	//dfs(list,0,visited);
	int start=1;
	int end=4;
	dijkstra(list,start,end);
}


int main(int argc,char *argv[]){
	int n=argv[1][0]-'0';
	//graphsUsingAdjancencyMatrix(n);
	graphsUsingAdjacencyList(n);
}
