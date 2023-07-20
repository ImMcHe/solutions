#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define oth first
#define r second

const int MV=5E3;
int n,q;
struct Node
{
    bool visited;
    vector<pii>nodes;
}nodes[MV];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
freopen("mootube.in","r",stdin);
freopen("mootube.out","w",stdout);

    cin>>n>>q;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        int r;
        cin>>r;
        nodes[a].nodes.push_back(pii(b,r));
        nodes[b].nodes.push_back(pii(a,r));
    }

    for(int i=0;i<q;i++)
    {
        int k,v;
        cin>>k>>v;
        v--;

        for(int i=0;i<n;i++)
            nodes[i].visited=0;

        int r=0;
        queue<pii>q;
        q.push(pii(v,LLONG_MAX));
        nodes[v].visited=1;

        while(!q.empty())
        {
            pii f=q.front();
            //cout<<f.oth<<endl;
            q.pop();

            r+=f.r>=k;
            
            for(pii i:nodes[f.oth].nodes)
            {
                if(nodes[i.oth].visited)
                    continue;
                nodes[i.oth].visited=1;
                q.push(pii(i.oth,min(i.r,f.r)));
            }
        }cout<<r-1<<endl;
    }

    return 0;
}