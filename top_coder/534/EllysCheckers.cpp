// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysCheckers.cpp"
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

int dp[1<<20];
class EllysCheckers {
    public:
    string s;
    int len,num;

    int solve(int mask) {
    	if(mask&1)
    		mask--;
    	int& ret=dp[mask];
    	if(ret!=-1)
    		return ret;

    	ret=0;
    	int a[20];
    	int val=mask;
    	for(int i=0;i<len;i++) {
    		a[i]=val&1;
    		val>>=1;
    	}

    	val=1<<(len-1);

    	for(int i=len-1;i>0;i--) {
    		if(a[i]) {
    			if(a[i-1]==0 && solve((mask^val)^(val/2))==0) {
    				ret=1;
    				return ret;
    			}
    			if(i>2 && a[i-1] && a[i-2] && a[i-3]==0 && solve((mask^val)^(val/8))==0) {
    				ret=1;
    				return ret;
    			}
    		}
    		val/=2;
    	}
    	return ret;
    }

    string getWinner(string board) {
         //$CARETPOSITION$
    	memset(dp,-1,sizeof dp);
    	s=board;
    	len=s.length();

    	dp[0]=0;
    	num=1<<len;
    	for(int i=1;i<num;i++) {
    		dp[i]=solve(i);
    		// cout<<i<<" "<<dp[i]<<endl;
    	}
    	num=0;
    	for(int i=0;i<len;i++) {
    		num=num*2;
    		if(s[i]=='o')
    			num++;
    	}
    	// cout<<num<<" "<<endl;
    	if(dp[num])
    		return "YES";
    	else
    		return "NO";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	// private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o..."; string Arg1 = "YES"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "..o..o"; string Arg1 = "YES"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = ".o...ooo..oo.."; string Arg1 = "NO"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "......o.ooo.o......"; string Arg1 = "YES"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = ".o..o...o....o.....o"; string Arg1 = "NO"; verify_case(4, Arg1, getWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    EllysCheckers ___test;
    ___test.run_test(-1);
    // ___test.test_case_0();
    system("pause");
}
// END CUT HERE 
