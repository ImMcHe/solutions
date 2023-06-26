#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define a first.first
#define b first.second
#define w second
#define nodes first
#define vsted second

const int MV=1E5;
int n,m,arr[MV];
pair<pii,int>wh[MV];
pair<vector<int>,bool>nodes[MV];

bool dfs(int node)
{
    queue<int>q;
    q.push(node);
    nodes[node].vsted=1;
    
    vector<int>vst={node},other;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        
        for(int i:nodes[f].nodes)
        {
            if(!nodes[i].vsted)
            {
                q.push(i);
                nodes[i].vsted=1;
                vst.push_back(i);
            }
        }
    }

    for(int i:vst)
        other.push_back(arr[i]-1);

    sort(vst.begin(),vst.end());
    sort(other.begin(),other.end());

    for(int i=0;i<vst.size();i++)
    {
        if(vst[i]!=other[i])
            return 0;
    }
    return 1;
}

bool check(int v)
{
    fill(nodes,nodes+n,pair<vector<int>,bool>({},0));

    for(int i=m-1;i>=v;i--)
    {
        nodes[wh[i].a-1].nodes.push_back(wh[i].b-1);
        nodes[wh[i].b-1].nodes.push_back(wh[i].a-1);
    }

    for(int i=0;i<n;i++)
    {
        if(!nodes[i].vsted&&nodes[i].nodes.size()!=0)
            if(!dfs(i))
                return 0;
    }

    for(int i=0;i<n;i++)
        if(!nodes[i].vsted&&arr[i]!=i+1)
            return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);

  freopen("wormsort.in","r",stdin);
freopen("wormsort.out","w",stdout);
//freopen("in.txt","r",stdin);
 cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++)
        cin>>wh[i].a>>wh[i].b>>wh[i].w;
    int sarr[n];
    copy(arr,arr+n,sarr);
    sort(sarr,sarr+n);
    sort(wh,wh+m,[&](pair<pii,int>f,pair<pii,int>s){return f.w<s.w;});

    bool iss[n];
    for(int i=0;i<n;i++)
        iss[i]=arr[i]!=sarr[i];if(*max_element(iss,iss+n)==0){cout<<-1;return 0;}

    /*for(int i=0;i<m;i++)
        cout<<wh[i].a<<' '<<wh[i].b<<' '<<wh[i].w<<endl;
    cout<<endl;
    cout<<m<<endl;*/

    int l=0,r=m-1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        //cout<<mid<<endl;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    if(check(r))
        cout<<wh[r].w;
    else
        cout<<wh[l].w;

    return 0;
}