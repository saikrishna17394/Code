// BEGIN CUT HERE

// END CUT HERE
#line 5 "SkiResorts.cpp"
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

class SkiResorts {
    public:
    lli D[50][50][51],edge_cost[50][50];

    long long minCost(vector <string> road, vector <int> altitude) {
         //$CARETPOSITION$
    	int n=road.size();
    	lli inf=(lli)1e14;
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<n;j++) {
    			if(i==j) {
    				edge_cost[i][j]=0;
    			}
    			else {
    				if(road[i][j]=='Y')
	    				edge_cost[i][j]=(lli)max(0,altitude[j]-altitude[i]);
	    			else
	    				edge_cost[i][j]=inf;
    			}
    		}
    	}

    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			D[i][j][0]=edge_cost[i][j];

    	for(int k=1;k<=n;k++) {	
	    	for(int i=0;i<n;i++) {
	    		for(int j=0;j<n;j++) {
	    			D[i][j][k]=min(D[i][j][k-1],D[i][k-1][k-1]+D[k-1][j][k-1]);
	    		}
	    	}
	    }
	    if(D[0][n-1][n]==inf)
	    	return -1;
	    return D[0][n-1][n];
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 20, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(0, Arg2, minCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(1, Arg2, minCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYN",
 "YNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {573, 573, 573}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(2, Arg2, minCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 12LL; verify_case(3, Arg2, minCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     SkiResorts ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
