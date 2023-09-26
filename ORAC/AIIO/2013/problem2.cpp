#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=1E5;
struct Node
{
    bool vsted=0;
    vector<pii>paths;
}
cntr[MV];
map<int,Node>city[MV];
int n,m,cntrNodes[MV];

signed main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>cntrNodes[i],cntrNodes[i]--;
    
    int tot=0;
    for(int i=0;i<m;i++)
    {
        int a,b,t;
        cin>>a>>b>>t;
        tot+=t;
        a--,b--;
        if(cntrNodes[a]!=cntrNodes[b])
            cntr[cntrNodes[a]].paths.push_back({cntrNodes[b],t}),
            cntr[cntrNodes[b]].paths.push_back({cntrNodes[a],t});
        else
            city[cntrNodes[a]][a].paths.push_back({b,t}),
            city[cntrNodes[a]][b].paths.push_back({a,t});
    }

    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,*min_element(cntrNodes,cntrNodes+n)});

    int res=0;
    
    while(!q.empty())
    {
        pii f=q.top();
        q.pop();

        //cerr<<f.first<<' '<<f.second<<endl;

        if(cntr[f.second].vsted)
            continue;
        cntr[f.second].vsted=1;
        res+=f.first;

        for(pii i:cntr[f.second].paths)
            if(!cntr[i.first].vsted)
                q.push({i.second,i.first});
    }
    //cerr<<res<<endl<<endl;
    
    for(int i=0;i<n;i++)
    {
        q.push({0,city[cntrNodes[i]].begin()->first});

        while(!q.empty())
        {
            pii f=q.top();
            q.pop();

            if(city[cntrNodes[i]][f.second].vsted)
                continue;
            city[cntrNodes[i]][f.second].vsted=1;
            res+=f.first;

            for(pii j:city[cntrNodes[i]][f.second].paths)
                if(!city[cntrNodes[i]][j.first].vsted)
                    q.push({j.second,j.first});
            //cerr<<f.first<<' '<<f.second<<endl;
        }
    }

    cout<<tot-res;
}