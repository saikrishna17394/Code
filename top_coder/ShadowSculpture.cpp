// BEGIN CUT HERE

// END CUT HERE
#line 5 "ShadowSculpture.cpp"
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

int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};

int A[10][10][10],n,vis[10][10][10];
int xy[10][10],yz[10][10],zx[10][10];

class ShadowSculpture {
    public:

    vector<string> XY,YZ,ZX;


    bool ch(int i,int j,int k) {
    	if(i<0 || j<0 || k<0)
    		return false;
    	if(i>=n || j>=n || k>=n || A[i][j][k]==0)
    		return false;
    	return true;
    }

    void dfs(int x,int y,int z) {
    	vis[x][y][z]=1;
    	xy[x][y]=1;
    	yz[y][z]=1;
    	zx[z][x]=1;

    	for(int a=0;a<6;a++) {
    		int i=x+dx[a],j=y+dy[a],k=z+dz[a];
    		if(ch(i,j,k) && vis[i][j][k]==0)
    			dfs(i,j,k);
    	}

    }

    bool check() {
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<n;j++) {
    			if(xy[i][j]==0 && XY[i][j]=='Y')
    				return false;
    			if(xy[i][j]==1 && XY[i][j]=='N')
    				return false;

    			if(yz[i][j]==0 && YZ[i][j]=='Y')
    				return false;
    			if(yz[i][j]==1 && YZ[i][j]=='N')
    				return false;

    			if(zx[i][j]==0 && ZX[i][j]=='Y')
    				return false;
    			if(zx[i][j]==1 && ZX[i][j]=='N')
    				return false;
    		}
    	}
    	return true;
    }

    string possible(vector <string> XY1, vector <string> YZ1, vector <string> ZX1) {
         //$CARETPOSITION$
    	n=XY1[0].length();
    	XY=XY1;
    	YZ=YZ1;
    	ZX=ZX1;

    	memset(A,0,sizeof A);

    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			for(int k=0;k<n;k++) {
    				if(XY[i][j]=='Y' && YZ[j][k]=='Y' && ZX[k][i]=='Y')
	    				A[i][j][k]=1;
    			}

    	for(int i=0;i<n;i++) {
    		for(int j=0;j<n;j++) {
    			int val=0;
    			if(XY[i][j]=='Y') {
    				for(int k=0;k<n;k++)
    					val+=A[i][j][k];
    				if(val==0)
    					return "Impossible";
    			}
    			if(YZ[i][j]=='Y') {
    				val=0;
    				for(int k=0;k<n;k++)
    					val+=A[k][i][j];
    				if(val==0)
    					return "Impossible";
    			}
    			if(ZX[i][j]=='Y') {
    				val=0;
    				for(int k=0;k<n;k++)
    					val+=A[j][k][i];
    				if(val==0)
    					return "Impossible";
    			}
    		}
    	}

    	memset(vis,0,sizeof vis);

    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			for(int k=0;k<n;k++) {
    				if(A[i][j][k]==1 && vis[i][j][k]==0) {
    					memset(xy,0,sizeof xy);
    					memset(yz,0,sizeof yz);
    					memset(zx,0,sizeof zx);
    					dfs(i,j,k);

    					if(check())
    						return "Possible";
    				}
    			}

    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			if(XY[i][j]=='Y' || YZ[i][j]=='Y' || ZX[i][j]=='Y')
    				return "Impossible";

    	return "Possible";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YN","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(3, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"N"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ShadowSculpture ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
