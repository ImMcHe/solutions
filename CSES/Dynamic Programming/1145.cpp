#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=2E5;
int n,arr[MV],dp[MV],l=1;

signed main()
{
    ios_base::sync_with_stdio(0);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    dp[0]=arr[0];

    for(int i=0;i<n;i++)
    {
        if(arr[i]>dp[l-1])
            dp[l++]=arr[i];
        else
            *lower_bound(dp,dp+l,arr[i])=arr[i];
    }

    cout<<l;
    return 0;
}