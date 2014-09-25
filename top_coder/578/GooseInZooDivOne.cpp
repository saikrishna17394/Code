// BEGIN CUT HERE

// END CUT HERE
#line 5 "GooseInZooDivOne.cpp"
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
#define mod 1000000007
#define lli long long int
using namespace std;
int dx[]={+1,-1,0,0};
int dy[]={0,0,+1,-1};

int dp[2501][2501];
class GooseInZooDivOne {
    public:
    int n,m,d,vis[50][50],val,val1;
    vector<string> v;

    bool check(int i,int j) {
    	if(vis[i][j]==1 || v[i][j]=='.')
    		return false;
    	return true;
    }

    void dfs(int i,int j) {
    	vis[i][j]=1;
    	val++;

    	for(int a=i-d;a<=(i+d);a++) {
    		if(a<0 || a>=n)
    			continue;
    		for(int b=j-d;b<=(j+d);b++) {
    			if(b<0 || b>=m)
    				continue;
    			if(check(a,b) && abs(i-a)+abs(j-b)<=d)
    				dfs(a,b);
    		}
    	}

    }

    int count(vector <string> field, int dist) {
         //$CARETPOSITION$
    	v=field;
    	n=field.size();
    	m=v[0].length();
    	d=dist;
    	int o=0,e=0;
    	val1=0;
    	memset(vis,0,sizeof vis);
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			if(v[i][j]=='v' && vis[i][j]==0) {
    				val=0;
    				dfs(i,j);
    				// cout<<i<<" "<<j<<" "<<val<<endl;
    				if(val&1)
    					o++;
    				else
    					e++;
    			}
    		}
    	}

    	int ans=1;
    	// cout<<o<<" "<<e<<endl;
    	for(int i=0;i<e;i++) {
    		ans*=2;
    		ans%=mod;
    	}
    	// cout<<ans<<endl;
    	memset(dp,0,sizeof dp);
    	dp[0][0]=1;
    	for(int i=1;i<=2500;i++) {
    		dp[i][0]=1;
    		for(int j=1;j<=i;j++)
    			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
    	}

    	val=1;

    	for(int i=2;i<=o;i+=2) {
    		val+=dp[o][i];
    		val%=mod;
    	}

    	lli num=(lli)ans*(lli)val;
    	num%=mod;
    	ans=num;
    	ans=(ans+mod-1)%mod;
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 898961330; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    GooseInZooDivOne ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
