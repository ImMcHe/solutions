#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

const int MV=1E6;
int n,arr[(int)1E5],r;

signed main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    for(int i=1;i<=MV;i++)
    {
        if(arr[n-1]<i)
            break;
        bool isEvenCovered=1;
        int stIdx=0;
        for(int j=MV/i*i;j>0;j-=i)
        {
            if(arr[n-1]<j)
                continue;
            int*lb=lower_bound(arr,arr+n,j);
            int*ub=upper_bound(arr,arr+n,j+i-1);
            // cerr<<(lb-arr+1)<<' '<<(ub-arr+1)<<' '<<i<<' '<<j<<endl;
            if((ub-lb)%2==1&&!stIdx)
            {
                if(*lb/i==1)
                {
                    r+=(ub-lb);
                    break;
                    // cerr<<r<<endl;
                }
                else
                {
                    stIdx=j-i;
                    continue;
                }
            }
            if(stIdx)
            {
                // cerr<<(ub-arr+1)<<' '<<(lb-arr+1)<<' '<<stIdx<<' '<<i<<' '<<j<<endl;
                if((ub-lb)%2!=(j==stIdx))
                {
                    isEvenCovered=0;
                    break;
                }
            }
        }

        if(stIdx&&isEvenCovered)
            r+=(upper_bound(arr,arr+n,stIdx+i*2-1)-lower_bound(arr,arr+n,stIdx+i));
    }

    cout<<r;
}