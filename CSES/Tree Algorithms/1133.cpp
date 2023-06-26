#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define node first
#define nodeCount second 

const int MV=2E5;
int n;
struct Node
{
    vector<pii>paths;
    int dpth,sum;
    bool vst;
}nodes[MV];

void printTreeV1(int depth,int node)
{
    //cout<<node<<endl;
    //cout<<nodes[node].paths.size()<<endl;
    nodes[node].vst=1;
        for(int j=0;j<depth;j++)
            cout<<' ';
        cout<<node<<' '<<nodes[node].sum<<endl;
    for(pii i:nodes[node].paths)
    {
        if(nodes[i.node].vst)
            continue;
        nodes[i.node].vst=1;
        printTreeV1(depth+1,i.node);
    }
}
void printTreeV2()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<endl;
        for(pii i:nodes[i].paths)
        {
            cout<<' '<<i.first<<' '<<i.second<<endl;
        }
        cout<<endl;
    }
}

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
        nodes[a].paths.push_back(pii(b,0));
        nodes[b].paths.push_back(pii(a,0));
    }

    {
    stack<pair<int,pii>>q;
    q.push(make_pair(0,pii(0,1)));

    #define times second.first
    #define depth second.second

    while(!q.empty())
    {
        auto&f=q.top();
        nodes[f.node].dpth=f.depth;

        //cout<<f.node<<' '<<f.depth<<' '<<f.times<<endl;

        if(f.times!=0)
        {
            int othNode=nodes[f.node].paths[f.times-1].node;
            //cout<<f.times-1<<' '<<f.node<<' '<<f.depth
            //<<' '<<othNode<<' '<<nodes[othNode].dpth<<endl;
            if(nodes[othNode].dpth>f.depth)
            {
                int s=0;
                for(pii i:nodes[othNode].paths)
                    if(i.node!=f.node)
                        s+=i.nodeCount;
                //cout<<"AF"<<endl;
                nodes[f.node].paths[f.times-1].nodeCount+=s+1;
            }
        }
        if(f.times==nodes[f.node].paths.size())
        {
            q.pop();
            continue;
        }
        if(nodes[nodes[f.node].paths[f.times].node].dpth<f.depth&&
            nodes[nodes[f.node].paths[f.times].node].dpth)
        {
            f.times++;
            continue;
        }

        q.push(make_pair(nodes[f.node].paths[f.times].node,pii(0,f.depth+1)));
        f.times++;
    }
    }//cout<<endl;

    //printTree(0,0);

    for(int i=0;i<n;i++)
    {
        int s=0;
        for(pii j:nodes[i].paths)
        {
            s+=j.nodeCount;
        }
        for(pii&j:nodes[i].paths)
        {
            if(!j.nodeCount)
                j.nodeCount=n-s-1;
        }
    }

    //printTreeV2();

    {
    stack<pair<int,bool>>q;
    q.push(pii(0,0));

    #define vsted second

    while(!q.empty())
    {
        auto&f=q.top();
        if(f.vsted)
        {
            for(pii i:nodes[f.node].paths)
                if(nodes[i.node].dpth>nodes[f.node].dpth)
                    nodes[f.node].sum+=nodes[i.node].sum+i.nodeCount;
            q.pop();
            continue;
        }

        for(pii i:nodes[f.node].paths)
            if(nodes[f.node].dpth<nodes[i.node].dpth)
                q.push(pair<int,bool>(i.node,0));
        f.vsted=1;
    }
    }    

    //printTreeV1(0,0);

    stack<int>q;
    q.push(0);

    while(!q.empty())
    {
        int f=q.top();
        q.pop();

        for(pii i:nodes[f].paths)
            if(nodes[i.node].dpth>nodes[f].dpth)
            {
                nodes[i.node].sum=nodes[f].sum-i.nodeCount;
                for(pii j:nodes[i.node].paths)
                    if(f==j.node)
                        nodes[i.node].sum+=j.nodeCount;
                
                q.push(i.node);
            }
    }

    for(int i=0;i<n;i++)
        cout<<nodes[i].sum<<' ';
    return 0;
}