#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define idx first
#define taste second
//#define debug

const int MAX_VAL=2E5+2;
int patchN,karlN,n,karl[MAX_VAL],patchCpy[MAX_VAL],dp[MAX_VAL],r,pfxPatch[MAX_VAL];
pii patch[MAX_VAL];
vector<pii>regions;
multiset<pii>reg1,reg2;

int query(double a,double b)
{
    int p1=lower_bound(patchCpy,patchCpy+patchN,a)-patchCpy;
    int p2=upper_bound(patchCpy,patchCpy+patchN,b)-1-patchCpy;

    return pfxPatch[p2]-(p1==0?0:pfxPatch[p1-1]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    cin>>patchN>>karlN>>n;
    for(int i=0;i<patchN;i++)
        cin>>patch[i].idx>>patch[i].taste;
    for(int i=0;i<karlN;i++)
        cin>>karl[i];
    sort(patch,patch+patchN);
    sort(karl,karl+karlN);
    for(int i=0;i<patchN;i++)
        patchCpy[i]=patch[i].idx;
    for(int i=0;i<patchN;i++)
        pfxPatch[i]=patch[i].taste;
    for(int i=1;i<patchN;i++)
        pfxPatch[i]+=pfxPatch[i-1];


    int ptr=0;
    while(ptr<patchN&&patch[ptr].idx<karl[0])
        ptr++;
    regions.push_back(ptr==0?pii(0,0):pii(
        query(LONG_LONG_MIN,patch[ptr-1].idx),
        query(LONG_LONG_MIN,patch[ptr-1].idx)));

    for(int i=0;i<karlN-1;i++)
    {
        int maxNum=0;

        while(ptr<patchN&&patch[ptr].idx<karl[i+1])
        {
            int dist1=patch[ptr].idx-karl[i];
            int dist2=karl[i+1]-patch[ptr].idx;
            int curMax=0;

            if(dist1==0||dist2==0)
            {
                ptr++;
                continue;
            }

            if(dist1<=dist2)
            {
                double pos=patch[ptr].idx+dist1-0.1;
                curMax=max(curMax,query(
                    (pos+karl[i])/2.0,
                    (pos+karl[i+1])/2.0));
            }
            if(dist1>=dist2)
            {
                double pos=patch[ptr].idx-dist2+0.1;
                curMax=max(curMax,query(
                    (pos+karl[i])/2.0,
                    (pos+karl[i+1])/2.0));
            }

            maxNum=max(curMax,maxNum);
            ptr++;
        }

        regions.push_back(pii(maxNum,0));
    }
    while(ptr<patchN&&patch[ptr].idx==karl[karlN-1])
        ptr++;
    regions.push_back(ptr>=patchN?pii(0,0):pii(
        query(patch[ptr].idx,LONG_LONG_MAX),
        query(patch[ptr].idx,LONG_LONG_MAX)));


    for(int i=1;i<karlN;i++)
        regions[i].second=query(karl[i-1]+0.1,karl[i]-0.1);


    for(int i=0;i<regions.size();i++)
    {
        reg1.insert(regions[i]);
        reg2.insert(pii(regions[i].second,regions[i].first));
    }
    int i=1;
    while(i<n)
    {
        int fst=reg1.rbegin()->first+(--reg1.rbegin())->first;
        int snd=reg2.rbegin()->first;

        if(snd>fst)
        {
            pii lb=*reg2.rbegin();
            pii r1=pii(0,0);
            reg2.erase(reg2.find(lb));
            reg2.insert(r1);
            reg1.erase(reg1.find(pii(lb.second,lb.first)));
            reg1.insert(r1);
            i++;
            r+=snd;
        }
        else
        {
            pii lb=*reg1.rbegin();
            pii r1=pii(lb.second-lb.first,lb.second-lb.first);
            reg1.erase(reg1.find(lb));
            reg2.erase(reg2.find(pii(lb.second,lb.first)));
            reg1.insert(r1);
            reg2.insert(r1);
            r+=lb.first;
        }

        i++;
    }
    if(i<=n)
        r+=reg1.rbegin()->first;


    cout<<r<<endl;
    return 0;
}