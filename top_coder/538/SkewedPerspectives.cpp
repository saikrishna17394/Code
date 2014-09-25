// BEGIN CUT HERE

// END CUT HERE
#line 5 "SkewedPerspectives.cpp"
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

class SkewedPerspectives {
    public:
    string s;
    int len;
    vector<int> v;
    bool solve(int idx,int b,int w,int ex,int ex1) {
    	// cout<<idx<<" "<<b<<" m "<<w<<" "<<ex<<" "<<ex1<<endl;
    	if(idx==len) {
    		int val=0;
    		for(int i=0;i<3;i++) {
    			val+=v[i];
    		}
    		
    		if(ex1>val)
    			return false;
    		val-=ex1;
    		val+=2*b;
    		if(val>=ex)
    			return true;
    		return false;
    	}
    	if(s[idx]!='b') {
    		if(v[s[idx]-'0']) {
    			v[s[idx]-'0']--;
    			return solve(idx+1,b,w,ex,ex1);
    		}
    		return false;
    	}
    	int val=0;
    	for(int i=idx;i<len;i++) {
    		if(s[i]=='b')
    			val++;
    		else
    			break;
    	}
    	if(val%2==0) {
    		if(2*b>=val) {
	    		return solve(idx+val,b-val/2,w,ex,ex1);
    		}
    		return false;
    	}

    	if((idx==0 && val==1) || 2*b<val || w==0)
    		return false;
    	val++;
        if(idx==0) {
            return solve(idx+val-1,b-val/2,w-1,ex,ex1+1);
        }
    	if(idx&1)
	    	return solve(idx+val-1,b-val/2,w-1,ex+idx-1,ex1);
	    else
	    	return solve(idx+val-1,b-val/2,w-1,ex+idx-2,ex1+1);
    }
    vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views) {
         //$CARETPOSITION$
        // Note :: I changed the first test case
        // But the code workds fine :)
    	vector<string> ans;
    	for(int i=0;i<views.size();i++) {
    		s=views[i];
    		len=s.length();
    		// cout<<i<<" "<<s<<" "<<len<<" "<<endl;
    		v=cubes;
    		if(solve(0,B,w-1,0,0))
    			ans.push_back("valid");
    		else
    			ans.push_back("invalid");
            
	    }
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {61,23,39}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; int Arg2 = 4; string Arr3[] = { "0000000b0020002011b0100001b022bbb200021010", "012bb", "bb0", "21bb", "21b", "1bb20" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; string Arr3[] = {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {100,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 3; string Arr3[] = {"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {5,6,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "invalid", "valid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {100,100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 50; string Arr3[] = {"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"0", "bb"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; string Arr3[] = {"00b0b", "bbbbbbbb", "000b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(6, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     SkewedPerspectives ___test;
      ___test.run_test(-1);
     // // ___test.test_case_4();
     // vector<int> v;
     // v.push_back(61);
     // v.push_back(23);
     // v.push_back(39);

     // string s="0000000b0020002011b0100001b022bbb200021010";
     // vector<string> v1;
     // v1.push_back(s);
     //  ___test.areTheyPossible(v, 11, 4,v1);
      system("pause");
}
// END CUT HERE 
