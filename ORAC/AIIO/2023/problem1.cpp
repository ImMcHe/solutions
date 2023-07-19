#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int MV=1E5;
int n,m,arr[MV];
pii ch[MV];
vector<pii>oth;
int dp[MV];
 
signed main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++)
        cin>>ch[i].first>>ch[i].second,ch[i].first--,ch[i].second--;
    sort(ch,ch+m);
    oth.push_back(ch[0]);
    // cout<<endl;
 
    // for(int i=0;i<m;i++)
    //     cout<<ch[i].first<<' '<<ch[i].second<<endl;
 
    for(int i=1;i<m;i++)
    {
        pii&lst=*--oth.end();
        if(lst.second>=ch[i].second)
            continue;
        if(lst.first==ch[i].first)
        {
            lst.second=ch[i].second;
            continue;
        }
        oth.push_back(ch[i]);
    }
 
    m=oth.size();
    oth.push_back({n,n});
    int mi=0;
 
    for(int i=0;i<n;i++)
    {
        if(i!=0)
            dp[i]=dp[i-1];
        if(oth[mi].first>i)
            dp[i]=dp[i-1]+arr[i];
        else
            dp[i]=max(dp[i],oth[mi].first==0?arr[i]:dp[oth[mi].first-1]+arr[i]);
 
        if(oth[mi].second==i)
            mi++;
    }
 
    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<' ';
    // cout<<endl;
    cout<<dp[n-1];
}