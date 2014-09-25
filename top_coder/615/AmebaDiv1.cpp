// BEGIN CUT HERE

// END CUT HERE
#line 5 "AmebaDiv1.cpp"
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

class AmebaDiv1 {
    public:
    int count(vector <int> v) {
         //$CARETPOSITION$
    	map<int,int> m,m1;
    	for(int i=0;i<v.size();i++)
    		m[v[i]]=1;

    	for(int i=0;i<v.size();i++) {
    		int num=v[i];
    		while(num%2==0) {
    			num/=2;
    			int num1=num;
    			bool ok=true;
    			for(int j=0;j<v.size();j++) {
    				if(v[j]==num1) {
    					num1*=2;
    					if(num1>v[i]) {
    						ok=false;
    						break;
    					}
    				}
    			}

    			if(!ok)
    				continue;
    			if(num1==v[i]) {
    				m1[num1]=1; 
    				break;
    			}
    		}
    	}

    	int ans=(int)m.size();
    	ans-=(int)m1.size();

    	// for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++) {
    	// 	cout<<it->first<<" ";
    	// }
    	// cout<<endl;
    	// cout<<ans<<endl;
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {2,2,2,2,2,2,4,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,4,8,16,32,64,128,256,1024,2048}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    AmebaDiv1 ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
