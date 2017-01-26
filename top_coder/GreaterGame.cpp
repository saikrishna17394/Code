// BEGIN CUT HERE

// END CUT HERE
#line 5 "GreaterGame.cpp"
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

class GreaterGame {
    public:
    double calc(vector <int> hand, vector <int> sothe) {
         //$CARETPOSITION$
    	sort(hand.begin(),hand.end());
    	sort(sothe.begin(),sothe.end());
    	int n=hand.size();
    	int A[101];
    	memset(A,0,sizeof A);
    	double ans=0;
    	set<int> s;
    	for(int i=1;i<=2*n;i++)
    		s.insert(i);

    	for(int i=0;i<n;i++)
    		s.erase(hand[i]);

    	for(int i=0;i<sothe.size();i++) {
    		if(sothe[i]==-1)
    			continue;
    		s.erase(sothe[i]);
    		bool ok=false;
    		for(int j=0;j<n;j++) {
    			if(A[hand[j]]==0 && hand[j]>sothe[i]) {
    				ans+=1.0;
    				ok=true;
    				A[hand[j]]=1;
    				break;
    			}
    		}
    		if(ok)
    			continue;

    		for(int j=0;j<n;j++) {
    			if(A[hand[j]]==0) {
    				A[hand[j]]=1;
    				break;
    			}
    		}
    	}

    	vector<int> v(s.begin(),s.end());

    	int sz=v.size();
    	if(sz==0)
    		return ans;

    	for(int i=0;i<hand.size();i++) {
    		if(A[hand[i]]==1)
    			continue;

    		double val=1.0/(double)sz;

    		for(int j=0;j<sz;j++)
    			if(hand[i]>v[j])
    				ans+=val;
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,-1,4,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.5; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {6,12,17,14,20,8,16,7,2,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,4,-1,11,3,13,-1,-1,18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(4, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    GreaterGame ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
