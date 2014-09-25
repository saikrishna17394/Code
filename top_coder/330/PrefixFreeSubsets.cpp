// BEGIN CUT HERE

// END CUT HERE
#line 5 "PrefixFreeSubsets.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
using namespace std;

class PrefixFreeSubsets {
    public:
    int n;
    lli dp[50];
    vector<string> v;
    bool check_prefix(string s,string s1) {
    	int len=min(s.length(),s1.length());
    	int i;
    	for(i=0;i<len;i++)
    		if(s[i]!=s1[i])
    			return false;
    	if(i==s.length())
    		return true;
    	return false;
    }
    lli solve(int idx) {
    	if(idx==n)
    		return 1;
    	lli & ret=dp[idx];
    	if(ret!=-1)
    		return ret;
    	ret=solve(idx+1);

    	int i;
    	for(i=idx+1;i<n;i++) {
    		if(check_prefix(v[idx],v[i]))
    			continue;
    		break;
    	}
    	ret+=solve(i);
    	// cout<<idx<<" "<<ret<<endl;
    	return ret;
    }
    long long cantPrefFreeSubsets(vector <string> words) {
         //$CARETPOSITION$
    	sort(words.begin(),words.end());
    	v=words;
    	n=words.size();
    	memset(dp,-1,sizeof dp);
    	return solve(0);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"hello","hell","hi"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(0, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","b","c","d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 16LL; verify_case(1, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_2() { string Arr0[] = {"a","ab","abc","abcd","abcde","abcdef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(2, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_3() { string Arr0[] = {"a","b","aa","ab","ba","bb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 25LL; verify_case(3, Arg1, cantPrefFreeSubsets(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     PrefixFreeSubsets ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
