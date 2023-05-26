#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define dst first
#define same second

const int MAX_VAL=1E5;
int n,m,r;
struct Node
{
    vector<pair<int,bool>>nodes;
    bool type,visited;
}nodes[MAX_VAL];

bool check(int node)
{
    if(nodes[node].visited)
        return 1;
    
    queue<int>q;
    q.push(node);
    while(!q.empty())
    {
        int f=q.front();
        q.pop();

        for(auto i:nodes[f].nodes)
        {
            if(nodes[i.dst].visited)
            {
                //cout<<i.same<<' '<<nodes[i.dst].type<<' '<<nodes[f].type<<endl;
                if(i.same)
                {
                    if(nodes[i.dst].type!=nodes[f].type)
                        return 0;
                }
                else if(nodes[i.dst].type==nodes[f].type)
                    return 0;
            }
            else
            {
                nodes[i.dst].visited=1;
                if(i.same)
                    nodes[i.dst].type=nodes[f].type;
                else
                    nodes[i.dst].type=!nodes[f].type;
                q.push(i.dst);
            }
        }
    }

    r++;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);
freopen("revegetate.in","r",stdin);
freopen("revegetate.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        char ar;
        cin>>ar>>a>>b;a--;
        b--;
        nodes[a].nodes.push_back(make_pair(b,ar=='S'));
        nodes[b].nodes.push_back(make_pair(a,ar=='S'));
    }

    for(int i=0;i<n;i++)
    {
        if(!check(i))
        {
            cout<<0;
            return 0;
        }
    }

    cout<<1;
    for(int i=0;i<r;i++)
        cout<<0;
    cout<<endl;

    return 0;
}