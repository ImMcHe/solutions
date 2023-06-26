#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define x first
#define y second
 
const int MV=1E6;
int n,dp[MV+10];
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    dp[0]=1;
 
    cin>>n;
    for(int i=0;i<=MV;i++)
    {
        for(int j=1;j<=6;j++)
            dp[i+j]=(dp[i+j]+dp[i])%(const int)(1E9+7);
    }
 
    cout<<dp[n];
    return 0;
}