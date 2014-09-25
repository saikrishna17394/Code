// BEGIN CUT HERE

// END CUT HERE
#line 5 "RookAttack.cpp"
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

int g[300][300],n,m,a,b,ans,match[300],vis[300];

class RookAttack {
    public:
    bool dfs(int i) {

    	for(int j=0;j<m;j++) {
    		if(vis[j] || !g[i][j])
    			continue;
    		vis[j]=1;
    		if(match[j]==-1 || dfs(match[j])) {
    			match[j]=i;
    			return true;
    		}
    	}
    	return false;
    }
    int howMany(int rows, int cols, vector <string> cutouts) {
         //$CARETPOSITION$
    	string s="";
    	n=rows;
    	m=cols;

    	for(int i=0;i<cutouts.size();i++)
    		s+=(cutouts[i]+" , ") ;
    	int idx=0,len=s.length();

    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++)
    			g[i][j]=1;
    	while(idx<len) {
    		while(!(s[idx]>='0' && s[idx]<='9') && idx<len)
    			idx++;
    		if(idx==len)
    			break;
    		a=0;
    		b=0;
    		while(s[idx]>='0' && s[idx]<='9') {
    			a=a*10+s[idx]-'0';
    			idx++;
    		}
    		idx++;

    		while((s[idx]>='0' && s[idx]<='9') && idx<len) {
    			b=b*10+s[idx]-'0';
    			idx++;
    		}
    		idx++;
    		g[a][b]=0;
    	}

    	ans=0;
    	memset(match,-1,sizeof match);
    	for(int i=0;i<n;i++) {
    		memset(vis,0,sizeof vis);
    		if(dfs(i))
    			ans++;
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 8; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"0 0","0 1","1 1","1 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0 0","1 0","1 1","2 0","2 1","2 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0 0","1 2","2 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 200; int Arg1 = 200; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 200; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    RookAttack ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
