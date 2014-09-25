// BEGIN CUT HERE

// END CUT HERE
#line 5 "FiveHundredEleven.cpp"
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

class FiveHundredEleven {
    public:
    vector<int> v;
    int n,dp[512][50];

    int solve(int mask,int cnt) {
    	if(mask==511)
    		return 1;
    	if(cnt==n)
    		return 0;
    	int & ret=dp[mask][cnt];
    	if(ret!=-1)
    		return ret;

    	ret=0;
    	int val=0;

    	for(int i=0;i<n;i++) {
    		if((v[i]|mask)==mask) {
    			val++;
    			continue;
    		}
    		if(solve(mask|v[i],cnt+1)==0) {
    			ret=1;
    			return ret;
    		}
    	}

    	if(cnt<val && solve(mask,cnt+1)==0) {
    		ret=1;
    		return ret;
    	}
    	return ret;
    }

    string theWinner(vector <int> cards) {
         //$CARETPOSITION$
    	v=cards;
    	n=v.size();
    	memset(dp,-1,sizeof dp);
    	if(solve(0,0))
    		return "Fox Ciel";
    	else
    		return "Toastman";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 5, 7, 9, 510}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Fox Ciel"; verify_case(0, Arg1, theWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Toastman"; verify_case(1, Arg1, theWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {511}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Toastman"; verify_case(2, Arg1, theWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {5, 58, 192, 256}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Fox Ciel"; verify_case(3, Arg1, theWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FiveHundredEleven ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
