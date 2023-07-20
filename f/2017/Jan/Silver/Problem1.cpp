//#include"MyTemplate.h"
#ifndef __MY_TEMPLATE_H__
#define __MY_TEMPLATE_H__
#include<bits/stdc++.h>

//#include"Graph.h" --->
#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<vector>
#include<map>
#include<queue>
#include<functional>

template<typename _Ty>
struct Path
{
	_Ty to;
	int len;

	inline Path<_Ty>(const _Ty&to,int len)noexcept
	{
		this->to=to;
		this->len=len;
	}
	inline Path<_Ty>(const _Ty&to)noexcept
	{
		this->to=to;
	}
	inline Path<_Ty>()noexcept
	{
	}


	inline bool operator<(const Path<_Ty>&other)const noexcept
	{
		return to<other.to;
	}
	inline bool operator>(const Path<_Ty>&other)const noexcept
	{
		return to>other.to;
	}
	inline bool operator<=(const Path<_Ty>&other)const noexcept
	{
		return to<=other.to;
	}
	inline bool operator>=(const Path<_Ty>&other)const noexcept
	{
		return to>=other.to;
	}
	inline bool operator==(const Path<_Ty>&other)const noexcept
	{
		return to==other.to;
	}
	inline bool operator!=(const Path<_Ty>&other)const noexcept
	{
		return to!=other.to;
	}
};
template<typename _Ty>
class Graph
{
public:
	inline Graph()
	{
	}

	
	inline void connect(const _Ty&from,const _Ty&to,int len,bool isOneWay=true)noexcept
	{
		insert(from);
		insert(to);
		
		vertecies[from].push_back(Path<_Ty>(to,len));
		if(!isOneWay)
			vertecies[to].push_back(Path<_Ty>(from,len));

		return;
	}
	inline void connect(const _Ty&from,const Path<_Ty>&path)noexcept
	{
		connect(from,path.to,path.len);
		return;
	}


	inline std::vector<Path<_Ty>>&find(const _Ty&id)noexcept
	{
		return vertecies[id];
	}


	inline std::vector<_Ty>listVertecies()noexcept
	{
		std::vector<_Ty>result;
		for(const std::pair<_Ty,std::vector<Path<_Ty>>>&key:vertecies)
			result.push_back(key.first);
		return result;
	}


	inline std::vector<std::pair<std::pair<_Ty,_Ty>,int>>listPaths()noexcept
	{
		std::vector<std::pair<std::pair<_Ty,_Ty>,int>>result;
		for(const std::pair<_Ty,std::vector<Path<_Ty>>>&from:vertecies)
			for(const Path<_Ty>&to:from.second)
				result.push_back(
					std::pair<std::pair<_Ty,_Ty>,int>(
						std::pair<_Ty,_Ty>(from.first,to.to),
						to.len));
		return result;
	}


	inline std::map<_Ty,int>dijkstra(const _Ty&from)noexcept
	{
		return dijkstra(from,
			[&](std::pair<int,_Ty>a,std::pair<int,_Ty>b)->bool
			{
				return a.first>=b.first;
			});
	}
	template<typename _Comp>
	inline std::map<_Ty,int>dijkstra(const _Ty&from,const _Comp&greaterThanOrEqualTo)noexcept
	{
		return dijkstra(from,greaterThanOrEqualTo,
			[&](std::pair<int,_Ty>a,std::pair<int,_Ty>b)->int
			{
				return a.first+b.first;
			});
	}
	template<typename _Comp,typename _Inc>
	inline std::map<_Ty,int>dijkstra(const _Ty&from,
		const _Comp&greaterThanOrEqualTo,
		_Inc increase)noexcept
	{
		std::map<_Ty,int>result;
		std::priority_queue<
			std::pair<int,_Ty>,
			std::vector<std::pair<int,_Ty>>,
			std::function<bool(std::pair<int,_Ty>,std::pair<int,_Ty>)>>
		pq(greaterThanOrEqualTo);
		pq.push(std::pair<int,_Ty>(0,from));
		result.insert(std::pair<_Ty,int>(from,0));

		while(!pq.empty())
		{
			_Ty vert=pq.top().second;
			pq.pop();
			int currentLen=result[vert];
			for(const Path<_Ty>&path:vertecies[vert])
			{
				int inc=increase(std::pair<int,_Ty>(currentLen,from),
					std::pair<int,_Ty>(path.len,path.to));
				
				if(result.find(path.to)==result.end())
				{
					result.insert(std::pair<_Ty,int>(path.to,inc));
					pq.push(std::pair<int,_Ty>(inc,path.to));
				}
				else if(!greaterThanOrEqualTo(
					std::pair<int,_Ty>(inc,path.to),
					std::pair<int,_Ty>(result[path.to],path.to)))
				{
					result[path.to]=inc;
					pq.push(std::pair<int,_Ty>(inc,path.to));
				}
			}
		}

		return result;
	}


