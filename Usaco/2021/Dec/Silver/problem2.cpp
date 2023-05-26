#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>

const int MAX_VAL=1E5;
int m,n,r;
struct Node
{
    vector<int>nodes;
    bool visited;
    Node(){visited=0;nodes.clear();}
}nodes[MAX_VAL];
vector<set<int>>regions;

int findShortest(int a,int b)
{
    if(regions[a].size()>regions[b].size())
    {
        swap(a,b);
    }

    int minVal=LLONG_MAX;

    for(int i:regions[a])
    {
        auto idx=regions[b].lower_bound(i);
        if(idx==regions[b].begin())
            minVal=min(minVal,abs(*idx-i));
        else if(idx==regions[b].end())
            minVal=min(minVal,abs(*(--idx)-i));
        else
        {
            minVal=min(minVal,abs(*idx-i));
            minVal=min(minVal,abs(*(--idx)-i));
        }
    }

    return minVal;
}

void newReg(int node)
{
    regions.push_back(set<int>());
    queue<int>q;
    q.push(node);
    nodes[node].visited=1;

    while(!q.empty())
    {
        int f=q.front();
        (regions.end()-1)->insert(f);
        q.pop();

        for(int i:nodes[f].nodes)
        {
            if(!nodes[i].visited)
            {
                nodes[i].visited=1;
                q.push(i);
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    //cout<<n<<' '<<m<<endl;
    regions.clear();
    fill(nodes,nodes+n,Node());

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        //cout<<a<<' '<<b<<endl;
        a--;
        b--;
        nodes[a].nodes.push_back(b);
        nodes[b].nodes.push_back(a);
    }
    //cout<<endl;


    for(int i=0;i<n;i++)
    {
        if(!nodes[i].visited)
        {
            newReg(i);
        }
    }


    /*for(auto i:regions)
    {
        for(int j:i)
            cout<<j<<' ';
        cout<<endl;
    }
    cout<<endl;*/

    
    int endRegion=0;
    for(int i=0;i<regions.size();i++)
    {
        if(regions[i].find(n-1)!=regions[i].end())
        {
            endRegion=i;
            break;
        }
    }


    r=findShortest(0,endRegion);
    r*=r;
    //cout<<r<<endl;


    for(int i=1;i<regions.size();i++)
    {
        if(i!=endRegion)
        {
            int s1=findShortest(0,i);
            int s2=findShortest(i,endRegion);
            //cout<<s1<<' '<<s2<<endl;
            r=min(r,s1*s1+s2*s2);
        }
    }
    cout<<r<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);

    int t;
    cin>>t;
    //cout<<"FFF"<<endl;
    for(int i=0;i<t;i++)
    {
        //if(i==17)
        //cout<<"CASE #: "<<t<<endl<<endl<<endl;
        solve();
        //cout<<endl<<endl<<endl;
        /*else
        {
            int a,b;
            cin>>a>>b;
            for(int i=0;i<b;i++)
            {
                int r,s;
                cin>>r>>s;
            }
        }*/
    }

    return 0;
}