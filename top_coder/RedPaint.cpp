// BEGIN CUT HERE

// END CUT HERE
#line 5 "RedPaint.cpp"
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

double dp[2][501][501];

class RedPaint {
    public:
    double expectedCells(int N) {
         //$CARETPOSITION$
    	// memset(dp,0,sizeof dp);
    	// cout<<dp[0][0][0]<<endl;

    	for(int i=0;i<=N;i++) {
    		for(int j=0;j<=N;j++) {
    			if((i+j)>N)
    				continue;
    			dp[0][i][j]=(double)(i+j+1);
    			// cout<<i<<" "<<j<<" "<<dp[0][i][j]<<endl;
    		}
    	}

    	for(int n=1;n<=N;n++) {
    		for(int i=0;i<=N;i++) {
    			for(int j=0;j<=N;j++) {
    				if((i+j)>N)
    					continue;
    				if(j==0) {
    					dp[1][i][j]=0;
    					if((i+1)<=N) {
		    				dp[1][i][j]+=dp[0][i+1][j]/2.0;
		    			}

	    				dp[1][i][j]+=dp[0][max(i-1,0)][1]/2.0;
    				}
    				else if(i==0) {
    					dp[1][i][j]=0;
    					if((j+1)<=N) {
    						dp[1][i][j]+=dp[0][i][j+1]/2.0;
    					}

						dp[1][i][j]+=dp[0][1][max(j-1,0)]/2.0;
    					
    				}
    				else {
    					dp[1][i][j]=0;
    					if((i+1)<=N) {
		    				dp[1][i][j]+=dp[0][i+1][j-1]/2.0;
		    			}
    					if((j+1)<=N) {
    						dp[1][i][j]+=dp[0][i-1][j+1]/2.0;
    					}

    				}
    				// cout<<n<<" "<<i<<" "<<j<<" "<<dp[n][i][j]<<endl;
    			}
    		}
    		for(int i=0;i<=N;i++) {
    			for(int j=0;j<=N;j++) {
    				if((i+j)>N)
    					continue;
    				dp[0][i][j]=dp[1][i][j];
    			}
    		}
    	}
    	return dp[0][0][0];
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; double Arg1 = 1.0; verify_case(0, Arg1, expectedCells(Arg0)); }
	void test_case_1() { int Arg0 = 1; double Arg1 = 2.0; verify_case(1, Arg1, expectedCells(Arg0)); }
	void test_case_2() { int Arg0 = 2; double Arg1 = 2.5; verify_case(2, Arg1, expectedCells(Arg0)); }
	void test_case_3() { int Arg0 = 4; double Arg1 = 3.375; verify_case(3, Arg1, expectedCells(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    RedPaint ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
