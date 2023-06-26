#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=2E5;
struct Node
{
    bool vst;
    vector<int>nodes;
}nodes[MV];
int n,r[MV];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        nodes[a].nodes.push_back(b);
        nodes[b].nodes.push_back(a);
    }

    queue<pii>q;
    q.push(pii(0,0));
    int furn=0,furd=0;
    nodes[0].vst=1;

    while(!q.empty())
    {
        pii f=q.front();
        q.pop();
        
        for(int i:nodes[f.second].nodes)
        {
            if(nodes[i].vst)
                continue;
            q.push(pii(f.first+1,i));
            nodes[i].vst=1;
            if(f.first+1>furd)
            {
                furd=f.first+1;
                furn=i;
            }
        }
    }

    for(int i=0;i<MV;i++)
        nodes[i].vst=0;

    q.push(pii(0,furn));
    furd=0;
    nodes[furn].vst=1;

    while(!q.empty())
    {
        pii f=q.front();
        q.pop();

        for(int i:nodes[f.second].nodes)
        {
            if(nodes[i].vst)
                continue;
            q.push(pii(f.first+1,i));
            nodes[i].vst=1;
            furd=max(furd,f.first+1);
        }
    }

    cout<<furd;

    return 0;
}