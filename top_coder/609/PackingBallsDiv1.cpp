// BEGIN CUT HERE

// END CUT HERE
#line 5 "PackingBallsDiv1.cpp"
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

lli X[100010];

class PackingBallsDiv1 {
    public:
    int minPacks(int k, int a, int b, int c, int d) {
         //$CARETPOSITION$
    	X[0]=a;
    	for(int i=1;i<k;i++) {
    		X[i]=((X[i-1]*(lli)b)+(lli)c)%(lli)d;
    		X[i]++;
    	}
    	lli ans=0;

    	lli val=0;
    	// lli val1=0;
    	vector<lli> v;
    	for(int i=0;i<k;i++) {
    		ans+=(X[i]/(lli)k);
    		X[i]%=(lli)k;
    		if(X[i])
    			v.push_back(X[i]);
    			// val1++;
    		// val=max(val,X[i]);
    	}
    	sort(v.begin(),v.end());
    	val=v.size();

    	int n=v.size();
    	for(int i=n-1;i>=0;i--) {
    		val=min(val,v[i]+(lli)(n-i-1));
    	}
    	
    	ans+=val;
    	// ans+=min(val,val1);
    	return (int) ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 2; int Arg3 = 5; int Arg4 = 6; int Arg5 = 4; verify_case(0, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 23; int Arg3 = 39; int Arg4 = 93; int Arg5 = 58; verify_case(1, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 10988; int Arg2 = 5573; int Arg3 = 4384; int Arg4 = 100007; int Arg5 = 47743; verify_case(2, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 123456789; int Arg2 = 234567890; int Arg3 = 345678901; int Arg4 = 1000000000; int Arg5 = 331988732; verify_case(3, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PackingBallsDiv1 ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
