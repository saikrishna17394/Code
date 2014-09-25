// BEGIN CUT HERE

// END CUT HERE
#line 5 "CuttingBitString.cpp"
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
#define lli long long int
#define inf 999999999
using namespace std;

class CuttingBitString {
    public:

    int A[50][50];
    int B[50][50];
    bool check(lli num) {
    	if(num==0)
    		return false;
    	while(num%5==0)
    		num/=5;
    	if(num==1)
    		return true;
    	return false;
    }


    int getmin(string s) {
         //$CARETPOSITION$
    	int len=s.length();

    	memset(B,0,sizeof B);

    	for(int i=0;i<len;i++) {
    		// cout<<i<<endl;
    		lli num=0;
    		if(s[i]=='1') {
    			A[i][i]=0;
    			B[i][i]=1;
    			num=1;
    		}
    		else {
    			A[i][i]=inf;
    		}
    		for(int j=i+1;j<len;j++) {
    			// cout<<j<<endl;
    			num<<=1;
    			if(s[j]=='1')
    				num++;
    			if(check(num))
    				B[i][j]=1;
    		}
    	}
    	// cout<<"man\n";
    	// cout<<B[0][2]<<" "<<" "<<B[]
    	for(int j=1;j<len;j++) {
    		for(int i=0;i+j<len;i++) {
    			if(s[i]=='0') {
    				A[i][i+j]=inf;
    				continue;
    			}
    			if(B[i][i+j])
    				A[i][i+j]=0;
    			else {
    				A[i][i+j]=inf;
    				for(int k=i;k<(i+j);k++) {
    					A[i][i+j]=min(A[i][i+j],A[i][k]+A[k+1][i+j]+1);
    				}
    			}
    		}
    	}
    	if(A[0][len-1]==inf)
    		return -1;
    	return A[0][len-1]+1;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "101101101"; int Arg1 = 3; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "1111101"; int Arg1 = 1; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "00000"; int Arg1 = -1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "110011011"; int Arg1 = 3; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "1000101011"; int Arg1 = -1; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arg0 = "111011100110101100101110111"; int Arg1 = 5; verify_case(5, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     CuttingBitString ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
