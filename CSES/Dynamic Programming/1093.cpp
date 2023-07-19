#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=501,MOD=1E9+7;
int n,totSum,dp[(MV*MV+MV)  ][MV];

signed main()
{
    cin>>n;
    totSum=(n*n+n)/4;

    if((n*n+n)/2%2==1)
    {
        cout<<0;
        return 0;
    }

    dp[0][0]=1;

    for(int j=1;j<=n;j++)
    {
        for(int i=0;i<=totSum;i++)
        {
            dp[i][j]=dp[i][j-1];
            if(i-j>=0)
                dp[i][j]+=dp[i-j][j-1];
            dp[i][j]%=MOD;
        }
    }

    //for(int i=1;i<=totSum;i++)
    {
      //  for(int j=1;j<=n;j++)
        //    cout<<dp[i][j]<<' ';
        //cout<<endl;
    }

    cout<<dp[totSum][n-1];
}