// BEGIN CUT HERE

// END CUT HERE
#line 5 "HexagonalBoard.cpp"
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
int dx[]={+1,-1,0,0,+1,-1};
int dy[]={0,0,+1,-1,-1,+1};

class HexagonalBoard {
    public:
    vector<string> s;
    int n,vis[50][50];

    bool check(int a,int b) {
    	if(a<0 || a>=n || b<0 || b>=n || s[a][b]!='X')
    		return false;
    	return true;
    }

    bool dfs(int i,int j) {
    	int x,y;
    	for(int k=0;k<6;k++) {
    		x=i+dx[k];
    		y=j+dy[k];
    		if(check(x,y)) {
    			if(vis[x][y]==-1) {
    				vis[x][y]=vis[i][j]^1;
    				if(!dfs(x,y))
    					return false;
    			}
    			if(vis[x][y]==vis[i][j])
    				return false;
    		}
    	}
    	return true;
    }
    int minColors(vector <string> board) {
         //$CARETPOSITION$
    	s=board;
    	n=s.size();

    	int val=0,val1=0;

    	for(int i=0;i<n;i++) {
    		for(int j=0;j<n;j++) {
    			if(s[i][j]=='X') {
    				val++;
    				for(int k=0;k<6;k++)
    					if(check(i+dx[k],j+dy[k]))
    						val1++;
    			}
    		}
    	}
    	if(val==0)
    		return 0;
    	if(val1==0)
    		return 1;
    	memset(vis,-1,sizeof vis);
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<n;j++) {
    			if(s[i][j]=='X' && vis[i][j]==-1) {
    				vis[i][j]=0;
    				if(!dfs(i,j))
    					return 3;
    			}
    		}
    	}
    	return 2;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"---",
 "---",
 "---"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minColors(Arg0)); }
	void test_case_1() { string Arr0[] = {"-X--",
 "---X",
 "----",
 "-X--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minColors(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXX",
 "---X",
 "---X",
 "---X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minColors(Arg0)); }
	void test_case_3() { string Arr0[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minColors(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     HexagonalBoard ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
