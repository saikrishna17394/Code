// BEGIN CUT HERE

// END CUT HERE
#line 5 "PowerOfThree.cpp"
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

class PowerOfThree {
    public:
    vector<lli> v1,v2;

    bool check(vector<lli> v,lli a) {
    	if(v.size()==0) {
    		if(a==0)
	    		return true;
	    	return false;
    	}
    	// cout<<"yo\n";
    	lli num=v[v.size()-1];
    	// cout<<"yo123\n";
 	 	
    	for(int i=v.size()-2;i>=0;i--) {
    		if(num>a)
    			num-=v[i];
    		else
    			num+=v[i];
    	}

    	if(num==a)
    		return true;
    	return false;
    }

    string ableToGet(int x, int y) {
         //$CARETPOSITION$
    	x=abs(x);
    	y=abs(y);
    	lli a;
    	if(x==0 && y==0)
    		return "Possible";
    	// cout<<"yo\n";
    	// cout<<x<<" "<<y<<endl;
    	for(int k=1;k<20;k++) {
    		// cout<<"yo\n";
    		int val=1<<k,mask;
    		for(int i=0;i<val;i++) {
    			// cout<<"yo\n";
    			mask=i;
    			v1.clear();
    			v2.clear();
    			a=1;
    			for(int j=0;j<k;j++) {
    				// cout<<"yodaf3\n";
    				// cout<<
    				if(mask&1)
    					v1.push_back(a);
    				else
    					v2.push_back(a);
    				// cout<<j<<" dude\n";
    				a*=3;
    				mask/=2;
    			}
    			// cout<<"man\n";
    			if(check(v1,(lli)x) && check(v2,(lli)y)) {
    				// cout<<k<<endl;
    				return "Possible";
    			}
    		}
    	}
    	return "Impossible";
    	
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 2; string Arg2 = "Possible"; verify_case(1, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 9; string Arg2 = "Impossible"; verify_case(2, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Impossible"; verify_case(4, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = -6890; int Arg1 = 18252; string Arg2 = "Possible"; verify_case(5, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1000000000; int Arg1 = -1000000000; string Arg2 = "Impossible"; verify_case(6, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 0; int Arg1 = 0; string Arg2 = "Possible"; verify_case(7, Arg2, ableToGet(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PowerOfThree ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
