// BEGIN CUT HERE

// END CUT HERE
#line 5 "PotentialArithmeticSequence.cpp"
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

class PotentialArithmeticSequence {
    public:
    int numberOfSubsequences(vector <int> d) {
         //$CARETPOSITION$
    	int n=d.size();

    	int ans=0;

    	for(int i=0;i<n;i++) {
    		for(int j=i;j<n;j++) {
    			if(i==j) {
    				ans++;
    				continue;
    			}
    			if(d[i]==0 && d[i+1]==0)
    				continue;
    			if(d[i]!=0 && d[i+1]!=0)
    				continue;

    			if(j==i+1) {
    				ans++;
    				continue;
    			}

    			int k=i;
    			if(d[k]==0)
    				k++;
    			int rem=d[k];
    			int num=0;
    			bool ok=true;
    			// cout<<"man"<<k<<" "<<num<<" "<<rem<<endl;
    			for(int a=k+1;a<=j;a++) {
    				num++;
    				if(num%2==1 && d[a]!=0) {
    					ok=false;
    					break;
    				}
    				if(num%2==1 && d[a]==0)
    					continue;
    				int val=0,num1=num;
    				while(num1%2==0) {
    					val++;
    					num1/=2;
    				}

    				if(val<rem) {
    					if(d[a]!=val) {
    						ok=false;
    						break;
    					}
    					continue;
    				}
    				if(val>rem) {
    					if(d[a]!=rem) {
    						ok=false;
    						break;
    					}
    					continue;
    				}
    				if(val==rem) {
    					if(d[a]<=rem) {
    						ok=false;
    						break;
    					}
    					rem=d[a];
    					num=0;
    				}
    			}
    			if(ok) {
    				// cout<<i<<" "<<j<<endl;
    				ans++;
    			}
    		}
    	}

    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,0,2,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(0, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_3() { int Arr0[] = {0,100,0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_4() { int Arr0[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(4, Arg1, numberOfSubsequences(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PotentialArithmeticSequence ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
