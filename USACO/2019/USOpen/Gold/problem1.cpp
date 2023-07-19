#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=401;
int n,k,arr[MV],dp[MV][MV];

signed main()
{freopen("snakes.in","r",stdin);
freopen("snakes.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<MV;i++)
        for(int j=0;j<MV;j++)
            dp[i][j]=INT_MAX;
    dp[0][0]=0;
    int curMax=arr[0];
    int sm=0;
    for(int i=0;i<n;i++)
        curMax=max(curMax,arr[i]),sm+=arr[i],dp[i][0]=curMax*(i+1)-sm;

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            int curMax=0;
            int sm=0;

            for(int l=i+1;l<n;l++)
            {
                curMax=max(curMax,arr[l]);
                sm+=arr[l];
                //cout<<curMax<<' '<<sm<<' '<<(curMax*(l-i)-sm)<<'/';
                dp[l][j]=min(dp[l][j],dp[i][j-1]+(curMax*(l-i)-sm));
            }
            //cout<<endl;
        }
    }

    for(int i=0;i<n;i++)
    {
        //for(int j=0;j<=k;j++)
            //cout<<dp[i][j]<<' ';
        //cout<<endl;
    }

    cout<<dp[n-1][k];
}