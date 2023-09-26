#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=1E3;
int n,arr[MV];
int dp[MV][MV];

signed main()
{freopen("taming.in","r",stdin);
freopen("taming.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    for(int i=0;i<n;i++)
        fill(dp[i],dp[i]+MV,1E11);
    dp[0][0]=arr[0]!=0;
    for(int i=1;i<n;i++)
        dp[0][i]=dp[0][i-1]+(arr[i]!=i);
    cout<<dp[0][n-1]<<endl;

    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=0;k<j;k++)
            {
                int sm=0;
                for(int l=k+1;l<=j;l++)
                    sm+=arr[l]!=(l-k-1);
                dp[i][j]=min(dp[i][j],dp[i-1][k]+sm);
            }
        }
        cout<<dp[i][n-1]<<endl;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cerr<<dp[i][j]<<' ';
        cerr<<endl;
    }
}