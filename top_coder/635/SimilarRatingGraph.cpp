// BEGIN CUT HERE

// END CUT HERE
#line 5 "SimilarRatingGraph.cpp"
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

bool dp[400][400][400];
double val[400][400],ans[400][400];

class SimilarRatingGraph {
    public:
    int n;

    double dist(int a,int b) {
    	double ret=a;
    	ret*=ret;
    	ret+=(double)(b*b);
    	return sqrt(ret);
    }
	bool check(int x,int y,int x1,int y1) {
		lli l=(lli)x*(lli)y1;
		l-=(lli)x1*(lli)y;
		if(l==0)
			return true;
		return false;
	}

    double maxLength(vector <int> d, vector <int> r) {
         //$CARETPOSITION$
    	memset(dp,0,sizeof dp);
    	memset(ans,0,sizeof ans);

    	n=d.size();
    	for(int i=0;i<n;i++) {
    		val[i][i]=0;
    		for(int j=i+1;j<n;j++) {
    			val[i][j]=val[i][j-1]+dist(d[j]-d[j-1],r[j]-r[j-1]);
    		}
    	}



    	for(int i=0;i<n;i++) {
    		for(int j=0;j<i;j++)
	    		dp[i][j][0]=1;

    		for(int k=1;k<i;k++) {

    			for(int j=k;j<i;j++) {
    				if(dp[i-1][j-1][k-1]==1) {
    					if(k==1) {
    						if(check(d[j]-d[j-1],r[j]-r[j-1],d[i]-d[i-1],r[i]-r[i-1])) {
    							dp[i][j][k]=1;
    							ans[i][k]=max(val[i-k][i],val[j-k][j]);
    							// cout<<i<<" "<<j<<" "<<k<<endl;
    						}
    					}
    					else {
    						if(check(d[j]-d[j-1],r[j]-r[j-1],d[i]-d[i-1],r[i]-r[i-1])) {
    							if(check(d[j]-d[j-1],d[i]-d[i-1],d[j-1]-d[j-2],d[i-1]-d[i-2])) {
 									dp[i][j][k]=1;
 									ans[i][k]=max(val[i-k][i],val[j-k][j]); 									
    								// cout<<i<<" "<<j<<" "<<k<<endl;
    							}
    						}
    					}
    				}
    			}
    		}

    	}

    	double ret=0;

    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			ret=max(ret,ans[i][j]);
    	// return 0;
    	return ret;

    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,4,8,16,32}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,4,8,16,32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 42.42640687119285; verify_case(0, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {81,104,120,124,134,137}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1866,2332,2510,2678,2876,3002}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 168.04761230080004; verify_case(1, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10,11,13,15,19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,14,15,23,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.7183472062349; verify_case(2, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1700,1800,1750,1850}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 100.00499987500625; verify_case(3, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,9,16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(4, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {5,11,25,58,92,162,255,350,458,566,677,792,919,1051,1189,1331,1489,1673,1882,2093,2315,2541,2771,3012,3254,3524,3797,4087,4379,4675,4973,5278,5588,5904,6225,6550,6888,7249,7612,8018,8428,8847,9267,9688,10109,10530,10964,11407,11870,12340,12811,13288,13768,14249,14734,15242,15774,16306,16847,17400,17966,18533,19108,19692,20278,20871,21471,22074,22679,23297,23916,24553,25190,25829,26472,27135,27814,28497,29181,29865,30555,31272,31994,32729,33487,34246,35005,35764,36537,37326,38119,38913,39725,40538,41360,42185,43010,43840,44671,45509,46350,47205,48063,48932,49807,50691,51577,52464,53289,54119,54950,55788,56629,57484,58342,59211,60086,60970,61856,62743,63568,64398,65388}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1505,1462,1436,1416,1463,1421,1411,1450,1497,1465,1423,1394,1391,1367,1358,1323,1310,1279,1268,1279,1311,1342,1359,1387,1414,1376,1424,1382,1373,1335,1359,1318,1275,1266,1227,1203,1168,1163,1184,1144,1169,1207,1250,1235,1209,1162,1124,1148,1168,1202,1190,1155,1179,1194,1195,1195,1203,1240,1218,1245,1220,1190,1208,1180,1182,1148,1139,1126,1152,1159,1147,1158,1112,1091,1101,1116,1123,1086,1126,1110,1128,1085,1132,1145,1135,1140,1117,1081,1120,1131,1081,1032,1071,1102,1071,1065,1068,1027,980,947,987,968,959,980,990,974,1003,996,999,958,911,878,918,899,890,911,921,905,934,927,930,889,844}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 11940.179271014536; verify_case(5, Arg2, maxLength(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SimilarRatingGraph ___test;
    // ___test.test_case_0();
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
