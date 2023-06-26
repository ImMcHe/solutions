#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int n;cin>>n;
    long long tmp=0,r=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int asdf;cin>>asdf;tmp+=asdf;
 
        r=max(tmp,r);
        if(tmp<0)
            tmp=0;
    }
    cout<<r;
}