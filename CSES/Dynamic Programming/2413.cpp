#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MV=1E6,MOD=1E9+7;
int n,dp[MV+1][2];
 
void solve()
{
    cin>>n;
    dp[0][0]=1;
    dp[0][1]=1;
 
    for(int i=0;i<n;i++)
    {
        dp[i+1][0]=(dp[i][0]*4+dp[i][1])%MOD;
        dp[i+1][1]=(dp[i][0]+dp[i][1]*2)%MOD;
    }
 
    cout<<(dp[n-1][0]+dp[n-1][1])%MOD<<endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
 
    int t;
    cin>>t;
    while(t--)
        solve();
 
    return 0;
}