// BEGIN CUT HERE

// END CUT HERE
#line 5 "CityMap.cpp"
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

class CityMap {
    public:
    int n,m,A[26];
    string getLegend(vector <string> s, vector <int> v) {
         //$CARETPOSITION$
    	n=s.size();
    	m=s[0].length();

    	memset(A,0,sizeof A);
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++)
    			if(s[i][j]>='A' && s[i][j]<='Z')
    				A[s[i][j]-'A']++;
    	string ans;

    	for(int i=0;i<v.size();i++) {
    		for(int j=0;j<26;j++)
    			if(A[j]==v[i])
    				ans+=('A'+j);
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"M....M",
 "...R.M",
 "R..R.R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "MR"; verify_case(0, Arg2, getLegend(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"XXXXXXXZXYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 8, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ZXY"; verify_case(1, Arg2, getLegend(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...........",
 "...........",
 "...........",
 "..........T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "T"; verify_case(2, Arg2, getLegend(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AIAAARRI.......GOAI.",
 ".O..AIIGI.OAAAGI.A.I",
 ".A.IAAAARI..AI.AAGR.",
 "....IAI..AOIGA.GAIA.",
 "I.AIIIAG...GAR.IIAGA",
 "IA.AOA....I....I.GAA",
 "IOIGRAAAO.AI.AA.RAAA",
 "AI.AAA.AIR.AGRIAAG..",
 "AAAAIAAAI...AAG.RGRA",
 ".J.IA...G.A.AA.II.AA"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16,7,1,35,11,66}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "GOJIRA"; verify_case(3, Arg2, getLegend(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CityMap ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
