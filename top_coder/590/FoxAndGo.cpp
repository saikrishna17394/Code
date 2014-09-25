// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndGo.cpp"
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

typedef pair<int,int> pi;

class FoxAndGo {
    public:
    int vis[19][19],check[19][19],len,num,x,y,size;
    map<pair<int,int>,int> m;
    vector<string> v;

    void dfs(int i,int j) {
    	vis[i][j]=1;
    	size++;

    	if((i+1)<len) {
    		if(v[i+1][j]=='o' && vis[i+1][j]==0)
    			dfs(i+1,j);
    		else if(v[i+1][j]=='.' && check[i+1][j]==0) {
    			check[i+1][j]=1;
    			num++;
    			x=i+1;
    			y=j;
    		}
    		else
    			;
    	}

    	if((j+1)<len) {
    		if(v[i][j+1]=='o' && vis[i][j+1]==0)
    			dfs(i,j+1);
    		else if(v[i][j+1]=='.' && check[i][j+1]==0) {
    			check[i][j+1]=1;
    			num++;
    			x=i;
    			y=j+1;
    		}
    		else
    			;
    	}

    	if(i>0) {
    		if(v[i-1][j]=='o' && vis[i-1][j]==0)
    			dfs(i-1,j);
    		else if(v[i-1][j]=='.' && check[i-1][j]==0) {
    			check[i-1][j]=1;
    			num++;
    			x=i-1;
    			y=j;
    		}
    		else
    			;
    	}

    	if(j>0) {
    		if(v[i][j-1]=='o' && vis[i][j-1]==0)
    			dfs(i,j-1);
    		else if(v[i][j-1]=='.' && check[i][j-1]==0) {
    			check[i][j-1]=1;
    			num++;
    			x=i;
    			y=j-1;
    		}
    		else
    			;
    	}

    }
    int maxKill(vector <string> board) {
         //$CARETPOSITION$
    	
    	memset(vis,0,sizeof vis);
    	v=board;
    	m.clear();

    	int ans=0;
    	len=v.size();
    	for(int i=0;i<len;i++) {
    		for(int j=0;j<len;j++) {
    			if(v[i][j]=='o' && vis[i][j]==0) {
    				memset(check,0,sizeof check);
    				num=0;size=0;
    				dfs(i,j);
    				if(num==0)
    					ans+=size;

    				if(num==1) {
    					if(m.find(make_pair(x,y))==m.end())
    						m[pi(x,y)]=size;
    					else
    						m[pi(x,y)]+=size;
    				}
    			}
    		}
    	}

    	int big=0;

    	for(map<pi,int>::iterator it=m.begin();it!=m.end();it++)
    		big=max(big,(*it).second);

    	return ans+big;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 "..x..",
 ".xox.",
 ".....",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxKill(Arg0)); }
	void test_case_1() { string Arr0[] = {"ooooo",
 "xxxxo",
 "xxxx.",
 "xxxx.",
 "ooooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maxKill(Arg0)); }
	void test_case_2() { string Arr0[] = {".xoxo",
 "ooxox",
 "oooxx",
 "xoxox",
 "oxoox"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, maxKill(Arg0)); }
	void test_case_3() { string Arr0[] = {".......",
 ".......",
 ".......",
 "xxxx...",
 "ooox...",
 "ooox...",
 "ooox..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, maxKill(Arg0)); }
	void test_case_4() { string Arr0[] = {".......",
 ".xxxxx.",
 ".xooox.",
 ".xo.ox.",
 ".xooox.",
 ".xxxxx.",
 "......."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, maxKill(Arg0)); }
	void test_case_5() { string Arr0[] = {"o.xox.o",
 "..xox..",
 "xxxoxxx",
 "ooo.ooo",
 "xxxoxxx",
 "..xox..",
 "o.xox.o"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(5, Arg1, maxKill(Arg0)); }
	void test_case_6() { string Arr0[] = {".......",
 "..xx...",
 ".xooox.",
 ".oxxox.",
 ".oxxxo.",
 "...oo..",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(6, Arg1, maxKill(Arg0)); }
	void test_case_7() { string Arr0[] = {".ox....",
 "xxox...",
 "..xoox.",
 "..xoox.",
 "...xx..",
 ".......",
 "......."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(7, Arg1, maxKill(Arg0)); }
	void test_case_8() { string Arr0[] = {"...................",
 "...................",
 "...o..........o....",
 "................x..",
 "...............x...",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "................o..",
 "..x................",
 "...............x...",
 "...................",
 "..................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(8, Arg1, maxKill(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     FoxAndGo ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
