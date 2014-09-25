// BEGIN CUT HERE

// END CUT HERE
#line 5 "AstronomicalRecords.cpp"
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

class AstronomicalRecords {
    public:
    vector<lli> a,b;
    int dp[50][50];

    int solve(int i,int j,lli ax,lli bx) {
    	if(i==a.size() || j==b.size())
    		return 0;
    	int& ret=dp[i][j];
    	if(ret!=-1)
    		return ret;

    	if(a[i]*ax==b[j]*bx)
    		ret=1+solve(i+1,j+1,ax,bx);
    	else
    		ret=max(solve(i+1,j,ax,bx),solve(i,j+1,ax,bx));
    	// cout<<i<<" "<<j<<" "<<ret<<endl;
    	return ret;
    }
    int minimalPlanets(vector <int> A, vector <int> B) {
         //$CARETPOSITION$
    	a.clear();
    	b.clear();
    	for(int i=0;i<A.size();i++)
    		a.push_back(A[i]);
    	for(int i=0;i<B.size();i++)
    		b.push_back(B[i]);

    	int ans=A.size()+B.size();
    	int val=0;
    	for(int i=0;i<A.size();i++) {
    		for(int j=0;j<B.size();j++) {
    			memset(dp,-1,sizeof dp);
    			val=max(val,solve(i,j,b[j],a[i]));
    			// cout<<i<<" "<<j<<" "<<val<<endl;
    		}
    	}
    	ans-=val;
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,1,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,2,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,6,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,3,2,3,2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {600,700,600,700,600,700,600}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(2, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,7,8,9,10,11,12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {100000000,200000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {200000000,100000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, minimalPlanets(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     AstronomicalRecords ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
