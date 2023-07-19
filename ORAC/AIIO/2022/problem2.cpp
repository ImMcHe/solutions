#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MV=1E5;
int n,a,b,m;
struct Node
{
    vector<int>nodes;
    int val;
    int mv=INT_MAX;
}
nodes[MV];
 
signed main()
{
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
        cin>>nodes[i].val;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        nodes[a].nodes.push_back(b);
        nodes[b].nodes.push_back(a);
    }
 
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,0});
    nodes[0].mv=0;
 
    while(!q.empty())
    {
        pii f=q.top();
        q.pop();
 
        for(int i:nodes[f.second].nodes)
        {
            if(nodes[i].mv<=nodes[f.second].mv+abs(nodes[f.second].val-nodes[i].val))
                continue;
            nodes[i].mv=nodes[f.second].mv+abs(nodes[f.second].val-nodes[i].val);
            q.push({nodes[i].mv,i});
        }
    }
 
    int r=0;
    for(int i=0;i<n;i++)
        r+=(nodes[i].mv-abs(nodes[i].val-nodes[0].val))/2<=(nodes[i].val>nodes[0].val?b:a)&&
            (nodes[i].mv-abs(nodes[i].val-nodes[0].val))/2+abs(nodes[i].val-nodes[0].val)<=(nodes[i].val>nodes[0].val?a:b),"lmao";
        //cout<<i<<' '<<nodes[i].mv<<' '<<(nodes[i].mv-abs(nodes[i].val-nodes[0].val))/2<<' '<<(nodes[i].mv-abs(nodes[i].val-nodes[0].val))/2+abs(nodes[i].val-nodes[0].val)<<' '<<(nodes[i].val<nodes[0].val?"dec":"inc")<<endl;
    "cout<<endl;";
    cout<<r;
}