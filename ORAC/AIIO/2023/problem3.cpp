#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MV=1E5;
int n,q,arr[MV];
int pfxFwd[MV],pfxBwd[MV];
vector<pii>vt;
pii segTree[MV*4];
 
void buildTree(int l,int r,int idx)
{
    if(l==r)
    {
        segTree[idx]={arr[l],l};
        return;
    }
    int mid=(l+r)/2;
    buildTree(l,mid,idx*2+1);
    buildTree(mid+1,r,idx*2+2);
    segTree[idx]=max(segTree[idx*2+1],segTree[idx*2+2]);
}
pii query(int l,int r,int al,int ar,int idx)
{
    if(l>r)
        return{INT_MIN,INT_MIN};
    int mid=(al+ar)/2;
    //cout<<al<<' '<<ar<<' '<<l<<' '<<r<<' '<<mid<<' '<<idx<<endl;
    if(al==ar)
        return segTree[idx];
    if(l==al&&r==ar)
        return segTree[idx];
    pii mv=max(query(l,min(r,mid),al,mid,idx*2+1),query(max(l,mid+1),r,mid+1,ar,idx*2+2));
    return mv;
}
 
signed main()
{
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>arr[i];
 
    for(int i=0;i<n;i++)
    {
        if(vt.size()==0)
        {
            vt.push_back({arr[i],i});
            continue;
        }
        if(vt[vt.size()-1].first>=arr[i])
        {
            vt.push_back({arr[i],i});
            continue;
        }
 
        pii lst=vt[vt.size()-1];
        vt.pop_back();
        while(vt[vt.size()-1].first<arr[i]&&vt.size()!=0)
        {
            pfxFwd[i]+=(vt[vt.size()-1].first-lst.first)*(i-vt[vt.size()-1].second-1);
            lst=vt[vt.size()-1];
            vt.pop_back();
        }
        if(vt.size()==0)
        {
            vt.push_back({arr[i],i});
            continue;
        }
        pfxFwd[i]+=(arr[i]-lst.first)*(i-vt[vt.size()-1].second-1);
        vt.push_back({arr[i],i});
    }
    vt.clear();
    for(int i=n-1;i>=0;i--)
    {
        if(vt.size()==0)
        {
            vt.push_back({arr[i],i});
            continue;
        }
        if(vt[vt.size()-1].first>=arr[i])
        {
            vt.push_back({arr[i],i});
            continue;
        }
 
        pii lst=vt[vt.size()-1];
        vt.pop_back();
        while(vt[vt.size()-1].first<arr[i]&&vt.size()!=0)
        {
            pfxBwd[i]+=(vt[vt.size()-1].first-lst.first)*(vt[vt.size()-1].second-i-1);
            lst=vt[vt.size()-1];
            vt.pop_back();
        }
        if(vt.size()==0)
        {
            vt.push_back({arr[i],i});
            continue;
        }
        pfxBwd[i]+=(arr[i]-lst.first)*(vt[vt.size()-1].second-i-1);
        vt.push_back({arr[i],i});
    }
 
    for(int i=1;i<n;i++)
        pfxFwd[i]+=pfxFwd[i-1];
    for(int i=n-2;i>=0;i--)
        pfxBwd[i]+=pfxBwd[i+1];
 
    buildTree(0,n-1,0);
 
    // for(int i=0;i<n;i++)
    //     cout<<pfxFwd[i]<<' ';
    // cout<<endl;
    // for(int i=0;i<n;i++)
    //     cout<<pfxBwd[i]<<' ';
    // cout<<endl;
    
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
 
        int peek=query(a,b,0,n-1,0).second;
        //cout<<peek<<endl;
        cout<<(pfxFwd[b]-pfxFwd[peek]+pfxBwd[a]-pfxBwd[peek])<<endl;
    }
}