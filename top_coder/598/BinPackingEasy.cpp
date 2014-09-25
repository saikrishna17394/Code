// BEGIN CUT HERE

// END CUT HERE
#line 5 "BinPackingEasy.cpp"
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

using namespace std;

class BinPackingEasy {
    public:
    int minBins(vector <int> item) {
         //$CARETPOSITION$
    	int ans=item.size();
    	vector<int> v;
    	for(int i=0;i<ans;i++) {
    		if(item[i]<200)
    			v.push_back(item[i]);
    	}
    	sort(v.begin(),v.end());
    	int i=0,j=v.size()-1;
    	while(i<j) {
    		if(v[i]+v[j]<=300) {
    			ans--;
    			i++;
    		}
    		j--;
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {150, 150, 150, 150, 150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minBins(Arg0)); }
	void test_case_1() { int Arr0[] = {130, 140, 150, 160}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minBins(Arg0)); }
	void test_case_2() { int Arr0[] = {101, 101, 101, 101, 101, 101, 101, 101, 101}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, minBins(Arg0)); }
	void test_case_3() { int Arr0[] = {101, 200, 101, 101, 101, 101, 200, 101, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, minBins(Arg0)); }
	void test_case_4() { int Arr0[] = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minBins(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     BinPackingEasy ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
