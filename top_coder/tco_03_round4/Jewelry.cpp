// BEGIN CUT HERE

// END CUT HERE
#line 5 "Jewelry.cpp"
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

lli dp[31][31];
lli A[30][30001],B[31][30001];

class Jewelry {
    public:

    long long howMany(vector <int> values) {
         //$CARETPOSITION$
    	memset(dp,0,sizeof dp);
    	dp[0][0]=1;
    	for(int i=1;i<=30;i++) {
    		dp[i][0]=1;
    		for(int j=1;j<=i;j++)
    			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
    	}

    	map<int,int> m;
    	for(int i=0;i<values.size();i++)
    		m[values[i]]++;

    	vector<ii> v(m.begin(),m.end());
    	int n=v.size();

    	memset(A,0,sizeof A);
    	memset(B,0,sizeof B);
    	
		A[0][0]=1;
		int num=v[0].first;
		for(int a=0;a<v[0].second;a++) {
			A[0][num]=dp[v[0].second][a+1];
			num+=v[0].first;
		}

    	for(int i=1;i<n;i++) {
    		for(int j=0;j<30001;j++) {
    			A[i][j]=A[i-1][j];
    			int val=v[i].first;
    			for(int k=0;k<v[i].second;k++) {
    				if(j>=val)
    					A[i][j]+=(A[i-1][j-val]*dp[v[i].second][k+1]);
    				else
    					break;
    				val+=v[i].first;
    			}
    		}
    	}
    	lli ans=0;

    	B[n][0]=1;

    	for(int i=n-1;i>=0;i--) {
    		int num=v[i].first;
    		for(int k=1;k<=v[i].second;k++) {

    			for(int j=num;j<30001;j++) {
    				
    				for(int a=0;a<=(v[i].second-k);a++) {
						if(i==0) {
							if(j==a*v[i].first)
								ans+=(dp[v[i].second][k]*dp[v[i].second-k][a]*B[i+1][j-num]);
						}
						else {
							if(j>=a*v[i].first)
								ans+=(dp[v[i].second][k]*dp[v[i].second-k][a]*B[i+1][j-num]*A[i-1][j-a*v[i].first]);
						}
    				}

    			}
    			num+=v[i].first;
    		}

    		for(int j=0;j<30001;j++) {			
	    		int val=v[i].first;
	    		B[i][j]=B[i+1][j];
	    		for(int k=0;k<v[i].second;k++) {
	    			if(j>=val)
	    				B[i][j]+=(B[i+1][j-val]*dp[v[i].second][k+1]);
	    			else
	    				break;
	    			val+=v[i].first;
	    		}
	    	}
    	}

		return ans;    	
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,5,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arr0[] = {1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 18252025766940LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arr0[] = {7,7,8,9,10,11,1,2,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 607LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { int Arr0[] = {123,217,661,678,796,964,54,111,417,526,917,923}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Jewelry ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
