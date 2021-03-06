// BEGIN CUT HERE

// END CUT HERE
#line 5 "JanuszTheBusinessman.cpp"
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

class JanuszTheBusinessman {
    public:
    int makeGuestsReturn(vector <int> a, vector <int> d) {
         //$CARETPOSITION$
    	int n=a.size();

    	vector<int> dp(n+1);
    	vector<ii> v(n);

    	for(int i=0;i<n;i++)
    		v[i]=ii(a[i],d[i]);
    	sort(v.begin(),v.end());

    	set<int> v1;
    	int tim=v[0].second;

    	for(int i=1;i<n;i++) {
    		if(v[i].first>tim) {
    			v1.insert(i);
    		}
    		tim=max(tim,v[i].second);
    	}

    	dp[n]=0;

    	int tim=9999;

    	int val=0;

    	for(int i=n-1;i>=0;i--) {
    		dp[i]=max(dp[i+1],1);


    		if(v[i].second<)
    		// cout<<i<<" "<<v[i].first<<" "<<v[i].second<<" :";
    		for(int j=i+1;j<n;j++) {
    			if(v[i].second<v[j].first) {
    				dp[i]=max(dp[i],dp[j]+1);
    				break;
    			}
    		}
    		val++;

    		if(v1.find(i)!=v1.end()) {
    			ans+=(val-dp[i]);
    			val=0;
    		}
    		// cout<<dp[i]<<endl;
    	}
    	return n-dp[0];
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 10, 6}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 11, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 10, 23, 34, 45, 123, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25, 12, 40, 50, 48, 187, 365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {8, 12, 20, 30, 54, 54, 68, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13, 31, 30, 53, 55, 70, 80, 76}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(4, Arg2, makeGuestsReturn(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    JanuszTheBusinessman ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
