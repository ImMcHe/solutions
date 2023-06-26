#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define vt vector
#define mtmob getMtmob()

const int MV=100;
string recipie;
int nb,ns,nc,pb,ps,pc,val,nOfb,nOfs,nOfc,nOfBurgers;
bool uselessb,uselessc,uselesss;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>recipie;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>val;

    for(char i:recipie)
    {
        nOfb+=i=='B';
        nOfs+=i=='S';
        nOfc+=i=='C';
    }

    uselessb=nOfb==0;
    uselessc=nOfc==0;
    uselesss=nOfs==0;

    while((nb!=0&&!uselessb)||(nc!=0&&!uselessc)||(ns!=0&&!uselesss))
    {
        if(nb!=0&&!uselessb)
            if(nb<nOfb)
            {
                //cout<<nb<<endl;
                val-=(nOfb-nb)*pb;
                nb=0;
            }
            else
                nb-=nOfb;
        else
            val-=nOfb*pb;
        
        if(nc!=0&&!uselessc)
            if(nc<nOfc)
            {
                //cout<<nc<<endl;
                val-=(nOfc-nc)*pc;
                nc=0;
            }
            else
                nc-=nOfc;
        else
            val-=nOfc*pc;
            
        if(ns!=0&&!uselesss)
            if(ns<nOfs)
            {
                //cout<<ns<<endl;
                val-=(nOfs-ns)*ps;
                ns=0;
            }
            else
                ns-=nOfs;
        else
            val-=nOfs*ps;

        //cout<<nb<<' '<<nc<<' '<<ns<<endl;

        if(val<0)
        {
            cout<<nOfBurgers;
            return 0;
        }
        nOfBurgers++;
    }

    int totalCost=nOfb*pb+nOfc*pc+nOfs*ps;

    //cout<<val<<' '<<totalCost<<endl;

    cout<<nOfBurgers+val/totalCost;
    return 0;
}