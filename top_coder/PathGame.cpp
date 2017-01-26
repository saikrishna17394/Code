// BEGIN CUT HERE

// END CUT HERE
#line 5 "PathGame.cpp"
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

int dp[1000];

class PathGame {
    public:
    string judge(vector <string> b) {
         //$CARETPOSITION$
    	int n=b[0].size();
		
		int val=0;
		if(b[0][0]=='.')
			val++;
		if(b[1][0]=='.')
			val++;

		if(val==2)
			dp[0]=1;
		else
			dp[0]=0;

		for(int i=1;i<n;i++) {
			val=0;
			if(b[0][i]=='.')
				val++;
			if(b[1][i]=='.')
				val++;

			if(val==1) {
				dp[i]=dp[i-1];
			}
			else {
				dp[i]=dp[i-1]^1;
			}
		} 	

		if(dp[n-1]==1)
			return "Snuke";
		else
			return "Sothe";

    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#.."
,"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(0, Arg1, judge(Arg0)); }
	void test_case_1() { string Arr0[] = {"#"
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(1, Arg1, judge(Arg0)); }
	void test_case_2() { string Arr0[] = {"....."
,"..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(2, Arg1, judge(Arg0)); }
	void test_case_3() { string Arr0[] = {".#..."
,"....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(3, Arg1, judge(Arg0)); }
	void test_case_4() { string Arr0[] = {".....#..#........##......."
,"..........#..........#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(4, Arg1, judge(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PathGame ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
