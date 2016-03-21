#include <iostream>
#include <iomanip>
using namespace std;

class denomination{
    int pounds,shilling,pence;
    int sh_w,p_w;
    public:
        denomination(): pounds(0),shilling(0),pence(0),sh_w(20),p_w(12)
        {}
        denomination(int p,int s,int po): pounds(p), shilling(s), pence(po)
        {}
        denomination operator +(denomination);
        denomination operator -(denomination);
        double convertToNew();
        void adjust();
};

denomination denomination::operator +(denomination d){
    denomination d1;
    d1.pounds=this->pounds+d.pounds;
    d1.shilling=this->shilling+d.shilling;
    d1.pence=this->pence+d.pence;
    d1.adjust();
    return d1;
}

denomination denomination::operator -(denomination d){
    denomination d1;
    d1.pounds=this->pounds-d.pounds;
    d1.shilling=this->shilling-d.shilling;
    d1.pence=this->pence-d.pence;
    d1.adjust();
    return d1;
}

void denomination::adjust(){
    int temp_add;
    if(this->pence>p_w){
        temp_add=this->pence/p_w;
        this->pence=this->pence%p_w;        
    }
    this->shilling=this->shilling+temp_add;
    if(this->shilling>sh_w){
        temp_add=this->shilling/sh_w;
        this->shilling=this->shilling%sh_w;        
    }
    
}

double denomination::convertToNew()
{
    double val=0.0;
    double total_s=shilling+((double)pence/12);
    total_s=total_s/20;
    return (total_s+pounds);
}
int main(int argc,char *argv[]){
    int po,s,p;
    char ch='.';
    cout<<"Enter the denomination";
    cin>>po>>ch>>s>>ch>>p;
    denomination d(po,s,p);
    cout<<setprecision(3)<<(d+d).convertToNew()<<"\n";
    return 0;
}
