#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define vt vector
 
const int MV=1E5;
int n,k;
int arr[MV];
int dp[MV+1][22][3];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
freopen("hps.in","r",stdin);
freopen("hps.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        char af;
        cin>>af;
        if(af=='H')
            arr[i]=0;
        if(af=='P')
            arr[i]=1;
        if(af=='S')
            arr[i]=2;
    }
    dp[0][0][arr[0]]=1;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            for(int l=0;l<3;l++)
            {
                dp[i+1][j][l]=max(dp[i][j][l]+(arr[i+1]==l),dp[i+1][j][l]);
                for(int m=0;m<3;m++)
                    dp[i+1][j+1][m]=max(dp[i][j][l]+(arr[i+1]==m),dp[i+1][j+1][m]);
            }
        }
    }

    int r=0;
    for(int i=0;i<k+1;i++)
        for(int j=0;j<3;j++)
            r=max(dp[n-1][i][j],r);

    cout<<r;
    return 0;
}