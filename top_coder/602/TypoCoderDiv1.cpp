// BEGIN CUT HERE

// END CUT HERE
#line 5 "TypoCoderDiv1.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
using namespace std;

int dp[50][2][2200];
class TypoCoderDiv1 {
    public:
    vector<int> v;
    int n;
    int solve(int idx,int a,int rat) {
    	if(idx==n)
    		return 0;
    	int& ret=dp[idx][a][rat];
    	if(ret!=-1)
    		return ret;
    	if(a==1) {
    		if(max(rat+v[idx-1]-v[idx],0)>=2200) {
    			ret=-1000;
    			return ret;
    		}
    		ret=1+solve(idx+1,0,max(rat+v[idx-1]-v[idx],0));
    		return ret;
    	}
    	ret=solve(idx+1,a,max(0,rat-v[idx]));
    	if((rat+v[idx])<2200)
    		ret=max(ret,solve(idx+1,0,rat+v[idx]));
    	else
    		ret=max(ret,1+solve(idx+1,1,rat));
    	return ret;
    }
    int getmax(vector <int> D, int X) {
         //$CARETPOSITION$
    	v=D;
    	n=v.size();
    	memset(dp,-1,sizeof dp);
    	return solve(0,0,X);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,200,100,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000; int Arg2 = 3; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2199; int Arg2 = 0; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000000000,1000000000,10000,100000,2202,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 4; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2199; int Arg2 = 0; verify_case(4, Arg2, getmax(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TypoCoderDiv1 ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
