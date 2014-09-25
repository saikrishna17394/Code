// BEGIN CUT HERE

// END CUT HERE
#line 5 "BoxesArrangement.cpp"
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
#define inf 100000
using namespace std;

class BoxesArrangement {
    public:
   	string s;
   	map<char,int> m;
   	int len,dp[50][3][3][51][51],a,b,c,A[3];
    
    int solve(int idx,int i,int j,int ac,int bc,int cc) {
    	// cout<<idx<<" "<<ac<<" "<<bc<<" "<<cc<<" "<<len<<endl;	
    	if(idx==len)
    		return 0;
    	int& ret=dp[idx][i][j][ac][bc];
    	if(ret!=-1)
    		return ret;
    	ret=inf;

		for(int k=0;k<3;k++) {
			if(i==j && j==k)
				continue;
			if(k==0)
				ac--;
			else if(k==1)
				bc--;
			else
				cc--;
			if(ac>=0 && bc>=0 && cc>=0) {
				if(m[s[idx]]==k)
					ret=min(ret,solve(idx+1,j,k,ac,bc,cc));
				else
					ret=min(ret,1+solve(idx+1,j,k,ac,bc,cc));
			}
			if(k==0)
				ac++;
			else if(k==1)
				bc++;
			else
				cc++;
		}   
		// cout<<idx<<" "<<i<<" "<<j<<" "<<ac<<" "<<bc<<" "<<cc<<" "<<ret<<endl;	
		return ret;
    }
    int maxUntouched(string boxes) {
         //$CARETPOSITION$
    	s=boxes;
    	len=s.length();
    	if(len<=2)
    		return len;
    	m['A']=0;
    	m['B']=1;
    	m['C']=2;
    	int ans=inf,val;

    	memset(A,0,sizeof A);
    	for(int i=0;i<len;i++) {
    		A[m[s[i]]]++;
    	}
    	a=A[0];
    	b=A[1];
    	c=A[2];
		
		memset(dp,-1,sizeof dp);
    	
    	for(int i=0;i<3;i++) {
    		if(!A[i])
    			continue;
    		A[i]--;
    		for(int j=0;j<3;j++) {
    			if(!A[j])
    				continue;
    			A[j]--;
    			val=0;
    			if(m[s[0]]!=i)
    				val++;
    			if(m[s[1]]!=j)
    				val++;
				ans=min(ans,val+solve(2,i,j,A[0],A[1],A[2]));
				A[j]++;
    		}
    		A[i]++;
    	}
    	ans=len-ans;
    	if(ans<0)
    		return -1;
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAABBBCCC"; int Arg1 = 6; verify_case(0, Arg1, maxUntouched(Arg0)); }
	void test_case_1() { string Arg0 = "AAAAAAAACBB"; int Arg1 = 7; verify_case(1, Arg1, maxUntouched(Arg0)); }
	void test_case_2() { string Arg0 = "CCCCCB"; int Arg1 = -1; verify_case(2, Arg1, maxUntouched(Arg0)); }
	void test_case_3() { string Arg0 = "BAACAABAACAAA"; int Arg1 = 5; verify_case(3, Arg1, maxUntouched(Arg0)); }
	void test_case_4() { string Arg0 = "CBBABA"; int Arg1 = 6; verify_case(4, Arg1, maxUntouched(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     BoxesArrangement ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
