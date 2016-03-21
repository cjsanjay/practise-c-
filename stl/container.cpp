#include<iostream>
#include<vector>

using namespace std;


void checkVector(){
	vector<int> v;
	vector<int> v1;
	v.push_back(1);
	v.push_back(2);
	v.swap(v1);
	for(int i=0;i<v1.size();i++){
		cout<<v1[i];
	}
}

int main(int argc, char *argv[]){
	checkVector();
}
