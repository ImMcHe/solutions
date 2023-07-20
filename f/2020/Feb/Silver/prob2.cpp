#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second

//#define debug

const int MOD=1E9+7;
const int MAX_VAL=1E5;
int n,r;
pair<int,int>cords[MAX_VAL];
map<int,vector<int>>xPos,yPos;
map<int,map<int,int>>xPrefixSum;

/*int nChoose2(int n)
{
    n++;
    return(pow(n,2)+n)/2;
}*/

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);freopen("triangles.in","r",stdin);
freopen("triangles.out","w",stdout);


    cin>>n;
    for(int i=0;i<n;i++)
        cin>>cords[i].x>>cords[i].y;

    for(int i=0;i<n;i++)
        xPos[cords[i].y].push_back(cords[i].x),yPos[cords[i].x].push_back(cords[i].y);

    for(auto&i:xPos)
        sort(i.second.begin(),i.second.end());
    for(auto&i:yPos)
        sort(i.second.begin(),i.second.end());

    for(const auto&i:xPos)
    {
        map<int,int>tmpStorage;
        for(int j=1;j<i.second.size();j++)
            tmpStorage[i.second[j-1]]=(i.second[j]-i.second[j-1]);

        for(int j=0;j<tmpStorage.size();j++)
            tmpStorage[i.second[j]]*=(tmpStorage.size()-j);

        for(int j=tmpStorage.size()-2;j>=0;j--)
            tmpStorage[i.second[j]]+=tmpStorage[i.second[j+1]];

        xPrefixSum[i.first]=tmpStorage;
    }

#ifdef debug
    for(auto&i:xPrefixSum){
        cout<<i.first<<": ";
        for(auto&j:i.second)cout<<j.first<<' '<<j.second<<", ";
        cout<<endl;}cout<<endl;
#endif

    for(auto&af:yPos)
    {
        vector<int>pos=af.second;
        int prefixSum=0;
        for(int i=1;i<pos.size();i++)
            prefixSum+=(pos[i]-pos[i-1])*(pos.size()-i);

        for(int i=1;i<pos.size();i++)
        {
            r=(r+prefixSum*xPrefixSum[pos[i-1]][af.first])%MOD;
            #ifdef debug
            cout<<prefixSum<<' '<<xPrefixSum[pos[i-1]][af.first]<<' '<<r<<' '<<pos[i-1]<<' '<<af.first<<endl;
            #endif
            prefixSum-=(pos[i]-pos[i-1])*(pos.size()-i);
        }
    }
        #ifdef debug
        cout<<endl;
        #endif

    for(auto&af:yPos)
    {
        vector<int>pos=af.second;
        int prefixSum=0;
        for(int i=pos.size()-2;i>=0;i--)
            prefixSum+=(pos[i+1]-pos[i])*(i+1);

        for(int i=pos.size()-2;i>=0;i--)
        {
            r=(r+prefixSum*xPrefixSum[pos[i+1]][af.first])%MOD;
            #ifdef debug
            cout<<prefixSum<<' '<<xPrefixSum[pos[i+1]][af.first]<<' '<<r<<' '<<pos[i+1]<<' '<<af.first<<endl;
            #endif
            prefixSum-=(pos[i+1]-pos[i])*(i+1);
        }
    }
        #ifdef debug
        cout<<endl;
        #endif

    for(const auto&i:xPos)
    {
        map<int,int>tmpStorage;
        for(int j=1;j<i.second.size();j++)
            tmpStorage[i.second[j]]=(i.second[j]-i.second[j-1]);

        for(int j=0;j<tmpStorage.size();j++)
            tmpStorage[i.second[j]]*=(j);

        for(int j=1;j<tmpStorage.size();j++)
            tmpStorage[i.second[j]]+=tmpStorage[i.second[j-1]];

#ifdef debug
        for(auto&i:tmpStorage)
            cout<<i.second<<' ';
        cout<<endl;
        #endif

        xPrefixSum[i.first]=tmpStorage;
    }
    #ifdef debug
    cout<<endl;
    #endif

    for(auto&af:yPos)
    {
        vector<int>pos=af.second;
        int prefixSum=0;
        for(int i=1;i<pos.size();i++)
            prefixSum+=(pos[i]-pos[i-1])*(pos.size()-i);

        for(int i=1;i<pos.size();i++)
        {
            r=(r+prefixSum*xPrefixSum[pos[i-1]][af.first])%MOD;
            #ifdef debug
            cout<<prefixSum<<' '<<xPrefixSum[pos[i-1]][af.first]<<' '<<r<<' '<<pos[i-1]<<' '<<af.first<<endl;
            #endif
            prefixSum-=(pos[i]-pos[i-1])*(pos.size()-i);
        }
    }
        #ifdef debug
        cout<<endl;
        #endif

    for(auto&af:yPos)
    {
        vector<int>pos=af.second;
        int prefixSum=0;
        for(int i=pos.size()-2;i>=0;i--)
            prefixSum+=(pos[i+1]-pos[i])*(i+1);

        for(int i=pos.size()-2;i>=0;i--)
        {
            r=(r+prefixSum*xPrefixSum[pos[i+1]][af.first])%MOD;
            #ifdef debug
            cout<<prefixSum<<' '<<xPrefixSum[pos[i+1]][af.first]<<' '<<r<<' '<<pos[i+1]<<' '<<af.first<<endl;
            #endif
            prefixSum-=(pos[i+1]-pos[i])*(i+1);
        }
    }
        #ifdef debug
        cout<<endl;
        #endif

    cout<<r<<endl;
    return 0;
}