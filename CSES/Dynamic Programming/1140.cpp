#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=2E5*2+1;
int n,cords[MV],dp[MV],cordLen;
struct Af
{
    int a,b,p;
    Af(int a,int b){this->a=a;this->b=b;}
    Af(){}
}pos[MV];
set<int>cps;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>pos[i].a>>pos[i].b>>pos[i].p;
    
    for(int i=0;i<n;i++)
        cps.insert(pos[i].a),cps.insert(pos[i].b);
    
    copy(cps.begin(),cps.end(),cords);
    cordLen=cps.size();

    for(int i=0;i<n;i++)
        pos[i].a=lower_bound(cords,cords+cordLen,pos[i].a)-cords,
        pos[i].b=lower_bound(cords,cords+cordLen,pos[i].b)-cords;
    sort(pos,pos+n,[&](Af a,Af b){return a.a<b.a;});

    for(int i=0;i<n;i++)
    {
        //cout<<pos[i].a<<' '<<pos[i].b<<' '<<pos[i].p<<endl;
    }

    for(int i=0;i<cordLen;i++)
    {
        dp[i+1]=max(dp[i],dp[i+1]);
        if((lower_bound(pos,pos+n,Af(i,-69420),[&](Af a,Af b){return a.a<b.a;}))->a!=i)
            continue;
        Af*it1=lower_bound(pos,pos+n,Af(i,-69420),[&](Af a,Af b){return a.a<b.a;})-1;
        Af*it2=upper_bound(pos,pos+n,Af(i,INT_MAX),[&](Af a,Af b){return a.a<b.a;});
        //cout<<it1->a<<' '<<it2->a<<endl;
        while(++it1!=it2)
        {
            //cout<<it1->a<<' '<<it1->b<<' '<<it1->p<<endl;
            dp[it1->b+1]=max(dp[(*it1).b+1],dp[i]+pos[it1-pos].p);
        }
        //cout<<dp[i]<<endl;
        //cout<<endl;
    }
    //cout<<endl;

    //for(int i=0;i<cordLen;i++)
    //    cout<<dp[i]<<' ';
    //cout<<endl;

    cout<<dp[cordLen];
    return 0;
}