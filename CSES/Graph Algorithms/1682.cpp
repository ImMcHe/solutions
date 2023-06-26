#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define x first
#define y second
 
 
const int MAX_VAL=1E5+1;
int n,m;
queue<int>visited,looped;
struct Node
{
    vector<int>nodes;
    bool visited,possible,loop;
}nodes[MAX_VAL];
 
void reset()
{
    while(!visited.empty())
    {
        nodes[visited.front()].visited=0;
        visited.pop();
    }
    while(!looped.empty())
    {
        nodes[looped.front()].loop=0;
        looped.pop();
    }
}
bool checkFwd(int node)
{
    stack<int>backTrack;
    backTrack.push(node);
    
    while(!backTrack.empty())
    {
        int f=backTrack.top();
        bool none=1;
        for(int i:nodes[f].nodes)
        {
            if(nodes[i].possible)
            {
                nodes[f].possible=1;
                break;
            }
            if(nodes[i].loop)
            {
                nodes[f].loop=1;
                looped.push(f);
            }
            if(!nodes[i].visited)
            {
                none=0;
                visited.push(i);
                nodes[i].visited=1;
                backTrack.push(i);
            }
        }
        if(none)
            backTrack.pop();
    }
 
    if(nodes[node].possible)
        return 1;
    return 0;
}
int check(int node)
{
    reset();
 
    visited.push(node);
    looped.push(node);
    nodes[node].visited=1;
    nodes[node].loop=1;
 
    bool r=0;
    if(checkFwd(node))
        r=1;
    if(visited.size()==n)
        r=1;
 
    if(r)
    {
        while(!looped.empty())
        {
            nodes[looped.front()].possible=1;
            looped.pop();
        }
        return-1;
    }
    for(int i=0;i<n;i++)
        if(!nodes[i].visited)
            return i;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
 
        nodes[a].nodes.push_back(b);        
    }
 
    for(int i=0;i<n;i++)
    {
        int r=check(i);
        if(r!=-1)
        {
            cout<<"NO\n"<<i+1<<' '<<r+1<<endl;
            return 0;
        }
        nodes[i].possible=1;
    }
 
    cout<<"YES";
    return 0;
}