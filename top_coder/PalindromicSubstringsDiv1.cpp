// BEGIN CUT HERE

// END CUT HERE
#line 5 "PalindromicSubstringsDiv1.cpp"
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

double dp[5000][5000];

class PalindromicSubstringsDiv1 {
    public:
    string s;
    int len;

    double expectedPalindromes(vector <string> S1, vector <string> S2) {
         //$CARETPOSITION$
    	s="";
    	for(int i=0;i<S1.size();i++)
    		s+=S1[i];
    	for(int i=0;i<S2.size();i++)
    		s+=S2[i];
    	len=s.length();
    	double ans=(double)len;
    	for(int i=0;i<len;i++)
    		dp[i][i]=1.0;
    	double val=1;
    	val/=26.0;

    	// cout<<s<<" "<<len<<" "<<ans<<endl;
    	for(int i=0;i<(len-1);i++) {
    		if(s[i]==s[i+1]) {
    			if(s[i]=='?')
	    			dp[i][i+1]=val;
	    		else
	    			dp[i][i+1]=1.0;
    		}
    		else {
    			if(s[i]=='?' || s[i+1]=='?')
    				dp[i][i+1]=val;
    			else
    				dp[i][i+1]=0;
    		}
    		ans+=(double)dp[i][i+1];
    		// cout<<i<<" "<<dp[i][i+1]<<" "<<ans<<endl;
    	}

    	for(int k=2;k<len;k++) {
    		for(int i=0;(i+k)<len;i++) {
	    		dp[i][i+k]=dp[i+1][i+k-1];
	    		if(s[i]==s[i+k]) {
	    			if(s[i]=='?')
		    			dp[i][i+k]*=val;
		    		else
		    			dp[i][i+k]*=1.0;
	    		}
	    		else {
	    			if(s[i]=='?' || s[i+k]=='?')
	    				dp[i][i+k]*=val;
	    			else
	    				dp[i][i+k]=0;
	    		}
	    		ans+=dp[i][i+k];
    		}
    	}

    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","a",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(0, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"z??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.115384615384615; verify_case(1, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ab","c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"??","a?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.315088757396449; verify_case(2, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(3, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ab?def","?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"f??a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.545971779699588; verify_case(4, Arg2, expectedPalindromes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PalindromicSubstringsDiv1 ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
