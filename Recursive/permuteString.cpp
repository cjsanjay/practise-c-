#include<iostream>
#include<vector>
#include<list>

using namespace std;

vector<list<char> >permuteString(vector<char> s,int index){
	vector<list<char> > stringSet;
	if(s.size()==index){
		char s[]={' '};
		list<char >s1(s,s+0); 
		stringSet.push_back(s1);
		return stringSet;
	}else{
		stringSet=permuteString(s,index+1);
		char char_push=s[index];
		vector<list<char> >newSet;
		for(int i=0;i<stringSet.size();i++){
			list<char> temp=stringSet[i];
			if(temp.size()==0){
				temp.insert(temp.begin(),char_push);
				newSet.push_back(temp);
			}else{
				for(int j=0;j<=temp.size();j++){
					list<char> temp2(temp);
					list<char>::iterator it=temp2.begin();
					int k=j;
					while(k>0){
						it++;
						k--;
					}
					temp2.insert(it,char_push);
					newSet.push_back(temp2);
				}
			}
		}
		return newSet;
	}
	return stringSet;
}

int main(int argc,char *argv[]){
	char str[]={'s','a','j','a','y','n'};
	vector<char>s(str,str+6);
	vector<list<char> > stringSet;
	stringSet=permuteString(s,0);
	for(int i=0;i<stringSet.size();i++){
		list<char>::iterator it=stringSet[i].begin();
		for(;it!=stringSet[i].end();it++){
			cout<<*it;
		}
		cout<<endl;	
	}
}