	inline int vertexCount()
	{
		return vertecies.size();
	}

	
private:
	std::map<_Ty,std::vector<Path<_Ty>>>vertecies;

	inline void insert(const _Ty&id)noexcept
	{
		if(vertecies.find(id)!=vertecies.end())
			return;
		vertecies.insert(std::pair<_Ty,std::vector<Path<_Ty>>>(id,std::vector<Path<_Ty>>()));
		return;
	}
};

#endif

//#include"Tree.h" --->
#ifndef __TREE_H__
#define __TREE_H__

#include<vector>

template<typename _Ty>
struct Tree
{
	inline Tree(const _Ty&node,const std::vector<Tree<_Ty>>&subnodes)noexcept
	{
		this->subnodes.assign(subnodes.begin(),subnodes.end());
		this->node=node;
	}
	inline Tree(const _Ty&node)noexcept
	{
		this->node=node;
	}
	inline Tree()noexcept
	{
	}


	std::vector<Tree<_Ty>>subnodes;
	_Ty node;
};

#endif

//#include"SegTree.h" --->
#ifndef __SEG_TREE_H__
#define __SEG_TREE_H__

#include<vector>
#include<functional>

template<typename _Ty>
class SegTree
{
public:
	inline SegTree()
	{
	}
	template<typename _Func>
	inline SegTree(const _Func&func)noexcept
	{
		initialize(func);
	}
	template<typename _Func>
	inline SegTree(const int&size,const _Func&func)noexcept
	{
		initialize(size,func);
	}
	template<typename _Iterator,typename _Func>
	inline SegTree(_Iterator begin,_Iterator end,const _Func&func)
	{
		if(begin>end)
			throw 1;
		initialize(begin,end,func);
	}


	std::function<_Ty(_Ty,_Ty)>func;

	inline void update(int idx,const _Ty&val)noexcept
	{
		updateFwd(idx,0,len-1,1,val);
		return;
	}


	inline _Ty query(int first,int last)
	{
		if(first>last)
			throw 0;
		if(first<0)
			throw-1;
		if(last>=len)
			throw 1;
		return queryFwd(first,last,0,len-1,1);
	}


	template<typename _Func>
	inline void initialize(const _Func&func)noexcept
	{
		this->func=func;
		data.clear();
		return;
	}
	template<typename _Func>
	inline void initialize(const int&size,const _Func&func)noexcept
	{
		_Ty allocator[size];
		std::memset(allocator,0,sizeof(allocator));
		initialize(allocator,allocator+size,func);
		return;
	}
	template<typename _Func,typename _Iterator>
	inline void initialize(_Iterator begin,_Iterator end,const _Func&func)
	{
		if(begin>end)
			throw 1;
		this->func=func;
		len=end-begin;
		resetData(4*len);
		initFwd(begin,0,len-1,1);
		return;
	}


private:
	std::vector<_Ty>data;
	int len;

	inline void resetData(int size)
	{
		data.clear();
		data.resize(size);
		return;
	}


