// BEGIN CUT HERE

// END CUT HERE
#line 5 "RelativePath.cpp"
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

#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

using namespace std;

class RelativePath {
      public:
      string makeRelative(string path, string currentDir) {
            //$CARETPOSITION$

      		vector<string> v1,v2;
                  string s="",res="";
                  for(int i=0;i<path.length();i++) {
                        if(path[i]=='/') {
                              if(s.length()==0)
                                    ;
                              else {
                                    v1.push_back(s);
                                    s="";
                              }

                        }
                        else s+=path[i];
                  }
                  if(s.length()>0)
                        v1.push_back(s);
      		
                  s="";
                  for(int i=0;i<currentDir.length();i++) {
                        if(currentDir[i]=='/') {
                              if(s.length()==0)
                                    ;
                              else {
                                    v2.push_back(s);
                                    s="";
                              }

                        }
                        else s+=currentDir[i];
                  }

                  if(s.length()>0)
                        v2.push_back(s);

                  // tr(v1,it)
                  //       cout<<*it<<endl;

                  // cout<<"yo\n";
                  // tr(v2,it)
                  //       cout<<*it<<endl;

                  int k=min(v1.size(),v2.size());

                  int j=0;
                  for(int i=0;i<k;i++) {
                        if(v1[i]!=v2[i])
                              break;
                        j++;
                  }

                  //cout<<j<<endl;
                  for(int i=0;i<v2.size()-j;i++) {
                        res+="../";

                  }
                  int i;
                  for(i=j;i<v1.size()-1;i++) {
                        res+=v1[i];
                        res+="/";
                  }
                  res+=v1[i];

      		return res;
      }
      
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "/home/top/data/file"; string Arg1 = "/home/user/pictures"; string Arg2 = "../../top/data/file"; verify_case(0, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "/home/user/movies/title"; string Arg1 = "/home/user/pictures"; string Arg2 = "../movies/title"; verify_case(1, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "/file"; string Arg1 = "/"; string Arg2 = "file"; verify_case(2, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "/a/b/a/b/a/b"; string Arg1 = "/a/b/a/a/b/a/b"; string Arg2 = "../../../../b/a/b"; verify_case(3, Arg2, makeRelative(Arg0, Arg1)); }
      void test_case_4() { string Arg0 = "/home/user/file"; string Arg1 = "/home/user/fi"; string Arg2 = "../file"; verify_case(4, Arg2, makeRelative(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     RelativePath ___test;
      ___test.run_test(-1);

      RelativePath a;
      string s1,s2;

      cin>>s1>>s2;
      cout<<a.makeRelative(s1,s2)<<endl;

      system("pause");
}
// END CUT HERE 

// /a/a/aa/aaa/a/a/aaa/aa/a/aa/a/a/a/a
// /a/a/aa/aaa/a/a/aaa/aa/a/aa/a/a/aa/aa/a/a/a/a