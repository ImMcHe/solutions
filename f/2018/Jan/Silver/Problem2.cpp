#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX_VAL=1E5+10;
int n,m,r,milkTotal,money=INT_MIN,rentMoney,milkMoney,milkIdx;
int cow[MAX_VAL],rent[MAX_VAL];
struct Milk
{
    int gallon,payment,nonPrefixGallon;
    bool operator<(Milk other)const
    {
        return other.payment<this->payment;
    }
}milk[MAX_VAL];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("rental.in","r",stdin);
    freopen("rental.out","w",stdout);

    cin>>n>>m>>r;   

    for(int i=0;i<n;i++)
    {
        cin>>cow[i];
        milkTotal+=cow[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>milk[i].nonPrefixGallon>>milk[i].payment;
        milk[i].gallon=milk[i].nonPrefixGallon;
        milkMoney+=milk[i].nonPrefixGallon*milk[i].payment;
    }
    //cout<<milkMoney<<"DEBUG\n"<<flush;
    for(int i=0;i<r;i++)
        cin>>rent[i];
    
    sort(rent,rent+r);
    reverse(rent,rent+r);
    sort(milk,milk+m);
    //reverse(milk,milk+m);
    sort(cow,cow+n);

    //cout<<"ORIGINAL MILK TOTAL "<<milkTotal<<endl;

    //for(int i=0;i<m;i++)
    //{
    //    cout<<"COW GALLON "<<milk[i].gallon<<" COW PAYMENT "<<milk[i].payment<<endl;
    //}
    //cout<<endl;

    milkIdx=m-1;
    //cout<<milkMoney<<" Milk mooney"<<endl;

    //cout<<"Mlik MOONEYL "<<milkMoney<<' '<<milkIdx<<" DEBUG"<<endl;;

    for(int i=1;i<m;i++)
        milk[i].gallon+=milk[i-1].gallon;

    while(milkTotal<=milk[milkIdx].gallon&&milkIdx>=0){
        milkMoney-=milk[milkIdx--].nonPrefixGallon*milk[milkIdx+1].payment;}
    //milkMoney+=milk[++milkIdx].nonPrefixGallon*milk[milkIdx].payment;
    milkIdx=min(m-1,milkIdx);
        money=max(money,rentMoney+milkMoney+(milk[milkIdx+1].nonPrefixGallon-milk[milkIdx+1].gallon+milkTotal)*milk[milkIdx+1].payment);
    //cout<<"Mlik MOONEYL "<<milk[milkIdx-1].gallon<<" MILK TOTAL "<<milkTotal<<' '<<milkIdx<<" DEBUG"<<endl;;

    //c//out<<"MILK MOONEY ORIGINAL "<<milkMoney<<endl<<endl;


    for(int i=0;i<min(r,n);i++)
    {
        milkTotal-=cow[i];
        rentMoney+=rent[i];
        
    //cout<<"Mlik GALLLON "<<milk[milkIdx].gallon<<" MILK TOTAL "<<milkTotal<<' '<<milkIdx<<" DEBUG"<<endl;;

    while(milkTotal<=milk[milkIdx].gallon&&milkIdx>=0){
        milkMoney-=milk[milkIdx--].nonPrefixGallon*milk[milkIdx+1].payment;
        /*cout<<milkIdx<<' '<<milk[milkIdx].gallon<<endl;*/}
    //milkMoney+=milk[++milkIdx].nonPrefixGallon*milk[milkIdx].payment;
        milkIdx=min(m-1,milkIdx);
   // cout<<"Mlik GALLON "<<milk[milkIdx].gallon<<" MILK PAYMENT "<<milk[milkIdx].payment<<' '<<milkIdx<<" DEBUG"<<endl;;
    //cout<<"MILK GALLON - MILK TOTAL "<<(milk[milkIdx].nonPrefixGallon-milk[milkIdx].gallon+milkTotal)<<" * payment "<<(milk[milkIdx].nonPrefixGallon-milk[milkIdx].gallon+milkTotal)*milk[milkIdx].payment<<endl;

        //cout<<"mok "<<milkMoney<<" rent "<<rentMoney<<" ggg "<<endl;
        //cout<<endl;

        money=max(money,rentMoney+milkMoney+(milk[milkIdx+1].nonPrefixGallon-milk[milkIdx+1].gallon+milkTotal)*milk[milkIdx+1].payment);
    }

    cout<<money<<endl;
    return 0;
}