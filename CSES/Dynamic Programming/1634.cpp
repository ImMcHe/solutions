#includebitsstdc++.h
using namespace std;
 
#define int long long
#define pii pairint,int
#define x first
#define y second
 
const int MV=1E6;
int n,k,dp[MV2+5];
vectorintcoins;
 
signed main()
{
    ios_basesync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    fill(dp,dp+MV2+5,INT_MAX);
 
    cinnk;
    for(int i=0;in;i++)
    {
        int tmp;
        cintmp;
        dp[tmp]=1;
        coins.push_back(tmp);
    }
    
    for(int i=0;iMV;i++)
    {
        if(dp[i])
        {
            for(int jcoins)
                dp[i+j]=min(dp[i]+1,dp[i+j]);
        }
    }
 
    cout(dp[k]==INT_MAX-1dp[k]);
    return 0;
}