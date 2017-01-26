// BEGIN CUT HERE

// END CUT HERE
#line 5 "MiniPaint.cpp"
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

int dp[50][3001],A[50][51];

class MiniPaint {
    public:
    int leastBad(vector <string> s, int ms) {
         //$CARETPOSITION$
    	int r=s.size(),c=s[0].size();

    	for(int i=0;i<r;i++) {

    		for(int k=0;k<c;k++)
    			A[k][0]=k+1;

    		for(int j=1;j<=c;j++) {
    			int w=0,b=0;
    			if(s[i][0]=='W')
    				w++;
    			else
    				b++;
    			A[0][j]=0;
    			for(int k=1;k<c;k++) {
    				if(s[i][k]=='W')
    					w++;
    				else
    					b++;
    				A[k][j]=min(w,b);

    				int w1=0,b1=0;
    				for(int a=k;a>0;a--) {
    					if(s[i][a]=='W')
    						w1++;
    					else
    						b1++;
    					A[k][j]=min(A[k][j],min(w1,b1)+A[a-1][j-1]);
    				}
    			}
    		}

    		// cout<<i<<" :\n";
    		// for(int j=0;j<=c;j++)
    		// 	cout<<A[c-1][j]<<" ";
    		// printf("\n");

    		if(i==0) {
    			for(int j=0;j<=c;j++)
    				dp[i][j]=A[c-1][j];
    			for(int j=c+1;j<=ms;j++)
    				dp[i][j]=0;
    		}
    		else {
    			for(int j=0;j<=ms;j++) {
    				dp[i][j]=dp[i-1][j]+c;
    				for(int k=0;k<=min(c,j);k++)
    					dp[i][j]=min(dp[i][j],dp[i-1][j-k]+A[c-1][k]);
    			}
    		}
    	}
    	return dp[r-1][ms];
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 0; verify_case(0, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(1, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 60; verify_case(2, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 40; verify_case(3, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(4, Arg2, leastBad(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MiniPaint ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
