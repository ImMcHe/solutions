#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=0XFFFFF+1;
int n,k,arr[MV],see[MV];
pii lolArr[MV];
bool vsted[MV];
vector<int>ppl[MV];

signed main()
{
    freopen("busin.txt","r",stdin);
    freopen("busout.txt","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>lolArr[i].first,lolArr[i].second=i;
    sort(lolArr,lolArr+n);
    for(int i=0;i<n;i++)
        lolArr[i].first=i+1;
    for(int i=0;i<n;i++)
        arr[lolArr[i].second]=lolArr[i].first;
    for(int i=0;i<k;i++)
        cin>>see[i],see[i]=arr[see[i]-1];

    for(int i=n/2;i>0;i/=2)
    {
        for(int j=0;j<i;j++)
            ppl[arr[j*2]].push_back(arr[j*2+1]),ppl[arr[j*2+1]].push_back(arr[j*2]),arr[j]=max(arr[j*2],arr[j*2+1]);
    }
    // for(int i=1;i<=n;i++)
    //     sort(ppl[i].begin(),ppl[i].end());
    sort(see,see+k);

    // for(int i=0;i<k;i++)
    //     cerr<<see[i]<<' ';
    // cerr<<endl;

    // for(int i=0;i<n-1;i++)
    // {
    //     cerr<<i<<": ";
    //     for(int j:ppl[i])
    //         cerr<<j<<' ';   
    //     cerr<<endl;
    // }
    // cerr<<endl;

    int res=0;

    for(int i=0;i<k;i++)
    {
        if(!vsted[i])
        {
            vsted[i]=1;
            res++;
            for(int j:ppl[see[i]])
                if(binary_search(see,see+k,j)&&!vsted[lower_bound(see,see+k,j)-see])
                {
                    // cerr<<"psBLE!"<<endl;
                    vsted[lower_bound(see,see+k,j)-see]=1;
                    break;
                }
        }
    }
    cout<<res<<endl;
}