// BEGIN CUT HERE

// END CUT HERE
#line 5 "RGBStreet.cpp"
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
#define inf 999999999
using namespace std;

class RGBStreet {
    public:

    int A[20][3],B[20][3];
    int estimateCost(vector <string> houses) {
         //$CARETPOSITION$
    	int len=houses.size(),ans;
    	memset(B,0,sizeof B);
    	for(int i=0;i<len;i++) {
    		int k=0;
    		for(int j=0;j<houses[i].length() && k<3;j++) {
    			if(houses[i][j]==' ')
    				k++;
    			else {
    				B[i][k]=B[i][k]*10+houses[i][j]-'0';
    			}
    		}
    	}

    	for(int i=0;i<3;i++)
    		A[0][i]=B[0][i];

    	for(int i=1;i<len;i++) {
    		for(int j=0;j<3;j++) {
    			A[i][j]=inf;

    			for(int k=0;k<3;k++) {
    				if(k==j)
    					continue;
    				A[i][j]=min(A[i][j],A[i-1][k]+B[i][j]);
    			}
    		}
    	}

    	ans=A[len-1][0];
    	ans=min(A[len-1][1],ans);
    	ans=min(A[len-1][2],ans);
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 100 100", "100 1 100", "100 100 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, estimateCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 100 100", "100 100 100", "1 100 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 102; verify_case(1, Arg1, estimateCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"26 40 83", "49 60 57", "13 89 99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 96; verify_case(2, Arg1, estimateCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"30 19 5", "64 77 64", "15 19 97", "4 71 57", "90 86 84", "93 32 91"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 208; verify_case(3, Arg1, estimateCost(Arg0)); }
	void test_case_4() { string Arr0[] = {"71 39 44", "32 83 55", "51 37 63", "89 29 100", 
 "83 58 11", "65 13 15", "47 25 29", "60 66 19"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 253; verify_case(4, Arg1, estimateCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     RGBStreet ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
