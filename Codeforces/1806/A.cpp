#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define byte signed char
#define ubyte unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort unsigned short
#define decimal long double
#define vt vector
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define elif else if
#define begend(LIST)LIST.begin(),LIST.end()
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
#define umap unordered_map
#define endl '\n'
#define lachlanMclean4(_Name,START,END,INC)for(int _Name=INC>0?START:START+INC;\
    INC>0?_Name<END:_Name>END+INC;\
    _Name=_Name+INC)
#define lachlanMclean1(END)lachlanMclean4(i,0,END,(0<END?1:-1))
#define lachlanMclean2(_Name,END)lachlanMclean4(_Name,0,END,(0<END?1:-1))
#define lachlanMclean3(_Name,START,END)lachlanMclean4(_Name,START,END,(START<END?1:-1))
#define helloLachlanMacleansCollege(START,_Fwd4,_Fwd3,_Fwd2,_Fwd1,...)_Fwd1
#define rep(...)helloLachlanMacleansCollege\
	(__VA_ARGS__,lachlanMclean4,lachlanMclean3,lachlanMclean2,lachlanMclean1)\
	(__VA_ARGS__)
#define lawrenceWen2(_Name,_List)for(auto&_Name:_List)
#define lawrenceWen1(_List)lawrenceWen2(i,_List)
#define helloLawrenceWhenDidIAsk(START,_Fwd2,_Fwd1,...)_Fwd1
#define each(...)helloLawrenceWhenDidIAsk(__VA_ARGS__,lawrenceWen2,lawrenceWen1)(__VA_ARGS__)
#define MOD 1000000007
 
 
bool isEnd_printFwd=false;
bool isFirstGet_getFwd=false;
 
void printFwd(const bool&isOut){}
void printFwd(const bool&isOut,const bool&val)
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
void printFwd(const bool&isOut,const _Ty&val)
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
void printFwd(const bool&isOut,const _First&first,const _Args&...args)
{
	printFwd(isOut,first);
	printFwd(isOut,args...);
	return;
}
template<typename..._Args>
void print(const _Args&...args)
{
	printFwd(true,args...);
	std::cout<<std::flush;
	return;
}
template<typename..._Args>
void println(const _Args&...args)
{
	printFwd(true,args...);
	std::cout<<std::flush<<endl;
	isEnd_printFwd=false;
	return;
}
template<typename..._Args>
void put(const _Args&...args)
{
	isEnd_printFwd=false;
	printFwd(false,args...);
	std::cout<<std::flush;
	return;
}
void refresh()
{
	std::cout<<std::flush;
}
 
 
template<typename _Ty>
void get(_Ty&val)
{
	isFirstGet_getFwd=true;
	std::cin>>val;
	return;
}
template<typename _First,typename..._Args>
void get(_First&first,_Args&...args)
{
	get(first);
	get(args...);
	return;
}
void getLine(char*val)
{
	if(isFirstGet_getFwd)
	{
		cin.ignore();
		cin.clear();
	}
	isFirstGet_getFwd=false;
	std::cin.getline(val,INT_MAX);
	return;
}
void getLine(std::string&val)
{
	if(isFirstGet_getFwd)
	{
		cin.clear();
		cin.ignore();
	}
	isFirstGet_getFwd=false;
	std::getline(std::cin,val);
	return;
}
//Inspired by William Lin
 
 
#define PROBLEMS
 
 
const int MAX_VAL=1E5+5;
ll sx,sy,dx,dy;
 
void myCodeHere()
{
	get(sx,sy,dx,dy);
	dx-=sx;
	dy-=sy;
	if(dy<0)
	{
		put(-1);
		return;
	}
	if(dx>dy)
	{
		put(-1);
		return;
	}
	put(dy*2-dx);
}
 
 
//Main function
int main(int argc,char*argv[])
{
	ios_base::sync_with_stdio(false);
	//std::cin.tie(0);std::cout.tie(0);
#ifdef INOUT_TXT
    std::ifstream in("in.txt");
    std::ofstream out("out.txt");
    std::cin.rdbuf(in.rdbuf());
    std::cout.rdbuf(out.rdbuf());
#else
#ifdef IN_TXT
    std::ifstream in("in.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
#ifdef OUT_TXT
    std::ofstream out("out.txt");
    std::cout.rdbuf(out.rdbuf());
#endif
#endif
#ifndef PROBLEM
	int myTestCases;
	std::cin>>myTestCases;
	while(myTestCases--)
	{
#endif
		myCodeHere();
		std::cout<<endl<<std::flush;
#ifndef PROBLEM
	}
#endif
	return 0;
}