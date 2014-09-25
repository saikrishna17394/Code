// BEGIN CUT HERE

// END CUT HERE
#line 5 "PalindromeMatrix.cpp"
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

class PalindromeMatrix {
    public:
    int R[14],C[14],r,c,ans,rc;
    vector<string> A,B;

    void rec(int i,int left) {
    	if(left==0) {
    		go();
    		return;
    	}
    	if(i==c)
    		return;
    	else {
    		if(left) {
	    		C[i]=1;
	    		int val=r/2;
	    		val=1<<val;
	    		for(int j=0;j<val;j++) {
	    			int num=j;
	    			for(int k=0;k<val/2;k++) {
	    				B[k][i]=num&1;
	    				B[r-k-1][i]=B[k][i];
	    				num>>=1;
	    			}
		    		rec(i+1,left-1);
	    		}
	    	}

	    	for(int j=0;j<r;j++)
	    		B[j][i]=A[j][i];

    		C[i]=0;
    		rec(i+1,left);
    	}
    }

    void go() {
    	vector<int> v;

    	for(int i=0;i<r;i++) {
    		bool ok=true;
    		int val=0;
			for(int j=0;j<c/2;j++) {
				if(B[i][j]!=B[i][c-j-1]) {
					if(C[j]==1 && C[c-j-1]==1) {
						ok=false;
						break;
					}
					if(C[j]==1) {
						B[i][c-j-1]^=1;
					}
					else if(C[c-j-1]==1) {
						B[i][j]^=1;
					}
					else
						B[i][j]^=1;
				}
			}
			if(ok) {
				for(int j=0;j<c;j++)
					if(A[i][j]!=B[i][j])
						val++;
				v.push_back(val);
			}
		}
		if(v.size()<rc)
			return;
		sort(v.begin(),v.end());
		int val1=0;
		for(int i=0;i<rc;i++)
			val1+=v[i];
		ans=min(ans,val1);
    }

    int minChange(vector <string> v, int rowCount, int columnCount) {
         //$CARETPOSITION$
    	A=v;
    	B=A;
    	rc=rowCount;
    	r=A.size();
    	c=A[0].length();
    	memset(R,0,sizeof R);
    	memset(C,0,sizeof C);
    	
    	ans=r*c;
    	cout<<ans<<endl;
    	rec(0,columnCount);

    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; verify_case(1, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"01"
,"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(2, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1110"
,"0001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(3, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 8; verify_case(4, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"000000000000"
,"011101110111"
,"010001010101"
,"010001010101"
,"011101010101"
,"010101010101"
,"010101010101"
,"011101110111"
,"000000000000"
,"000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 9; int Arg3 = 14; verify_case(5, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"11111101001110"
,"11000111111111"
,"00010101111001"
,"10110000111111"
,"10000011010010"
,"10001101101101"
,"00101010000001"
,"10111010100100"
,"11010011110111"
,"11100010110110"
,"00100101010100"
,"01001011001000"
,"01010001111010"
,"10100000010011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 8; int Arg3 = 31; verify_case(6, Arg3, minChange(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     PalindromeMatrix ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
