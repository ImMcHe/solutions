#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define x first
#define y second
 
const int MV=1E6;
int n,k,dp[MV*2+5];
vector<int>coins;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        dp[tmp]=1;
        coins.push_back(tmp);
    }
    
    for(int i=0;i<MV;i++)
    {
        if(dp[i])
        {
            for(int j:coins)
                dp[i+j]=(dp[i+j]+dp[i])%(const int)(1E9+7);
        }
    }
 
    cout<<dp[k];
    return 0;
}
