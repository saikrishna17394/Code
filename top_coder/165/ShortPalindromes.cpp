// BEGIN CUT HERE

// END CUT HERE
#line 5 "ShortPalindromes.cpp"
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

int A[25][25];
string dp[25][25];

class ShortPalindromes {
    public:
    int n;
    string s;
    string solve(int i,int j) {
    	
    	if(A[i][j]!=-1) {
    		return dp[i][j];
    	}
	
		if(i==j) {
			A[i][j]=1;
			dp[i][j]+=s[i];
			return dp[i][j];
		}
		if((i+1)==j) {
			if(s[i]==s[j]) {
				A[i][j]=2;
				dp[i][j]+=s[i];
				dp[i][j]+=s[j];
			}
			else {
				A[i][j]=3;
				if(s[i]<s[j])
					dp[i][j]=s.substr(i,2)+s[i];
				else
					dp[i][j]=s[j]+s.substr(i,2);
			}
			return dp[i][j];
		}
    	
    	if(s[i]==s[j]) {
    		string ret=solve(i+1,j-1);
    		A[i][j]=2+A[i+1][j-1];
    		dp[i][j]=s[i]+ret+s[j];
    	}
    	else {
    		string ret=solve(i+1,j);
    		string ret1=solve(i,j-1);

    		if(A[i+1][j]<A[i][j-1]) {
    			dp[i][j]=s[i]+ret+s[i];
    			A[i][j]=2+A[i+1][j];
    		}
    		else if(A[i+1][j]>A[i][j-1]) {
    			dp[i][j]=s[j]+ret1+s[j];
    			A[i][j]=2+A[i][j-1];
    		}
    		else {
    			A[i][j]=2+A[i][j-1];
    			dp[i][j]=min(s[j]+ret1+s[j],s[i]+ret+s[i]);
    		}
    	}
    	// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    	return dp[i][j];
    }
    string shortest(string base) {
         //$CARETPOSITION$
    	s=base;
    	n=s.length();
    	memset(A,-1,sizeof A);
    	return solve(0,n-1);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RACE"; string Arg1 = "ECARACE"; verify_case(0, Arg1, shortest(Arg0)); }
	void test_case_1() { string Arg0 = "TOPCODER"; string Arg1 = "REDTOCPCOTDER"; verify_case(1, Arg1, shortest(Arg0)); }
	void test_case_2() { string Arg0 = "Q"; string Arg1 = "Q"; verify_case(2, Arg1, shortest(Arg0)); }
	void test_case_3() { string Arg0 = "MADAMIMADAM"; string Arg1 = "MADAMIMADAM"; verify_case(3, Arg1, shortest(Arg0)); }
	void test_case_4() { string Arg0 = "ALRCAGOEUAOEURGCOEUOOIGFA"; string Arg1 = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA"; verify_case(4, Arg1, shortest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ShortPalindromes ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
