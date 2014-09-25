// BEGIN CUT HERE

// END CUT HERE
#line 5 "RoundOfEleven.cpp"
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
using namespace std;

lli dp[20][11][501];
int a[20];
class RoundOfEleven {
    public:

    lli solve(int idx,int rem,int cost) {
    	if(idx<0) {
    		if(rem==0)
    			return cost;
    		return 0;
    	}
    	lli &ret=dp[idx][rem][cost];
    	if(ret!=-1)
    		return ret;
    	ret=0;
    	for(int i=0;i<10;i++) {
    		if(abs(a[idx]-i)<=cost)
    			ret+=solve(idx-1,(rem*10+i)%11,cost-abs(a[idx]-i));
    	}
    	return ret;
    }
    long long maxIncome(int n, int money) {
         //$CARETPOSITION$
    	int idx=0;
    	for(int i=0;i<20;i++) {
    		a[i]=n%10;
    		n/=10;
    		if(n==0) {
    			idx=i;
    			break;
    		}
    	}
    	memset(dp,-1,sizeof dp);
    	return solve(idx,0,money);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 31; int Arg1 = 4; long long Arg2 = 6LL; verify_case(0, Arg2, maxIncome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 31; int Arg1 = 5; long long Arg2 = 11LL; verify_case(1, Arg2, maxIncome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 110; int Arg1 = 3; long long Arg2 = 7LL; verify_case(2, Arg2, maxIncome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 19759; int Arg1 = 435; long long Arg2 = 3788217LL; verify_case(3, Arg2, maxIncome(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    RoundOfEleven ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
