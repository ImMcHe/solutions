#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=1E5;
int n,m,q,qs[MV];
pii arr[MV];
vector<int>vt;

bool check()
{
    for(int i=0;i<m;i++)
        if(*lower_bound(vt.begin(),vt.end(),arr[i].first)<=arr[i].second&&upper_bound(vt.begin(),vt.end(),arr[i].second)-lower_bound(vt.begin(),vt.end(),arr[i].first)>(arr[i].second-arr[i].first+1)/2)
            return 1;
    return 0;
}

void solve()
{
    vt.clear();
    memset(arr,0,sizeof(arr));
    memset(qs,0,sizeof(qs));

    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>arr[i].first>>arr[i].second,arr[i].first--,arr[i].second--;
    
    cin>>q;
    for(int i=0;i<q;i++)
        cin>>qs[i],qs[i]--;

    // for(int i=0;i<q;i++)
    // {
    //     vt.push_back(qs[i]);
    //     sort(vt.begin(),vt.end());
    //     cout<<check()<<' ';
    // }
    // cout<<endl;
    // vt.clear();

    for(int i=pow(2,1+(int)(log2(n)));i>0;i/=2)
    {
        vector<int>oldArr=vt;
        for(int j=0;j<i&&vt.size()<q;j++)
            vt.push_back(qs[vt.size()]);
        sort(vt.begin(),vt.end());
        // cout<<i<<' '<<vt.size()<<' ';
        if(check())
            vt=oldArr;
        // cout<<vt.size()<<' ';
    }
    // cout<<endl;

    cout<<(vt.size()==q?-1:(int)vt.size()+1)<<endl;
}

signed main()
{
    // freopen("in.txt","r",stdin);

    int t;
    cin>>t;
    while(t--)
        solve();
}