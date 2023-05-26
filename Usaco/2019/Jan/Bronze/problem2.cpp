#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MAX_VAL=100;
int n,arr[MAX_VAL];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);freopen("sleepy.in","r",stdin);
freopen("sleepy.out","w",stdout);


    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=n-1;i>0;i--)
        if(arr[i-1]>arr[i])
        {
            cout<<i;
            return 0;
        }
    cout<<0;

    return 0;
}