	inline void updateFwd(const int&idx,int first,int last,int pos,const _Ty&val)noexcept
	{
		if(first==last)
		{
			data[pos]=val;
			return;
		}

		int mid=(first+last)/2;
		if(idx<=mid)
			updateFwd(idx,first,mid,2*pos,val);
		else
			updateFwd(idx,mid+1,last,2*pos+1,val);
		data[pos]=func(data[2*pos],data[2*pos+1]);
		return;
	}


	template<typename _Iterator>
	inline void initFwd(_Iterator begin,int first,int last,int pos)noexcept
	{
		if(first==last)
		{
			data[pos]=*(begin+first);
			return;
		}

		int mid=(first+last)/2;
		initFwd(begin,first,mid,2*pos);
		initFwd(begin,mid+1,last,2*pos+1);
		data[pos]=func(data[2*pos],data[2*pos+1]);
		return;
	}


	inline _Ty queryFwd(const int&first,const int&last,int ptrFirst,int ptrLast,int pos)noexcept
	{
		if(ptrFirst==ptrLast)
			return data[pos];
		if(first<=ptrFirst&&last>=ptrLast)
			return data[pos];

		int mid=(ptrFirst+ptrLast)/2;
		bool a=first<=mid,b=mid<last;
		if(a&&b)
			return func(queryFwd(first,last,ptrFirst,mid,2*pos),queryFwd(first,last,mid+1,ptrLast,2*pos+1));
		if(a)
			return queryFwd(first,last,ptrFirst,mid,2*pos);
		return queryFwd(first,last,mid+1,ptrLast,2*pos+1);
	}
};

#endif

//My template --->
using namespace std;

#define ll long long
#define ull unsigned ll
#define byte signed char
#define ubyte unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort unsigned short
#define decimal long double
#define String std::string
#define Vector std::vector
#define Umap std::unordered_map
#define Set std::set
#define Uset std::unordered_set
#define Map std::map
#define PriorityQueue std::priority_queue
#define Greater std::greater
#define Queue std::queue
#define Array std::array
#define Pair std::pair
#define Exception std::exception
#define charArray c_str
#define minElement std::min_element
#define maxElement std::max_element
#define lowerBound std::lower_bound
#define upperBound std::upper_bound
#define emplaceBack emplace_back
#define pushBack push_back
#define makePair std::make_pair
#define elif else if
#define begend(LIST)LIST.begin(),LIST.end()
#define toCharString c_str
#define toString to_string
#define parseInt std::stoi
#define parseLong std::stol
#define parseFloat std::stof
#define parseDouble std::stod
#define parseDecimal std::stold
#define parseULong std::stoul
#define parseLL std::stoll
#define parseULL std::stoull
#define SHORT_MAX SHRT_MAX
#define SHORT_MIN SHRT_MIN
#define USHORT_MAX USHRT_MAX
#define LL_MAX LLONG_MAX
#define ULL_MAX ULLONG_MAX
#define LL_MIN LLONG_MIN
#define FLOAT_MAX FLT_MAX
#define FLOAT_MIN FLT_MIN
#define DOUBLE_MAX DBL_MAX
#define DOUBLE_MIN DBL_MIN
#define DECIMAL_MAX LDBL_MAX
#define DECIMAL_MIN LDBL_MIN
#define BYTE_MAX SCHAR_MAX
#define BYTE_MIN SCHAR_MIN
#define UBYTE_MAX UCHAR_MAX
#define y1 ANOTHER_VARIABLE_NAME_y1
#define left ANOTHER_VARIABLE_NAME_left
#define right ANOTHER_VARIABLE_NAME_right
#define plus ANOTHER_VARIABLE_NAME_plus
#define reset(arr)std::memset(arr,0,sizeof(arr))
#define lachlanMclean4(_Name,START,END,INC)for(int _Name=INC>0?START:START+INC;\
    INC>0?(_Name<END):(_Name>END+INC);\
    _Name=_Name+INC)
