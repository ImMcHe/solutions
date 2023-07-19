#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MV=1E4;
int n,k;
struct Cord
{
    int x,y,idx;
    Cord(){}
    Cord(int x,int y){this->x=x,this->y=y;}
}
arr1[MV];
bool dp[MV+1][1001];
 
signed main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr1[i].x>>arr1[i].y;
 
    for(int i=1;i<=n;i++)
    {
        dp[arr1[i-1].x][i]=1;
        dp[arr1[i-1].y][i]=1;
        for(int j=1;j<=MV;j++)
        {
            dp[j][i]=dp[j][i-1]||dp[j][i];
            if(arr1[i-1].x<j)
                dp[j][i]=dp[j][i]||dp[j-arr1[i-1].x][i-1];
            if(arr1[i-1].y<j)
                dp[j][i]=dp[j][i]||dp[j-arr1[i-1].y][i-1];
        }
    }
 
    int r=0;
    for(int i=1;i<=k;i++)
        if(dp[i][n])
            r=max(i,r);
    cout<<r;
}