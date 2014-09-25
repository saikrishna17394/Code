// BEGIN CUT HERE

// END CUT HERE
#line 5 "HamiltonPath.cpp"
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

class HamiltonPath {
    public:
    vector<string> v;
    int n,vis[50],A[50],num;
    bool dfs(int i,int par) {
    	vis[i]=1;
    	num++;
    	for(int j=0;j<n;j++) {
    		if(i==j || j==par || v[i][j]=='N')
    			continue;
    		if(vis[j])
    			return false;
    		if(!dfs(j,i))
    			return false;
    	}
    	return true;
    }
    int countPaths(vector <string> roads) {
         //$CARETPOSITION$
    	v=roads;
    	n=v.size();
    	int val;
    	for(int i=0;i<n;i++) {
    		val=0;
    		for(int j=0;j<n;j++) {
    			if(v[i][j]=='Y')
    				val++;
    		}
    		if(val>2)
    			return 0;
    	}
    	// cout<<"dude\n";
    	memset(vis,0,sizeof vis);
    	int chains=0,points=0;

    	for(int i=0;i<n;i++) {
    		num=0;
    		// cout<<i<<" "<<vis[i]<<endl;
    		if(vis[i])
    			continue;
    		if(!dfs(i,-1))
    			return 0;
    		// cout<<i<<" "<<vis[i]<<endl;
    		if(num==1)
    			points++;
    		else
	    		chains++;
    	}
    	// cout<<points<<" kir "<<chains<<endl;
    	lli ans=1;
    	for(lli i=1;i<=(points+chains);i++) {
    		ans=(ans*i)%mod;
    	}
    	for(int i=0;i<chains;i++) {
    		ans=(ans*2)%mod;
    	}
    	return (int)ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, countPaths(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countPaths(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYY",
 "YNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countPaths(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(3, Arg1, countPaths(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    HamiltonPath ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