#define lachlanMclean1(END)lachlanMclean4(i,0,(END),(0<(END)?1:-1))
#define lachlanMclean2(_Name,END)lachlanMclean4(_Name,0,(END),(0<(END)?1:-1))
#define lachlanMclean3(_Name,START,END)lachlanMclean4(_Name,(START),(END),((START)<(END)?1:-1))
#define helloLachlanMacleansCollege(START,_Fwd4,_Fwd3,_Fwd2,_Fwd1,...)_Fwd1
#define rep(...)helloLachlanMacleansCollege\
	(__VA_ARGS__,lachlanMclean4,lachlanMclean3,lachlanMclean2,lachlanMclean1)\
	(__VA_ARGS__)
#define lawrenceWen2(_Name,_List)for(auto&_Name:_List)
#define lawrenceWen1(_List)lawrenceWen2(i,_List)
#define helloLawrenceWhenDidIAsk(START,_Fwd2,_Fwd1,...)_Fwd1
#define each(...)helloLawrenceWhenDidIAsk(__VA_ARGS__,lawrenceWen2,lawrenceWen1)(__VA_ARGS__)
#define MOD 1000000007
#define min customMin
#define max customMax
/*********************************\
|  -  Inspired by William Lin  -  |
\*********************************/


bool isEnd_printFwd=false;
bool isFirstGet_getFwd=false;

inline void printFwd(const bool&isOut){}
inline void printFwd(const bool&isOut,const bool&val)
{
	if(isOut)
    {
        if(isEnd_printFwd)
            std::cout<<' ';
        else
            isEnd_printFwd=true;
    }
	std::cout<<(val?"true":"false");
	return;
}
template<typename _Ty>
inline void printFwd(const bool&isOut,const _Ty&val)
{
	if(isOut)
    {
        if(isEnd_printFwd)
            std::cout<<' ';
        else
            isEnd_printFwd=true;
    }
	std::cout<<val;
	return;
}
template<typename _First,typename..._Args>
inline void printFwd(const bool&isOut,const _First&first,const _Args&...args)
{
	printFwd(isOut,first);
	printFwd(isOut,args...);
	return;
}
template<typename..._Args>
inline void print(const _Args&...args)
{
	printFwd(true,args...);
	std::cout<<std::flush;
	return;
}
template<typename..._Args>
inline void println(const _Args&...args)
{
	printFwd(true,args...);
	std::cout<<std::endl;
	isEnd_printFwd=false;
	return;
}
template<typename..._Args>
inline void put(const _Args&...args)
{
	isEnd_printFwd=false;
	printFwd(false,args...);
	std::cout<<std::flush;
	return;
}
inline void refresh()
{
	std::cout<<std::flush;
}


inline const int getInt()
{
	int tmp;
	std::cin>>tmp;
	return tmp;
}
inline const long getLong()
{
	long tmp;
	std::cin>>tmp;
	return tmp;
}
inline const long long getLL()
{
	long long tmp;
	std::cin>>tmp;
	return tmp;
}
inline const unsigned long long getULL()
{
	unsigned long long tmp;
	std::cin>>tmp;
	return tmp;
}
inline const short getShort()
{
	short tmp;
	std::cin>>tmp;
	return tmp;
}
inline const unsigned int getUInt()
{
	unsigned int tmp;
	std::cin>>tmp;
	return tmp;
}
inline const unsigned short getUShort()
{
	unsigned short tmp;
	std::cin>>tmp;
	return tmp;
}
inline const unsigned long getULong()
{
	unsigned long tmp;
	std::cin>>tmp;
	return tmp;
}
inline const signed char getByte()
{
	short tmp;
	std::cin>>tmp;
	return tmp;
}
inline const unsigned char getUByte()
{
	unsigned char tmp;
	std::cin>>tmp;
	return tmp;
}
inline const char getChar()
{
	char tmp;
	std::cin>>tmp;
	return tmp;
}
inline const std::string get()
{
	std::string tmp;
	std::cin>>tmp;
	return tmp;
}


