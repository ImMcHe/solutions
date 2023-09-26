#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=1E4;
int dp[MV],n,k;
int arr[MV];

signed main()
{
    freopen("teamwork.in","r",stdin);
freopen("teamwork.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // for(int i=0;i<n;i++)
    //     cerr<<arr[i]<<' ';
    // cerr<<endl;

    for(int i=0;i<n;i++)
    {
        int mv=0;
        for(int j=0;j<k;j++)
        {
            if(j+i==n)
                break;
            mv=max(mv,arr[i+j]);
            dp[i+j]=max(dp[i+j],mv*(j+1)+(i==0?0:dp[i-1]));
        }
    }

    cout<<dp[n-1];
}