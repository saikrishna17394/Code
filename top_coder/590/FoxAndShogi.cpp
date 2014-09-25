// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndShogi.cpp"
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

#define mod 1000000007

using namespace std;

typedef long long int lli;

lli A[51][51];

class FoxAndShogi {
    public:

    int len;
    vector<string> v;

    lli find(int i,int u,int d) {
    	int num=0,start,end;
    	char ch;

    	// cout<<i<<" "<<u<<" "<<d<<endl;
    	lli ans=1;

    	for(int j=u;j<=d;j++)
    		if(v[j][i]!='.') {
    			// cout<<v[i][j]<<" "<<i<<" "<<j<<endl;
    			ch=v[j][i];
    			start=j;
    			num++;
    			break;
    		}

    		// cout<<"Sai "<<num<<" "<<ch<<endl;
    	if(num==0)
    		return 1;

    	if(ch=='U') {
    		num=1;

    		end=start;

    		for(int j=start+1;j<=d;j++) {
    			if(v[j][i]=='D')
    				return (A[end-u+1][num]*find(i,j,d))%mod;

    			if(v[j][i]=='U') {
    				num++;
    				end=j;
    			}
    		}

    		return A[end-u+1][num];
    	}

    	if(ch=='D') {
    		num=1;
    		end=start;

    		// cout<<"krish\n";
    		for(int j=start+1;j<=d;j++) {
    			if(v[j][i]=='U') {
    				lli ans=1;

    				lli val1=0;
    				for(int a=end;a<j;a++) {
    					val1+=(A[a-start][num-1]*find(i,a+1,d))%mod;
    					// cout<<i<<" "<<a+1<<" "<<d<<endl;
    					// cout<<val1<<" "<<num-1<<" "<<a-start<<" "<<find(i,a+1,d)<<endl;
    					//ans=(ans*val1)%mod;
    				}
    				return (ans*val1)%mod;
    			}

    			if(v[j][i]=='D') {
    				num++;
    				end=j;
    			}
    		}
    		return A[d-start+1][num];
    	}



    }
    int differentOutcomes(vector <string> board) {
         //$CARETPOSITION$

    	A[0][0]=1;
    	A[1][0]=1;
    	A[1][1]=1;

    	for(int i=2;i<51;i++) {
    		A[i][0]=1;
    		A[i][i]=1;
    		for(int j=1;j<i;j++)
    			A[i][j]=(A[i-1][j]+A[i-1][j-1])%mod;
    	}
    	v=board;
    	len=v.size();
    	lli ans=1;

    	for(int i=0;i<len;i++) {
    		cout<<i+1<<" "<<ans<<endl;
    		ans=(ans*find(i,0,len-1))%mod;
    		cout<<i+1<<" "<<ans<<endl;
    	}

    	int ans1=ans;
    	return ans1;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".D.",
 "...",
 "..."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, differentOutcomes(Arg0)); }
	void test_case_1() { string Arr0[] = {".D.",
 "...",
 ".U."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, differentOutcomes(Arg0)); }
	void test_case_2() { string Arr0[] = {"DDDDD",
 ".....",
 ".....",
 ".....",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3125; verify_case(2, Arg1, differentOutcomes(Arg0)); }
	void test_case_3() { string Arr0[] = {"DDDDD",
 "U....",
 ".U...",
 "..U..",
 "...U."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900; verify_case(3, Arg1, differentOutcomes(Arg0)); }
	void test_case_4() { string Arr0[] = {"....D..",
 "U....D.",
 "D.D.U.D",
 "U.U...D",
 "....U..",
 "D.U...D",
 "U.U...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2268; verify_case(4, Arg1, differentOutcomes(Arg0)); }
	void test_case_5() { string Arr0[] = {"DDDDDDDDDD",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 ".........."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999937; verify_case(5, Arg1, differentOutcomes(Arg0)); }
	void test_case_6() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, differentOutcomes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     FoxAndShogi ___test;
       ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
