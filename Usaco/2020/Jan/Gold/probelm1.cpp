#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define vt vector
 
const int MV=1000;
int n,m,c,dp[MV][MV*2+1];
struct Node
{
    int val;
    vt<int>nodes;
}nodes[MV];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
freopen("time.in","r",stdin);
freopen("time.out","w",stdout);

    cin>>n>>m>>c;
    for(int i=0;i<n;i++)
        cin>>nodes[i].val;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        nodes[a-1].nodes.push_back(b-1);
    }

    for(int i=0;i<n;i++)
        fill(dp[i],dp[i]+MV*2+1,LONG_MIN);
    dp[0][0]=0;

    for(int i=0;i<MV*2;i++)
    {
        for(int j=0;j<n;j++)
        {
            //bool isBig=0;
            for(int k:nodes[j].nodes)
            {
                dp[k][i+1]=max(dp[k][i+1],dp[j][i]+nodes[k].val);
                //if(dp[k][i+1]-c*i*i>=0)
                //{
                    //cout<<dp[k][i+1]<<','<<c*i*i<<','<<k<<' ';
                    //isBig=1;
                //}
            }
            //if(isBig)
            //    cout<<endl;
        }
    //cout<<i<<endl;
    }

    int r=INT_MIN;
    for(int i=1;i<MV*2;i++)
        if(dp[0][i]>=0)
        {
            r=max(r,dp[0][i]-c*i*i);
            //cout<<dp[0][i]<<','<<c*(i-1)*(i-1)<<endl;
        }
    cout<<r<<endl;
    return 0;
}