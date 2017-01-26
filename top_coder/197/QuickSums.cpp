// BEGIN CUT HERE

// END CUT HERE
#line 5 "QuickSums.cpp"
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
#define inf 1<<30
using namespace std;

int dp[10][10][101];

class QuickSums {
    public:
    string s;
    int n;

    int solve(int i,int j,int sum) {
    	if(i>j) {
    		if(sum==0)
    			return 0;
    		return -1;
    	}
    	int &ret=dp[i][j][sum];

    	if(ret!=inf)
    		return ret;

    	
    	int num=0;
    	for(int k=i;k<=j;k++) {
    		num=num*10+s[k]-'0';
    		if(num>sum)
    			break;
    		int val=solve(k+1,j,sum-num);
    		if(val!=-1) {
    			if(k==j)
    				ret=min(ret,val);
    			else
	    			ret=min(ret,1+val);
    		}
    	}
    	if(ret==inf)
    		ret=-1;
    	return ret;
    }

    int minSums(string numbers, int sum) {
         //$CARETPOSITION$
    	s=numbers;
    	n=s.length();
    	for(int i=0;i<10;i++)
    		for(int j=0;j<10;j++)
    			for(int k=0;k<=100;k++)
	    			dp[i][j][k]=inf;

    	return solve(0,n-1,sum);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "99999"; int Arg1 = 45; int Arg2 = 4; verify_case(0, Arg2, minSums(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1110"; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, minSums(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0123456789"; int Arg1 = 45; int Arg2 = 8; verify_case(2, Arg2, minSums(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "99999"; int Arg1 = 100; int Arg2 = -1; verify_case(3, Arg2, minSums(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "382834"; int Arg1 = 100; int Arg2 = 2; verify_case(4, Arg2, minSums(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "9230560001"; int Arg1 = 71; int Arg2 = 4; verify_case(5, Arg2, minSums(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    QuickSums ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
