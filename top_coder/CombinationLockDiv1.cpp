// BEGIN CUT HERE

// END CUT HERE
#line 5 "CombinationLockDiv1.cpp"
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
#define inf 99999999
using namespace std;

int dp[2500][10][10];

class CombinationLockDiv1 {
    public:
    string s,t;
    int len,dist,ans;
    int minimumMoves(vector <string> P, vector <string> Q) {
         //$CARETPOSITION$
    	s="";
    	t="";
    	for(int i=0;i<P.size();i++)
    		s+=P[i];
    	for(int i=0;i<Q.size();i++)
    		t+=Q[i];
    	len=s.length();

    	for(int i=0;i<10;i++) {
    		for(int j=0;j<10;j++) {
    			dist=t[len-1]-s[len-1];
    			dist=(dist+i-j+100)%10;
    			dist=min(dist,10-dist);
    			if(dist==0)
    				dp[len-1][i][j]=i+j;
    			else
    				dp[len-1][i][j]=inf;
    			// dp[len-1][i][j]=dist+i+j;
    			// cout<<i<<" "<<j<<" "<<dp[len-1][i][j]<<endl;
    		}
    	}

    	for(int l=len-2;l>=0;l--) {
    		for(int i=0;i<10;i++) {
    			for(int j=0;j<10;j++) {
    				dist=t[l]-s[l];
    				dist=(dist+i-j+100)%10;
    				dist=min(dist,10-dist);

    				dp[l][i][j]=inf;
    				if(dist!=0)
    					continue;
    				for(int i1=0;i1<10;i1++) {
    					for(int j1=0;j1<10;j1++) {
    						int val=max(i-i1,0)+max(j-j1,0);
    						dp[l][i][j]=min(dp[l][i][j],dp[l+1][i1][j1]+val);
    					}
    				}
    				// cout<<l<<" "<<i<<" "<<j<<" "<<dp[l][i][j]<<endl;
    			}
    		}
    	}
    	ans=99999999;
    	for(int i=0;i<10;i++) {
    		for(int j=0;j<10;j++) {
    			ans=min(ans,dp[0][i][j]);
    		}
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	// private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"112"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"6","07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","60","7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4567"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"020"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"909"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"4423232218340"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"6290421476245"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(5, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CombinationLockDiv1 ___test;
    ___test.run_test(-1);
    // ___test.test_case_4();
    system("pause");
}
// END CUT HERE 
