#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MV=1E5;
int n;
struct Fab
{
    int val;
    vector<int>nodes;
    int vsted;
}
arr[MV];
 
signed main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i].val;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        arr[a].nodes.push_back(b);
        arr[b].nodes.push_back(a);
    }
 
    {
    stack<pii>q;
    q.push(pii(0,0));
    arr[0].vsted=1;
 
    while(!q.empty())
    {
        pii f=q.top();
        q.pop();
        if(f.second)
        {
            arr[f.first].vsted=1;
 
            for(int i:arr[f.first].nodes)
                if(arr[i].vsted==1)
                    arr[f.first].val+=arr[i].val<0?0:arr[i].val;
            continue;
        }
        arr[f.first].vsted=2;
        q.push(pii(f.first,1));
 
        for(int i:arr[f.first].nodes)
            if(!arr[i].vsted)
                q.push(pii(i,0));
    }
    }
 
    int r=INT_MIN;
    for(int i=0;i<n;i++)
        r=max(r,arr[i].val);
    cout<<r;
}