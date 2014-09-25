// BEGIN CUT HERE

// END CUT HERE
#line 5 "GearsDiv2.cpp"
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

class GearsDiv2 {
      public:
      int getmin(string s) {
            //$CARETPOSITION$
      		int ans=0,k=s.length();

      		int A[50]={0},cnt=0;


      		int num=1;
      		//cout<<s<<" "<<k<<endl;
      		for(int i=1;i<k;i++) {
      			if(s[i]!=s[i-1]) {
      				A[cnt++]=num;
      				//cout<<cnt-1<<" "<<A[cnt-1]<<endl;
      				num=0;
      			}
      			num++;
      		}

      		A[cnt++]=num;

      		if(cnt==1) {
      			return (k+1)/2;
      		}

      		//cout<<cnt-1<<" "<<A[cnt-1]<<endl;
      		//cout<<"yo "<<cnt<<endl;
      		if(s[0]==s[k-1]) {
      			cnt--;
      			A[0]+=A[cnt];
      		}


      		//cout<<endl<<ans<<endl;
      		for(int i=0;i<cnt;i++)
      			ans+=A[i]/2;

      		return ans;
      }
      
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LRRR"; int Arg1 = 1; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "RRR"; int Arg1 = 2; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "LRLR"; int Arg1 = 0; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "LRLLRRLLLRRRLLLL"; int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR"; int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     GearsDiv2 ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
