#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

int n,k,bPos;
const int MAX_VAL=250;
int arr[MAX_VAL],curIdx[MAX_VAL];
pii bot[MAX_VAL];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
freopen("snowboots.in","r",stdin);
freopen("snowboots.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<k;i++)
    {cin>>bot[i].first>>bot[i].second;
    }

    for(int i=0;i<n;i++)
    {
        bool isPrev=0;
        for(int j=bPos;j<k;j++)
        {
            if(bPos==j)
            {
                if(bot[j].second+curIdx[j]<i)
                {
                    bPos++;
                    //cout<<j<<' '<<curIdx[j]<<' '<<i<<endl;
                    continue;
                }
                if(arr[i]<=bot[j].first)
                {
                    curIdx[j]=i;
                    isPrev=1;
                }
            }
            else if(bPos<j)
            {
                if(!isPrev)
                {
                    if(arr[i]<=bot[j].first&&curIdx[j]+bot[j].second>=i)
                    {
                        isPrev=1;
                        curIdx[j]=i;
                    }
                }
                else if(arr[i]<=bot[j].first)
                {
                    curIdx[j]=i;
                    //cout<<' '<<i<<' '<<j<<' '<<arr[i]<<' '<<bot[j].first<<endl;
                }
            }
        }
    }
    
    cout<<bPos<<endl;
    return 0;
}