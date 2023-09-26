#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=201;
int n,k,arr[MV],dp[MV][9];

signed main()
{freopen("cbarn2.in","r",stdin);
freopen("cbarn2.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int res=1E9;
    for(int st=0;st<n;st++)
    {
        for(int i=0;i<MV;i++)
            for(int j=0;j<9;j++)
                dp[i][j]=INT_MAX;
        dp[n][0]=0;
        
        for(int i=1;i<=k;i++)
            for(int j=0;j<n;j++)
            {
                int val=0;
                for(int l=j+1;l<=n;l++)
                {
                    val+=arr[l-1]*(l-j-1);
                    dp[j][i]=min(dp[j][i],dp[l][i-1]+val);
                }
            }
        
        res=min(res,dp[0][k]);
        rotate(arr,arr+1,arr+n);
    }
    cout<<res;
}