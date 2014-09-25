// BEGIN CUT HERE

// END CUT HERE
#line 5 "CakeParty.cpp"
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

class CakeParty {
    public:
    string makeMove(vector <int> pieces) {
         //$CARETPOSITION$
    	int x=0,len,big=0,num;
    	len=pieces.size();

    	string s,s1;

    	for(int i=0;i<len;i++) {
    		x^=pieces[i];

    		if(pieces[i]>big) {
    			s="";
    			if(i>9)
    				s+='0'+i/10;
    			s+='0'+i%10;
    			big=pieces[i];
    			num=1;
    		}
    		else if(pieces[i]==big) {
    			s1="";
    			if(i>9)
    				s1+='0'+i/10;
    			s1+='0'+i%10;

    			s=min(s,s1);
    			num++;
    		}
    		else
    			;
    		// cout<<s<<" "<<big<<endl;
    	}

    	sort(pieces.begin(),pieces.end());
    	int big1=0,num1=0;
    	for(int i=len-1;i>=0;i--)  {
    		if(pieces[i]==big)
    			continue;
    		if(big1==0)
	    		big1=pieces[i];
	    	if(pieces[i]==big1)
	    		num1++;
	    	else
	    		break;

    	}
    	// cout<<s<<endl;
    	s1="CAKE "+s+" PIECES ";

    	if(num&1) {

    		if(num>1)
    			s1+="1";

			else {
				cout<<num<<" "<<num1<<" "<<big<<" "<<big1<<endl;
				if(num1==0) {
					ostringstream conv;
					conv<<big;
					s1+=conv.str();
				}
				else if(num1&1) {
					x=big-big1;
		    		ostringstream conv;
		    		conv<<x;
		    		s1+=conv.str();
				}
				else {
					s1+=smallstr_inrange(big-big1+1,big);
				}
			}
    		return s1;
    	}
    	else {
    		s1+="1";
    		return s1;
    	}
    }
    
    string smallstr_inrange(int a,int b) {
    	int num1=0,num2=0,a1=a,b1=b;

    	while(a1)
    		num1++,a1/=10;
    	while(b1)
    		num2++,b1/=10;

		ostringstream conv;
    	if(num1==num2) {
    		conv<<a;
    		return conv.str();
    	}
    	string s1="1",s2;
    	for(int i=0;i<num1;i++)
    		s1+="0";
    	conv<<a;
    	s2=conv.str();

    	return min(s1,s2);
    }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 47"; verify_case(0, Arg1, makeMove(Arg0)); }
	void test_case_1() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 1"; verify_case(1, Arg1, makeMove(Arg0)); }
	void test_case_2() { int Arr0[] = {3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 1 PIECES 2"; verify_case(2, Arg1, makeMove(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 1"; verify_case(3, Arg1, makeMove(Arg0)); }
	void test_case_4() { int Arr0[] = {3,3,112}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 2 PIECES 110"; verify_case(4, Arg1, makeMove(Arg0)); }
	void test_case_5() { int Arr0[] = {3,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 1"; verify_case(5, Arg1, makeMove(Arg0)); }
	void test_case_6() { int Arr0[] = {4,7,4,7,4,7,4,7,47,47,47,47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 10 PIECES 1"; verify_case(6, Arg1, makeMove(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     CakeParty ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 
