// BEGIN CUT HERE

// END CUT HERE
#line 5 "SumThemAll.cpp"
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
#define ii pair<int,int>
using namespace std;

lli dp[12],pow1[12];
pair<int,int> length(int n)  {
	int ret=0;
	ii p;
	while(n) {
		ret++;
		p.second=n%10;
		n/=10;
	}
	p.first=ret;
	return p;
}

lli solve(int n) {
	// cout<<" kir "<<n<<endl;
	if(n==0)
		return 0;
	//cout<<n<<" "<< length(n).second<<endl;
	ii p=length(n);
	lli ret;
	if(p.first==1) {
		ret=n;
		ret=ret*(ret+1);
		ret/=2;
		// cout<<n<<" adff "<<ret<<endl;
		return ret;
	}

	ret=dp[p.first-1];
	lli val=1;
	for(int i=1;i<p.first;i++)
		val*=10;

	for(lli i=1;i<p.second;i++) {
		ret+=i*val+dp[p.first-1];
	}

	val=(lli)n%val;
	ret+=solve(val);
	// cout<<ret<<" man "<<p.second<<" "<<val<<endl;
	ret+=(val+1)*(lli)p.second;
	// cout<<n<<" sup "<<ret<<endl;
	return ret;
}
class SumThemAll {
    public:
    long long getSum(int lowerBound, int upperBound) {
         //$CARETPOSITION$
    	dp[1]=45;
    	lli val=10;
    	pow1[1]=10;
    	for(int i=2;i<10;i++) {
    		dp[i]=dp[i-1];

    		for(lli j=1;j<10;j++) {
    			dp[i]+=j*val;
    			dp[i]+=dp[i-1];
    		}
    		val*=10;
    		pow1[i]=10*pow1[i-1];
    		// cout<<i<<" "<<dp[i]<<endl;
    	}

    	lli ans=solve(upperBound);
    	// cout<<" d "<<ans<<endl; 
    	if(lowerBound)
    		ans-=solve(lowerBound-1);
    	// cout<<" d "<<ans<<endl; 
    	return ans;
    	
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	// private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 3; long long Arg2 = 6LL; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 14; long long Arg2 = 15LL; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; long long Arg2 = 0LL; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 53; long long Arg2 = 296LL; verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 24660; int Arg1 = 308357171; long long Arg2 = 11379854844LL; verify_case(4, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     SumThemAll ___test;
      ___test.run_test(-1);
      // ___test.test_case_3();
      system("pause");
}
// END CUT HERE 
