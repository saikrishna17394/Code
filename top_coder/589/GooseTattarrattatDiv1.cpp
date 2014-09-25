// BEGIN CUT HERE

// END CUT HERE
#line 5 "GooseTattarrattatDiv1.cpp"
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

class GooseTattarrattatDiv1 {
    public:
    int g[50][50],len,vis[50],A[50],ans;
    string s;

    void dfs(int i) {
    	vis[i]=1;
    	A[s[i]-'a']++;
    	ans++;
    	for(int j=0;j<len;j++) {
    		if(vis[j]==0 && g[i][j]==1)
    			dfs(j);
    	}
    }

    int getmin(string S) {
         //$CARETPOSITION$
    	s=S;
    	len=s.length();
    	memset(g,0,sizeof g);
    	for(int i=0;i<len;i++) {
    		g[i][len-i-1]=1;
    		for(int j=0;j<len;j++) {
    			if(i==j)
    				continue;
    			if(s[i]==s[j])
    				g[i][j]=1;
    		}
    	}

    	memset(vis,0,sizeof vis);
    	ans=0;
    	for(int i=0;i<len;i++) {
    		if(vis[i]==0) {
    			memset(A,0,sizeof A);
    			dfs(i);
    			int val=0;
    			for(int j=0;j<26;j++)
    				val=max(val,A[j]);
    			ans-=val;
    		}
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "xyyzzzxxx"; int Arg1 = 2; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "abaabb"; int Arg1 = 3; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     GooseTattarrattatDiv1 ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