template<typename _Ty>
inline const _Ty&min(const _Ty&first)noexcept
{
	return first;
}
template<typename _Ty>
inline const _Ty&min(const _Ty&first,const _Ty&second)
{
	return first<second?first:second;
}
template<typename _Ty,typename..._Args>
inline const _Ty&min(const _Ty&first,const _Args&...args)
{
	return min(first,min(args...));
}


template<typename _Ty>
inline const _Ty&max(const _Ty&first)noexcept
{
	return first;
}
template<typename _Ty>
inline const _Ty&max(const _Ty&first,const _Ty&second)
{
	return first>second?first:second;
}
template<typename _Ty,typename..._Args>
inline const _Ty&max(const _Ty&first,const _Args&...args)
{
	return max(first,max(args...));
}
#endif
using namespace std;


#define PROBLEM
//#define USACO_UTIL "cowdance"


const int MAX_VAL=1E5;
int n,t;
int cows[MAX_VAL];

inline bool check(const int&k)noexcept
{
	if(k==0)
		return 0;
	PriorityQueue<int,Vector<int>,Greater<int>>pq;
	int r=0;
	rep(k)
		pq.push(cows[i]);
	int currentIdx=k;
	while(currentIdx<n)
	{
		pq.push(cows[currentIdx]+pq.top());
		pq.pop();
		currentIdx++;
	}
	rep(k-1)
		pq.pop();
	return pq.top()>t;
}


inline void myCodeHere()noexcept
{
	n=getInt(),t=getInt();
	rep(n)
		cows[i]=getInt();
	
	int l=0,r=n;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid;
	}
	if(!check(l))
		put(l);
	else
		put(r);
}


//#include"MyTemplateFwd.h"
#ifdef __MY_TEMPLATE_H__
#ifndef __MY_TEMPLATE_FWD_H__
#define __MY_TEMPLATE_FWD_H__


#ifdef USACO_UTIL
#define INOUT_TXT
#define IN_TXT_TEXT ((std::string)USACO_UTIL+".in").c_str()
#define OUT_TXT_TEXT ((std::string)USACO_UTIL+".out").c_str()
#endif


//Main function
int main(int argc,char*argv[])noexcept
{
	std::ios_base::sync_with_stdio(false);
#ifdef INOUT_TXT
#define IN_TXT
#define OUT_TXT
#endif
#ifdef IN_TXT
#ifndef IN_TXT_TEXT
#define IN_TXT_TEXT "in.txt"
#endif
	std::ifstream in(IN_TXT_TEXT);
    std::cin.rdbuf(in.rdbuf());
#endif
#ifdef OUT_TXT
#ifndef OUT_TXT_TEXT
#define OUT_TXT_TEXT "out.txt"
#endif
    std::ofstream out(OUT_TXT_TEXT);
    std::cout.rdbuf(out.rdbuf());
#endif
	std::cin.tie(NULL);std::cout.tie(NULL);
#ifndef PROBLEM
	int myTestCases;
	std::cin>>myTestCases;
	while(myTestCases--)
	{
#endif
		myCodeHere();
		std::cout<<std::endl;
#ifndef PROBLEM
	}
#endif
	return 0;
}
#endif
#endif


/*
Patrick Bateman, the Wall Street man,
A life of privilege, his only plan,
But deep inside, a darkness looms,
A monster lurking in the rooms.

His soul consumed by greed and lust,
His mind a web of lies and mistrust,
He lives a life of shallow grace,
A mask he wears, a smile on his face.

But beneath it all, a beast awakes,
A killer's urge, a thirst he slakes,
With each victim, his soul corrodes,
As his mind, further it erodes.

His crimes, a stain upon his soul,
A void he tries to fill, a hole,
But nothing brings him peace or rest,
For in his heart, a demon, possessed.

Patrick Bateman, a tragic tale,
Of a man who lost his moral trail,
A warning sign for all to see,
Of the dangers of depravity.
*/