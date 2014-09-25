// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAverageSequence.cpp"
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

int dp[2][41][2][1600];

class FoxAverageSequence {
    public:
    int theCount(vector <int> v) {
         //$CARETPOSITION$
    	memset(dp,0,sizeof dp);

    	int n=v.size();

    	if(n==1) {
    		if(v[0]!=-1)
    			return 1;
    		return 41;
    	}

    	for(int j=0;j<=40;j++) {
    		if(v[0]!=j && v[0]!=-1)
    			continue;
    		for(int k=0;k<=40;k++) {
    			if(v[1]!=k && v[1]!=-1)
    				continue;
    			if(j>k) {
					// if(k==j)
						dp[1][k][1][j+k]++;
					// cout<<1<<" "<<j<<" "<<k<<" "<<j+k<<" "<<dp[1][k][0][j+k]<<endl;
    			}
    			else if(j==k){
	    				dp[1][k][0][j+k]++;
    			}
    			else
    				;
    		}
    	}

    	for(int i=2;i<n;i++) {

    		for(int j=0;j<=40;j++)
    			for(int k=0;k<2;k++)
    				for(int sum=0;sum<=(40*i);sum++)
    					dp[i&1][j][k][sum]=0;

    		for(int a=0;a<=40;a++) {
    			if(v[i]!=a && v[i]!=-1) {
    				continue;
    			}
	    		for(int j=0;j<2;j++) {
	    			for(int k=0;k<=40;k++) {
	    				if(j==1 && k>a)
	    					continue;
	    				for(int sum=0;sum<=(40*i);sum++) {
	    					if((a*i) <= sum) {
	    						if(k>a) {
	    							dp[i&1][a][1][sum+a]+=dp[(i-1)&1][k][j][sum];
	    							dp[i&1][a][1][sum+a]%=mod;
	    							// if(dp[(i-1)&1][k][j][sum])
	    							// 	cout<<2<<" "<<a<<" "<<k<<" "<<j<<" "<<sum<<" "<<dp[0][a][1][sum+a]<<endl;
	    						}
	    						else {
	    							dp[i&1][a][0][sum+a]+=dp[(i-1)&1][k][j][sum];
	    							dp[i&1][a][0][sum+a]%=mod;
	    							// if(dp[(i-1)&1][k][j][sum])	    							
		    						// 	cout<<2<<" "<<a<<" "<<k<<" "<<j<<" "<<sum<<" "<<dp[0][a][0][sum+a]<<endl;
	    						}

	    					}
	    				}
	    			}
	    		}
	    	}
    	}

    	int ans=0;

    	for(int j=0;j<=40;j++) {
    		for(int k=0;k<2;k++) {
    			for(int sum=0;sum<1600;sum++) {
    				ans+=dp[(n-1)&1][j][k][sum];
    				ans%=mod;
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, 0, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 579347890; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 12, 25, 0, 18, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FoxAverageSequence ___test;
    ___test.run_test(-1);
    system("pause");

    // ___test.test_case_1();
}
// END CUT HERE 
