#include<iostream>
#include<map>
#include<fstream>

using namespace std;

void removeDuplcateLine(ifstream& file1){
	string line;
	map<string,int> hashMap;
	ofstream file2("temp.txt");
	while(getline(file1,line)){
		if(!hashMap[line]){
			hashMap[line]=1;
			file2<<line<<endl;
		}
	}
	file1.close();
	file2.close();
}


int main(int argc,char*argv[]){
	ifstream file1;
	file1.open("temp2.txt");
	removeDuplcateLine(file1);
	return 0;
}


