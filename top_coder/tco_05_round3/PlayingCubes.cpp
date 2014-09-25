// BEGIN CUT HERE

// END CUT HERE
#line 5 "PlayingCubes.cpp"
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

class PlayingCubes {
    public:
    int n,g[10][50],m,match[50],vis[50];

    bool dfs(int i) {

    	for(int j=0;j<m;j++) {
    		if(vis[j] || g[i][j]==0)
    			continue;
    		vis[j]=1;

    		if(match[j]==-1 || dfs(match[j])) {
    			match[j]=i;
    			return true;
    		}
    	}
    	return false;
    }
    vector <int> composeWords(vector <string> cubes, vector <string> words) {
         //$CARETPOSITION$
    	n=cubes.size();
    	vector<int> res;
    	int ans;

    	for(int k=0;k<words.size();k++) {
    		m=words[k].length();
    		memset(g,0,sizeof g);
    		for(int i=0;i<n;i++) {
    			for(int j=0;j<m;j++) {
    				for(int l=0;l<6;l++)
    					if(cubes[i][l]==words[k][j])
    						g[i][j]=1;
    			}
    		}

    		ans=0;
    		memset(match,-1,sizeof match);
    		for(int i=0;i<n;i++) {
    			memset(vis,0,sizeof vis);
    			if(dfs(i))
    				ans++;
    		}
    		if(ans==m)
    			res.push_back(k);
    	}
    	return res;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ABCDEF", "DEFGHI", "OPQRST", "ZZZZZZ", "YYYYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CAT", "DOG", "PIZZA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, composeWords(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ABCDEF", "DEFGHI", "OPQRST", "MNZLSA", "QEIOGH", "IARJGS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"DOG", "CAT", "MOUSE", "BIRD", "CHICKEN", "PIG", "ANIMAL"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, composeWords(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AAAAAA", "AAAAAA", "AAAAAA", "AAAAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AA", "AAA", "AAAA", "AAAAA", "AAAAAA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, composeWords(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"ABCDEF", "DEFGHI", "OPQRST", "ZZZZZZ", "ZZZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CAT", "DOG", "PIZZA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, composeWords(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PlayingCubes ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
