#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=1E3;
int n;
pii arr[MV];
#define x first
#define y second
struct Node
{
    vector<int>nodes;
    bool vsted;
};
Node nodes[MV];

bool check(int dist)
{
    for(int i=0;i<MV;i++)
        nodes[i].nodes.clear(),nodes[i].vsted=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j&&dist>=(arr[i].x-arr[j].x)*(arr[i].x-arr[j].x)+(arr[i].y-arr[j].y)*(arr[i].y-arr[j].y))
                nodes[i].nodes.push_back(j);
    
    stack<int>q;
    q.push(0);
    nodes[0].vsted=1;
    while(!q.empty())
    {
        int f=q.top();
        q.pop();
        for(int i:nodes[f].nodes)
            if(!nodes[i].vsted)
                nodes[i].vsted=1,q.push(i);
    }

    for(int i=0;i<n;i++)
        if(!nodes[i].vsted)
            return 0;
    return 1;
}

signed main()
{freopen("moocast.in","r",stdin);
freopen("moocast.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].y;

    // cout<<check(pow(2,32))<<endl;
    // for(int i=0;i<n;i++)
    //     if(!nodes[i].vsted)
    //         cout<<i<<' ';
    // cout<<endl;
    
    int res=0;
    for(int i=pow(2,31);i>0;i/=2)
        if(!check(res+i))
            res+=i;

    cout<<res+1;
}