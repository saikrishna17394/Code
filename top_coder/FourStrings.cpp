// Sai Krishna
// 110050059
// Room 137
// 9920131267

// BEGIN CUT HERE

// END CUT HERE
#line 5 "FourStrings.cpp"
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

class FourStrings {
    public:

    bool check(string& s1,string& s2,int idx) {
        
        for(int i=0;i<s2.size();i++) {
            if(s1[i+idx]=='.')
                s1[i+idx]=s2[i];
            else if(s1[i+idx]!=s2[i])
                return false;
            else
                ;
        }
        return true;
    }

    int shortestLength(string a, string b, string c, string d) {
         //$CARETPOSITION$
    	vector<string> v;
    	v.push_back(a);
    	v.push_back(b);
    	v.push_back(c);
    	v.push_back(d);

        sort(v.begin(),v.end());

        int ans=999;
        do {

            int val=999;

            for (int i = 0; i <= v[0].size(); i++) {
                
                int sz1 = max(i +(int)v[1].size(), (int)v[0].size());
                
                for (int j = i; j <= sz1; j++) {
                    
                    int sz2 = max(sz1, j +(int) v[2].size());
                    
                    for (int k = j; k <= sz2; k++) {
                        
                        int sz3 = max(sz2, k + (int)v[3].size());

                        string s="";
                        for(int z=0;z<sz3;z++)
                            s+='.';

                        if (check(s,v[0],0) && check(s,v[1],i) && check(s,v[2],j) && check(s,v[3],k)) {
                            val = min(val, sz3);
                        }
                    }
                }
            }

            ans=min(ans,val);
        } while(next_permutation(v.begin(),v.end()));

        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abc"; string Arg1 = "ab"; string Arg2 = "bc"; string Arg3 = "b"; int Arg4 = 3; verify_case(0, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "bc"; string Arg2 = "def"; string Arg3 = "ghij"; int Arg4 = 10; verify_case(1, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "top"; string Arg1 = "coder"; string Arg2 = "opco"; string Arg3 = "pcode"; int Arg4 = 8; verify_case(2, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "thereare"; string Arg1 = "arelots"; string Arg2 = "lotsof"; string Arg3 = "ofcases"; int Arg4 = 19; verify_case(3, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "aba"; string Arg1 = "b"; string Arg2 = "b"; string Arg3 = "b"; int Arg4 = 3; verify_case(4, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arg0 = "x"; string Arg1 = "x"; string Arg2 = "x"; string Arg3 = "x"; int Arg4 = 1; verify_case(5, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FourStrings ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
