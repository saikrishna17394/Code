// BEGIN CUT HERE

// END CUT HERE
#line 5 "LittleElephantAndXor.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

class LittleElephantAndXor {
    public:
    int a[32],b[32],c[32];
    lli dp[32][2][2][2];
    lli solve(int idx,int i,int j,int k) {
    	if(idx<0)
    		return 1;
    	lli& ret=dp[idx][i][j][k];
    	if(ret!=-1)
    		return ret;
    	ret=0;

    	if((a[idx]==1 || i==1) && (b[idx]==1 || j==1)) {
    		ret+=solve(idx-1,i,j,max(k,c[idx]));
    	}
    	ret+=solve(idx-1,max(i,a[idx]),max(j,b[idx]),max(k,c[idx]));

    	if(c[idx]==1 || k==1) {
    		if(a[idx] || i)
    			ret+=solve(idx-1,i,max(j,b[idx]),k);
    		if(b[idx] || j)
    			ret+=solve(idx-1,max(i,a[idx]),j,k);
    	}

    	return ret;

    }
    long long getNumber(int A, int B, int C) {
         //$CARETPOSITION$
    	for(int i=0;i<32;i++) {
    		a[i]=A&1;
    		A>>=1;
    	}
    	for(int i=0;i<32;i++) {
    		b[i]=B&1;
    		B>>=1;
    	}
    	for(int i=0;i<32;i++) {
    		c[i]=C&1;
    		C>>=1;
    	}
    	memset(dp,-1,sizeof dp);
    	return solve(31,0,0,0);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 5LL; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 3; long long Arg3 = 20LL; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; long long Arg3 = 57LL; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 774; int Arg1 = 477; int Arg2 = 447; long long Arg3 = 214144LL; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 500000000; long long Arg3 = 468566946385621507LL; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     LittleElephantAndXor ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
