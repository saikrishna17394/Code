// BEGIN CUT HERE

// END CUT HERE
#line 5 "MaxTriangle.cpp"
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


class MaxTriangle {
    public:
    map<int,int> m;
    double calculateArea(int A, int B) {
         //$CARETPOSITION$
    	int lim=max(A,B),cnt=0;
    	// lim=2000000000;
    	m[0]=1;
    	for(int i=1;i*i<=lim;i++) {
    		// cout<<i<<endl;
    		m[i*i]=1;
    		cnt++;
    	}
    	bool ok=false;

    	for(int i=1;i<=cnt;i++) {
    		if(m.find(A-i*i)!=m.end()) {
    			ok=true;
    			break;
    		}
    	}
    	if(!ok)
    		return (double)-1;
    	ok=false;
    	for(int i=1;i<=cnt;i++) {
    		if(m.find(B-i*i)!=m.end()) {
    			ok=true;
    			break;
    		}
    	}
    	if(!ok)
    		return (double)-1;
    	double ans;
    	ans=sqrt(A)*sqrt(B);
    	ans/=2.0;
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 0.5; verify_case(0, Arg2, calculateArea(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 7; double Arg2 = -1.0; verify_case(1, Arg2, calculateArea(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 41; int Arg1 = 85; double Arg2 = 29.5; verify_case(2, Arg2, calculateArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MaxTriangle ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
