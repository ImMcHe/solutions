#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define x first
#define y second


const int MAX_VAL=1E5+1;
struct Node
{
    vector<int>nodes;
    pii pos;
    bool visited;
};
Node nodes[MAX_VAL];
int n,m,r=LLONG_MAX;
vector<pair<pii,pii>>bondaries;

void check(int node)
{
    queue<int>q;
    q.push(node);
    nodes[node].visited=1;

    pair<pii,pii>bounds=make_pair(nodes[node].pos,nodes[node].pos); 

    bool isMooNetwork=0;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();

        for(int i:nodes[f].nodes)
        {
            if(!nodes[i].visited)
            {
                nodes[i].visited=1;
                q.push(i);
                bounds.first.x=max(nodes[i].pos.x,bounds.first.x);
                bounds.first.y=max(nodes[i].pos.y,bounds.first.y);
                bounds.second.x=min(nodes[i].pos.x,bounds.second.x);
                bounds.second.y=min(nodes[i].pos.y,bounds.second.y);
            }
        }

        if(!q.empty()&&isMooNetwork==0)
            isMooNetwork=1;
    }

    if(isMooNetwork)
        bondaries.push_back(bounds);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
freopen("fenceplan.in","r",stdin);
freopen("fenceplan.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>nodes[i].pos.x>>nodes[i].pos.y;
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        nodes[b].nodes.push_back(a);
        nodes[a].nodes.push_back(b);
    }

    for(int i=0;i<n;i++)
    {
        if(!nodes[i].visited)
            check(i);
    }

    for(auto i:bondaries)
    {
        r=min(abs(i.first.x-i.second.x)+abs(i.first.y-i.second.y),r);
    }

    cout<<r*2;
    return 0;
}