#include<bits/stdc++.h>
using namespace std;

#define int long long
//#define debug

const int MAX_VAL=200001;
int n,q,arr[MAX_VAL],dist[MAX_VAL];
pair<int,int>distFwd[MAX_VAL],distBwd[MAX_VAL];
int pfxFwd[MAX_VAL],pfxBwd[MAX_VAL];

int solveForRight(int idx,int r)
{
    int rIdx=dist[idx]-pfxFwd[idx];
    int lbIdx=lower_bound(distFwd,distFwd+n-1,pair<int,int>(rIdx,-1))-distFwd;
    if(lbIdx<n-2&&distFwd[lbIdx+1].first==rIdx)
        lbIdx++;
        #ifdef debug
    cout<<"IDX: "<<idx<<" DIST: "<<dist[idx]<<' '<<"RIDX: "<<rIdx<<" LBIDX: "<<lbIdx<<" R: "<<r<<endl;
    #endif
    if(lbIdx>=n-1)
        return n-1;
    int minSnd=INT_MAX;
    for(int i=lbIdx;i<n-1;i++)
    {
        minSnd=distFwd[i].second+1<=r?minSnd:min(minSnd,distFwd[i].second);
        #ifdef debug
        cout<<"IDX: "<<distFwd[i].second<<" DIST: "<<distFwd[i].first<<endl;
        #endif
    }
    #ifdef debug
    cout<<endl;
    #endif
        
    return minSnd==INT_MAX?n-1:minSnd;
}
int solveForLeft(int idx,int l)
{
    int rIdx=dist[idx]-pfxBwd[idx];
    int lbIdx=lower_bound(distBwd,distBwd+n-1,pair<int,int>(rIdx,INT_MAX))-distBwd;
        #ifdef debug
    cout<<"IDX: "<<idx<<" DIST: "<<dist[idx]<<' '<<"RIDX: "<<rIdx<<" LBIDX: "<<lbIdx<<" L: "<<l<<endl;
    #endif
    if(lbIdx>=n-1)
        return n-1;
    int maxSnd=INT_MIN;
    for(int i=lbIdx;i<n-1;i++)
    {
        maxSnd=distBwd[i].second+1>=l?maxSnd:max(maxSnd,distBwd[i].second+1);
        #ifdef debug
        cout<<"IDX: "<<distBwd[i].second<<" DIST: "<<distBwd[i].first<<endl;
        #endif
    }
    #ifdef debug
    cout<<endl;
    #endif
        
    return maxSnd==INT_MIN?0:maxSnd;
}

void solve(int idx)
{
    int d=0,l=idx,r=idx;
    while(idx!=0&&idx!=n-1)
    {
        #ifdef debug
        cout<<"DISTR: "<<dist[idx]<<" DISTL: "<<dist[idx-1]<<endl;
        #endif
        if(dist[idx]<dist[idx-1])
            idx=solveForRight(idx-1,r);
        else
            idx=solveForLeft(idx,l);
            #ifdef debug
        cout<<"RESULT: "<<idx<<" L: "<<l<<" R: "<<r<<" D: ";
        #endif
        
        if(idx>r)
            d+=(idx==0?0:pfxFwd[idx-1])-(r==0?0:pfxFwd[l-1]),r=idx;
        if(idx<l)
            d+=(l==0?0:pfxFwd[r-1])-(idx==0?0:pfxFwd[idx-1]),l=idx;
            #ifdef debug
        cout<<d<<endl;
        #endif
    }
    cout<<d+pfxFwd[n-2];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    for(int i=1;i<n;i++)
        dist[i-1]=arr[i]-arr[i-1];
    for(int i=0;i<n-1;i++)
        distFwd[i]=make_pair(dist[i],i);
    for(int i=0;i<n-1;i++)
        distBwd[i]=make_pair(dist[i],i);
    copy(dist,dist+n-1,pfxFwd);
    for(int i=1;i<n-1;i++)
        pfxFwd[i]+=pfxFwd[i-1];
    for(int i=1;i<n-1;i++)
        distFwd[i].first-=pfxFwd[i-1];
    copy(dist,dist+n-1,pfxBwd);
    for(int i=n-2;i>=0;i--)
        pfxBwd[i]+=pfxBwd[i+1];
    for(int i=n-2;i>=0;i--)
        distBwd[i].first-=pfxBwd[i+1];

    #ifdef debug
    cout<<"\nDIST FWD: \n";
    for(int i=0;i<n-1;i++)
        cout<<distFwd[i].first<<' ';
    cout<<endl;
    cout<<"\nPFX FWD: \n";
    for(int i=0;i<n-1;i++)
        cout<<pfxFwd[i]<<' ';
    cout<<endl<<endl;
    cout<<"\nDIST BWD: \n";
    for(int i=0;i<n-1;i++)
        cout<<distBwd[i].first<<' ';
    cout<<endl;
    cout<<"\nPFX BWD: \n";
    for(int i=0;i<n-1;i++)
        cout<<pfxBwd[i]<<' ';
    cout<<endl<<endl<<endl;
    #endif

    sort(distFwd,distFwd+n-1);
    sort(distBwd,distBwd+n-1);
    
    #ifndef debug
    cin>>q;
    #endif

    #ifdef debug
    while(1)
    #else
    for(int i=0;i<q;i++)
    #endif
    {
        int tmp;
        cin>>tmp;
        solve(lower_bound(arr,arr+n,tmp)-arr);
        cout<<endl;
    }

    return 0;
}