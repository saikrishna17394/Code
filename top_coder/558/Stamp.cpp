// BEGIN CUT HERE

// END CUT HERE
#line 5 "Stamp.cpp"
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

class Stamp {
    public:
    map<char,int> m;
    int check[50][51],dp[50][4];
    string s;
    int len,sc,pc,inf;

    int solve(int idx,int i,int col) {
		if(idx==len)
			return 0;
		if((idx+i)>len)
			return inf;

		if(check[idx][i]==-1)
			return inf;
		if(check[idx][i]>0 && col>0 &&check[idx][i]!=col)
			return inf;

		int &ret=dp[idx][col];
		if(ret!=-1)
			return ret;
		ret=inf;
		int color=max(col,check[idx][i]);

		for(int j=1;j<i;j++)
			ret=min(ret,pc+solve(idx+j,i,color));
		ret=min(ret,pc+solve(idx+i,i,0));
		return ret;
    }
    int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
         //$CARETPOSITION$
    	m['R']=1;
    	m['B']=2;
    	m['G']=3;
    	m['*']=0;
    	s=desiredColor;
    	sc=stampCost;
    	pc=pushCost;
    	len=s.length();
    	inf=999999999;

    	for(int i=0;i<len;i++)
    		check[i][1]=m[s[i]];

    	for(int j=2;j<=len;j++) {
    		for(int i=0;i+j<=len;i++) {
    			if(check[i][j-1]==-1)
    				check[i][j]=-1;
    			else if(check[i+j-1][1]==0 || check[i][j-1]==0)
    				check[i][j]=max(check[i][j-1],check[i+j-1][1]);
    			else if(check[i][j-1]==check[i+j-1][1])
    				check[i][j]=check[i][j-1];
    			else
    				check[i][j]=-1;
    		}
    	}
    	int ans=inf,val;

    	for(int i=1;i<=len;i++) {
    		val=sc*i;
    		memset(dp,-1,sizeof dp);
    		val+=solve(0,i,0);
    		ans=min(ans,val);
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
		// {"RR*GG", 1, 100000}
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RR*GG"; int Arg1 = 1; int Arg2 = 100000; int Arg3 = 300002; verify_case(0, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "R**GB*"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(1, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "BRRB"; int Arg1 = 2; int Arg2 = 7; int Arg3 = 30; verify_case(2, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "R*RR*GG"; int Arg1 = 10; int Arg2 = 58; int Arg3 = 204; verify_case(3, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "*B**B**B*BB*G*BBB**B**B*"; int Arg1 = 5; int Arg2 = 2; int Arg3 = 33; verify_case(4, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG"; int Arg1 = 7; int Arg2 = 1; int Arg3 = 30; verify_case(5, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     Stamp ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
