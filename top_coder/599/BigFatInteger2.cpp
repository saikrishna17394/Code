// BEGIN CUT HERE

// END CUT HERE
#line 5 "BigFatInteger2.cpp"
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

class BigFatInteger2 {
    public:
    map<int,lli> m,m1;

    void fac(int n) {
    	if(n==1)
    		return ;
    	int k=sqrt(n);
    	for(int i=2;i<=k;i++) {
    		if(n%i==0) {
    			m[i]++;
    			fac(n/i);
    			return ;
    		}
    	}
    	m[n]++;
    }
    void fac1(int n) {
    	// cout<<"nay "<<n<<endl;
    	if(n==1)
    		return ;
    	int k=sqrt(n);
    	for(int i=2;i<=k;i++) {
    		// cout<<n<<" "<<k<<endl;
    		if(n%i==0) {
    			m1[i]++;
    			// cout<<n/i
    			fac1(n/i);
    			return ;
    		}
    	}
    	m1[n]++;
    }

    string isDivisible(int A, int B, int C, int D) {
         //$CARETPOSITION$
    	if(C==1)
    		return "divisible";
    	m.clear();
    	fac(A);
    	m1.clear();
    	fac1(C);

    	for(map<int,lli>::iterator it=m.begin();it!=m.end();it++) {
    		it->second*=(lli)B;
    	}
    	for(map<int,lli>::iterator it=m1.begin();it!=m1.end();it++) {
    		it->second*=(lli)D;
    	}

    	// cout<<m.size()<<" "<<m1.size()<<" dude\n";
    	for(map<int,lli>::iterator it=m1.begin();it!=m1.end();it++) {
    		// cout<<it->first<<" "<<it->second<<endl;
    		if(m.find(it->first)==m.end())
    			return "not divisible";
    		if(it->second>m[it->first])
    			return "not divisible";
    	}
    	return "divisible";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	// private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; string Arg4 = "divisible"; verify_case(0, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 6; int Arg3 = 1; string Arg4 = "not divisible"; verify_case(1, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1000000000; int Arg3 = 200000000; string Arg4 = "divisible"; verify_case(2, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 100; int Arg2 = 4; int Arg3 = 200; string Arg4 = "not divisible"; verify_case(3, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 999999937; int Arg1 = 1000000000; int Arg2 = 999999929; int Arg3 = 1; string Arg4 = "not divisible"; verify_case(4, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; int Arg3 = 1; string Arg4 = "divisible"; verify_case(5, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BigFatInteger2 ___test;
    ___test.run_test(-1);
   	// ___test.test_case_1();
    system("pause");
}
// END CUT HERE 
