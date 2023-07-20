#include<bits/stdc++.h>
using namespace std;

#define int long long
//#define debug

const int MAX_VAL=1E5+1;
int n,arr[MAX_VAL],arrCpy[MAX_VAL];

int solve()
{
    cin>>n;for(int i=0;i<n;i++)cin>>arr[i];
    int sum=0;for(int i=0;i<n;i++)sum+=arr[i];
    int maxVal=*max_element(arr,arr+n);
    if(sum==0){return 0;}

    vector<int>factors;
    for(int i=1;i<sum;i++)
        if(sum%i==0)factors.push_back(i);
    reverse(factors.begin(),factors.end());
#ifdef debug
cout<<maxVal<<' '<<sum<<endl;
    for(int i:factors)cout<<i<<' ';cout<<endl;
#endif
    for(int i=factors.size()-1;i>=0;i--)
        if(factors[i]<maxVal){
            factors.pop_back();
            #ifdef debug
            cout<<i<<' ';
            #endif
            }
        else
            break;
            #ifdef debug
            cout<<endl;
            #endif
    
    reverse(factors.begin(),factors.end());

#ifdef debug
    for(int i:factors)cout<<i<<' ';cout<<endl;
#endif

    for(int val:factors)
    {
        int r=0;
        copy(arr,arr+n,arrCpy);
        bool isPossible=1;
        for(int i=1;i<n;i++)
        {
            if(arrCpy[i-1]+arrCpy[i]>val&&arrCpy[i-1]!=val){isPossible=0;break;}
            if(arrCpy[i]<val&&arrCpy[i-1]<val)
                arrCpy[i]+=arrCpy[i-1];
            if(arrCpy[i-1]<val)
            r++;
            if(arrCpy[i]>val||arrCpy[i-1]>val)
            {
                isPossible=0;
                break;
            }
            #ifdef debug
                cout<<arrCpy[i]<<' '<<r<<','<<' ';
                #endif
        }
        if(isPossible)
        {
            return r;
        }
    }
    return n-1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);//freopen("in.txt","r",stdin);
    //freopen()
vector<int>stuff;
#ifndef debug
int t;cin>>t;while(t--)
#endif
stuff.push_back(solve());for(int i:stuff)cout<<i<<endl;


    return 0;
}