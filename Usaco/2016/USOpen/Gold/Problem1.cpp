#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INT_MIN LLONG_MIN
#define INT_MAX LLONG_MAX

const int MAX_VAL=5E4+3;
int n,r,maxX=LLONG_MIN,maxY=INT_MIN,minX=INT_MAX,minY=INT_MAX,totArea,minVal,maxVal;
multiset<int>st;
struct Cord
{
    int x,y;

    static bool sortByX(Cord a,Cord b)noexcept
    {
        return a.x==b.x?a.y<b.y:a.x<b.x;
    }
    static bool sortByY(Cord a,Cord b)noexcept
    {
        return a.y==b.y?a.x<b.x:a.y<b.y;
    }
}arr[MAX_VAL];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);

    //cout<<"ready"<<endl;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].x>>arr[i].y;
        minX=min(minX,arr[i].x);
        minY=min(minY,arr[i].y);
        maxX=max(maxX,arr[i].x);
        maxY=max(maxY,arr[i].y);
    }
    //cout<<endl;
    
    r=LLONG_MAX,totArea=(maxX-minX)*(maxY-minY);

    //x
    sort(arr,arr+n,Cord::sortByX);
    st.clear();
    minVal=arr[0].y,maxVal=arr[0].y;

    for(int i=0;i<n;i++)
        st.insert(arr[i].y);
    for(int i=0;i<n-1;i++)
    {
        st.erase(st.find(arr[i].y));

        maxVal=max(arr[i].y,maxVal);
        minVal=min(arr[i].y,minVal);

        int areaA=((arr[i].x-arr[0].x))*
            ((maxVal-minVal));
        int areaB=((*st.rbegin()-*st.begin()))*
            ((arr[n-1].x-arr[i+1].x));

        //cout<<areaA<<' '<<areaB<<endl;
        //cout<<"x1: "<<arr[0].x<<" x2: "<<arr[i].x<<" y1: "<<minVal<<" y2: "<<maxVal<<endl;
        //cout<<"x1: "<<arr[i+1].x<<" x2: "<<arr[n-1].x<<" y1: "<<*st.begin()<<" y2: "<<*st.rbegin()<<endl;
        //cout<<endl;

        r=min(r,areaA+areaB);
    }

    //y
    sort(arr,arr+n,Cord::sortByY);
    st.clear();
    minVal=arr[0].x,maxVal=arr[0].x;

    for(int i=0;i<n;i++)
        st.insert(arr[i].x);
    for(int i=0;i<n-1;i++)
    {
        st.erase(st.find(arr[i].x));

        maxVal=max(arr[i].x,maxVal);
        minVal=min(arr[i].x,minVal);

        int areaA=((arr[i].y-arr[0].y))*
            ((maxVal-minVal));
        int areaB=((*st.rbegin()-*st.begin()))*
            ((arr[n-1].y-arr[i+1].y));

        //cout<<areaA<<' '<<areaB<<endl;
        //cout<<"y1: "<<arr[0].y<<" y2: "<<arr[i].y<<" x1: "<<minVal<<" x2: "<<maxVal<<endl;
        //cout<<"y1: "<<arr[i+1].y<<" y2: "<<arr[n-1].y<<" x1: "<<*st.begin()<<" x2: "<<*st.rbegin()<<endl;
        //cout<<endl;
        
        r=min(r,areaA+areaB);
    }

    //cout<<r<<endl;
    cout<<totArea-r<<endl;
    return 0;
}