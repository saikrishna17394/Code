// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheConsecutiveIntegersDivOne.cpp"
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

class TheConsecutiveIntegersDivOne {
    public:
    int find(vector <int> v, int k) {
         //$CARETPOSITION$
    	if(k==1)
    		return 0;

    	sort(v.begin(),v.end());

    	int a=-10000000,b=10000000;

    	// a=-53;b=-53;

    	int n=v.size();
    	int ans=1000000000;

    	for(int i=a;i<=b;i++) {
    		int idx=-1;
    		int val=1000000000;

    		for(int j=0;j<n;j++) {
    			if(abs(v[j]-i)<val) {
    				idx=j;
    				val=abs(v[j]-i);
    			}
    		}

			int num=1;
			int l=idx-1,r=idx+1;
			int ans1=val;

			while(num<k) {
				// cout<<num<<endl;
				// cout<<l<<" "<<r<<" "<<ans1<<endl;
				// cout<<v[l]<<" "<<v[r]<<endl;
				if(l>=0) {
					val=abs(v[l]-(i-(idx-l)) );

					if(r<n) {
						int val1=abs(v[r]-(i+(r-idx)) );

						if(val1<val) {
							r++;
							ans1+=val1;
						}
						else {
							l--;
							ans1+=val;
						}
					}
					else {
						ans1+=val;
						l--;
					}
				}
				else {
					val=abs(v[r]-(i+(r-idx)) );
					ans1+=val;
					r++;
				}

				num++;
			}

			if(ans1<ans) {
				// cout<<i<<" "<<ans1<<endl;
				ans=ans1;
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
	void test_case_0() { int Arr0[] = {4, 7, 47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-96, -53, 82, -24, 6, -75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 20; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {64, -31, -56}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 24; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-96, -53, 82, -24, 6, -75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 90; verify_case(4, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TheConsecutiveIntegersDivOne ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
