// BEGIN CUT HERE

// END CUT HERE
#line 5 "StripePainter.cpp"
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
#define inf 1000
using namespace std;

int dp[50][50][27];

class StripePainter {
    public:
    string s;
    int n;
    int solve(int i,int j,int c) {
    	if(i>j)
    		return 0;
    	int &ret=dp[i][j][c];
    	if(ret!=inf)
    		return ret;

    	int col=s[i]-'A';
    	if(col==c) {
    		ret=solve(i+1,j,c);
    		return ret;
    	}

    	// bool ok=true;
    	int idx=j;
    	for(int k=i+1;k<=j;k++) {
    		if(s[k]!=s[i]) {
    			idx=k-1;
    			break;
    		}
    	}
    	ret=min(ret,1+solve(idx+1,j,c));

    	for(int k=idx+1;k<=j;k++) {
    		ret=min(ret,1+solve(idx+1,k,col)+solve(k+1,j,c));
    	}
    	return ret;
    }

    int minStrokes(string stripes) {
         //$CARETPOSITION$
    	s=stripes;
    	n=s.length();
    	for(int i=0;i<50;i++)
    		for(int j=0;j<50;j++)
    			for(int k=0;k<27;k++)
	    			dp[i][j][k]=inf;

    	return solve(0,n-1,26);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGBGR"; int Arg1 = 3; verify_case(0, Arg1, minStrokes(Arg0)); }
	void test_case_1() { string Arg0 = "RGRG"; int Arg1 = 3; verify_case(1, Arg1, minStrokes(Arg0)); }
	void test_case_2() { string Arg0 = "ABACADA"; int Arg1 = 4; verify_case(2, Arg1, minStrokes(Arg0)); }
	void test_case_3() { string Arg0 = "AABBCCDDCCBBAABBCCDD"; int Arg1 = 7; verify_case(3, Arg1, minStrokes(Arg0)); }
	void test_case_4() { string Arg0 = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"; int Arg1 = 26; verify_case(4, Arg1, minStrokes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    StripePainter ___test;
    ___test.run_test(-1);
    // ___test.test_case_0();
    system("pause");
}
// END CUT HERE 
