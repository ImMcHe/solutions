#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=2E5;
int n;
struct Node
{
    vector<int>nodes;
    bool vst;
    int longest;
}nodes[MV];

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

    int furn=0;

    for(int i=0;i<3;i++)
    {
        for(int i=0;i<MV;i++)
            nodes[i].vst=0;
        
        int furd=0;

        queue<pii>q;
        q.push(pii(furn,0));
        nodes[furn].vst=1;

        while(!q.empty())
        {
            pii f=q.front();
            q.pop();
            for(int i:nodes[f.first].nodes)
            {
                if(nodes[i].vst)
                    continue;
                nodes[i].vst=1;
                q.push(pii(i,f.second+1));
                nodes[i].longest=max(nodes[i].longest,f.second+1);

                if(furd<f.second+1)
                {
                    furd=f.second+1;
                    furn=i;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<nodes[i].longest<<' ';
    return 0;
}