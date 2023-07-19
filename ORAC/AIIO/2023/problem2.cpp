#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MV=1E5;
int n,m,g;
struct Node
{
    vector<pii>path;
    bool ground;
    int t=LLONG_MAX,nodeBef=-1;
}
nodes[MV];
 
signed main()
{
    cin>>n>>m>>g;
    for(int i=0;i<g;i++)
    {
        int g;
        cin>>g;
        nodes[g-1].ground=1;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        nodes[a-1].path.push_back({b-1,c});
        nodes[b-1].path.push_back({a-1,c});
    }
    for(int i=0;i<n;i++)
        sort(nodes[i].path.begin(),nodes[i].path.end());
 
    priority_queue<pii,vector<pii>,greater<pii>>cringe;
    for(int i=0;i<n;i++)
        if(nodes[i].ground)
            cringe.push({0,i}),nodes[i].nodeBef=i,nodes[i].t=0;
 
    int res=LLONG_MAX;
    
    while(!cringe.empty())
    {
        pii f=cringe.top();
        cringe.pop();
 
        if(f.first!=nodes[f.second].t)
            continue;
        //cout<<f.second+1<<' '<<f.first<<endl;
 
        for(pii i:nodes[f.second].path)
        {
            if(nodes[i.first].nodeBef==-1)
            {
                cringe.push({i.second+f.first,i.first});
                nodes[i.first].nodeBef=nodes[f.second].nodeBef;
                nodes[i.first].t=f.first+i.second;
                //cout<<"SIT1 ";
            }
            else
            {
                if(nodes[i.first].nodeBef!=nodes[f.second].nodeBef)
                {
                    res=min(res,nodes[f.second].t+nodes[i.first].t+i.second);
                    //cout<<"SIT2 /"<<res<<'/'<<' ';
                }
                if(nodes[i.first].t>f.first+i.second)
                {
                    cringe.push({i.second+f.first,i.first});
                    nodes[i.first].nodeBef=nodes[f.second].nodeBef;
                    nodes[i.first].t=f.first+i.second;
                    //cout<<"SIT3 ";
                }
            }
            //cout<<i.first+1<<','<<i.second<<','<<nodes[i.first].t<<'\n';
        }
    }
 
    cout<<res;
}