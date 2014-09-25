// BEGIN CUT HERE

// END CUT HERE
#line 5 "RoadOrFlightHard.cpp"
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

typedef long long int lli;

using namespace std;

class RoadOrFlightHard {
    public:
    long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K) {
         //$CARETPOSITION$
    	lli r,f,A[2][41],B[2][41];

    	r=(roadFirst)%roadMod;
    	f=flightFirst%flightMod;
    	for(int i=0;i<=K;i++) {
    		A[0][i]=r;
    		B[0][i]=f;
    	}
    	B[0][0]=r;
    	//cout<<r<<" "<<f<<" "<<K<<endl;
    	for(int j=1;j<N;j++) {

    		r=(r*(lli)roadProd+(lli)roadAdd)%roadMod;
    		f=(f*(lli)flightProd+(lli)flightAdd)%flightMod;

    		//cout<<r<<" "<<f<<endl;
    		A[1][0]=r+min(A[0][0],B[0][0]);
    		B[1][0]=A[1][0];
    		for(int i=1;i<=K;i++) {
    			A[1][i]=r+min(A[0][i],B[0][i]);

    			
    			B[1][i]=f+min(B[0][i],A[0][i-1]);

    			//cout<<i<<" "<<A[1][i]<<" "<<B[1][i]<<endl;
    		}



    		for(int i=0;i<=K;i++)
    			A[0][i]=A[1][i],B[0][i]=B[1][i];
    	}

    	return min(A[0][K],B[0][K]);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 14; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10; int Arg5 = 18; int Arg6 = 1; int Arg7 = 10; int Arg8 = 17; int Arg9 = 1; long long Arg10 = 14LL; verify_case(0, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10; int Arg5 = 1; int Arg6 = 1; int Arg7 = 10; int Arg8 = 17; int Arg9 = 2; long long Arg10 = 11LL; verify_case(1, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10; int Arg5 = 1; int Arg6 = 1; int Arg7 = 6; int Arg8 = 9; int Arg9 = 1; long long Arg10 = 12LL; verify_case(2, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 85739; int Arg2 = 94847; int Arg3 = 93893; int Arg4 = 98392; int Arg5 = 92840; int Arg6 = 93802; int Arg7 = 93830; int Arg8 = 92790; int Arg9 = 3; long long Arg10 = 122365LL; verify_case(3, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     RoadOrFlightHard ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
