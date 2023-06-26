#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MV=101;
bool dp[MV*1000][MV];
int n,arr[MV];
 
signed main()
{
    ios_base::sync_with_stdio(0);
 
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        dp[0][i]=1;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<MV*1000;j++)
        {
            if(dp[j][i])
                for(int k=i+1;k<n+1;k++)
                    dp[j+arr[i]][k]=1;
        }
    }
 
    set<int>r;
    for(int i=1;i<MV*1000;i++)
        for(int j=0;j<MV;j++)
            if(dp[i][j])
                r.insert(i);
 
    cout<<r.size()<<endl;
    for(int i:r)
        cout<<i<<' ';
    
    return 0;
}