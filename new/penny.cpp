#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

class fraction{
    int num,denom;
    public :
        fraction();
        fraction(int a,int b);
        fraction operator +(fraction);
        fraction operator -(fraction);
        fraction operator *(fraction);
        fraction operator /(fraction);
        bool operator !=(fraction);
        bool operator <(fraction);
        friend ostream& operator <<(ostream& os, const fraction &f);
        friend istream& operator >>(istream& os, fraction &f);
        void reduceToSim();
};

fraction::fraction(){
    this->num=0;
    this->denom=1;
}

fraction::fraction(int a,int b){
    this->num=a;
    this->denom=b;
}


bool fraction::operator <(fraction f){
    float val1=(float)this->num/this->denom;
    float val2=(float)f.num/f.denom;
    if(val1<val2){
        return true;
    }else{
        return false;
    }    
}

bool fraction::operator !=(fraction f){
    if(this->num==f.num && this->denom==f.denom){
        return false;
    }else{
        return true;
    }
}
void fraction::reduceToSim(){
    int gcd=denom;
    int t_num=labs(num);
    int t_denom=labs(denom);
    while(t_num!=0){
        if(t_num<t_denom){
            int temp=t_num;
            t_num=t_denom;
            t_denom=temp;
        }
        t_num=t_num-t_denom;
    }
    gcd=t_denom;
    num=num/gcd;
    denom=denom/gcd;
}

ostream& operator <<(ostream& os, const fraction &f){
    os<<f.num<<"/"<<f.denom;
    return os;
}

istream& operator >>(istream& is,fraction &f){
    char c;
    is>>f.num>>c>>f.denom;
    return is;
}

fraction fraction:: operator +(fraction f){
    int num=(this->num*f.denom+this->denom*f.num);
    int denom=(this->denom*f.denom);
    return fraction(num,denom);
}

fraction fraction:: operator -(fraction f){
    int num=(this->num*f.denom-this->denom*f.num);
    int denom=(this->denom*f.denom);
    return fraction(num,denom);
}

fraction fraction:: operator *(fraction f){
    int num=(this->num*f.num);
    int denom=(this->denom*f.denom);
    return fraction(num,denom);
}

fraction fraction:: operator /(fraction f){
    int num=(this->num*f.denom);
    int denom=(this->denom*f.num);
    return fraction(num,denom);
}

int main(int argc,char *argv[]){
    int denom;
    char c;
    vector<fraction> f;
    cout<<"Enter the denominator:";
    cin>>denom;
    fraction temp(1,denom),temp1(1,1),temp2(1,denom);
    while(temp<temp1){
        f.push_back(temp);
        temp=temp+temp2;
        temp.reduceToSim();        
    }
    cout<<"\t";
    for(int i=0;i<f.size();i++){
        cout<<f[i]<<"\t";
    }
    cout<<"\n";
    for(int i=0;i<f.size();i++){
        cout<<f[i];
        for(int j=0;j<f.size();j++){
            fraction f1=f[i]*f[j];
            f1.reduceToSim();
            cout<<"\t"<<f1;
        }
        cout<<"\n";
    }
}


/*
old logic involves parsing and processing
double fAdd(int num1a,int num1b,int num2a,int num2b){
    int num=(num1a*num2b+num1b*num2a);
    int denom=(num1b*num2b);
    return (double)num/denom;
}

double fSub(int num1a,int num1b,int num2a,int num2b){
    int num=(num1a*num2b-num1b*num2a);
    int denom=(num1b*num2b);
    return (double)num/denom;
}

double fMul(int num1a,int num1b,int num2a,int num2b){
    int num=(num1a*num2a);
    int denom=(num1b*num2b);
    return (double)num/denom;
}

double fDiv(int num1a,int num1b,int num2a,int num2b){
    int num=(num1a*num2b);
    int denom=(num1b*num2a);
    return (double)num/denom;
}




void getNumbers(string s1,int *data){    
    string temp="";
    for(int i=0;i<s1.length();i++){
        if(s1[i]!='/'){            
            temp+=s1[i];
        }else{            
            istringstream(temp)>>data[0];
            temp="";
        }
                
    }
    istringstream(temp)>>data[1];   
}

double parseAndGetSum(string s1,string s2){   
    int *num1,*num2;
    num1=new int[2];
    num2=new int[2];
    getNumbers(s1,num1);
    getNumbers(s2,num2);
    return getSum(num1[0],num1[1],num2[0],num2[1]);    
}
*/

