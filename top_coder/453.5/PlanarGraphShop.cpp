// BEGIN CUT HERE

// END CUT HERE
#line 5 "PlanarGraphShop.cpp"
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

int dp[50001];
class PlanarGraphShop {
    public:
	vector<int> v;
	int solve(int n) {
		if(n==0)
			return 0;
		int& ret=dp[n];
		if(ret!=-1)
			return ret;
		ret=n;
		for(int i=0;i<v.size();i++) {
			if(v[i]>n)
				break;
			ret=min(ret,1+solve(n-v[i]));
		}
		return ret;
	}
    int bestCount(int N) {
         //$CARETPOSITION$
    	int num,val;
    	set<int> s;

    	// Read about planar graphs
    	// There is a condition that #edges<=3*(#vertices -2)
    	// i.e E<=3*(V-2) for |V|>=3
    	// Proof in the editorial
    	for(int i=1;i<=N;i++) {
    		num=i*i*i;
    		if(num>N)
    			break;
    		if(i>2)
	    		val=3*(i-2);
	    	else {
	    		val=i*(i-1);
	    		val/=2;
	    	}
    		for(int j=0;j<=val;j++) {
    			if((num+j*j)>N)
    				break;
    			s.insert(num+j*j);
    		}
    	}
    	vector<int> v1(s.begin(),s.end());
    	v=v1;
    	
    	memset(dp,-1,sizeof dp);
    	return solve(N);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 36; int Arg1 = 1; verify_case(0, Arg1, bestCount(Arg0)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 7; verify_case(1, Arg1, bestCount(Arg0)); }
	void test_case_2() { int Arg0 = 72; int Arg1 = 2; verify_case(2, Arg1, bestCount(Arg0)); }
	void test_case_3() { int Arg0 = 46; int Arg1 = 3; verify_case(3, Arg1, bestCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PlanarGraphShop ___test;
    ___test.run_test(-1);
    // ___test.bestCount(18735);
    system("pause");
}
// END CUT HERE 
