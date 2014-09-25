// BEGIN CUT HERE

// END CUT HERE
#line 5 "GameOnABoard.cpp"
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
#define inf 999999999
#define ii pair<int,int>
#define mp make_pair
using namespace std;
int dx[]={+1,-1,0,0};
int dy[]={0,0,+1,-1};

class GameOnABoard {
    public:
    int v[40][40],D[40][40],n,m;

    void fill_inf() {
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++)
	    		D[i][j]=inf;
    }

    bool check(int a,int b) {
    	if(a<0 || b<0 || a>=n || b>=m)
    		return false;
    	return true;
    }

    int optimalChoice(vector <string> cost) {
         //$CARETPOSITION$
    	n=cost.size();
    	m=cost[0].size();
    	// s=cost;
    	int ans=inf;
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++) 
    			v[i][j]=cost[i][j]-'0';

    	int cost1;
    	// I could have used floyd warshall and made the code more easier
    	// ...!!!!...
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			
    			fill_inf();
    			set<pair<int,ii> > s;
    			set<pair<int,ii> >::iterator it,it1;
    			D[i][j]=v[i][j];
    			s.insert(mp(v[i][j],ii(i,j)));
    			int val=v[i][j],x,y;
    			ii p;
    			while(s.size()) {
    				it=s.begin();
    				cost1=it->first;
    				val=max(val,cost1);
    				p=it->second;
    				s.erase(it);
    				// cout<<" df "<<D[p.first][p.second]<<" "<<n<<" "<<m<<endl;
    				// cout<<p.first<<" posman "<<p.second<<" "<<endl;
    				for(int k=0;k<4;k++) {
    					x=p.first+dx[k];
    					y=p.second+dy[k];
    					if(check(x,y) && ((cost1+v[x][y])<D[x][y])) {
    						// cout<<D[x][y]<<" "<<cost1<<" "<<v[x][y]<<" "<<endl;
    						// cout<<x<<" dsfd "<<y<<endl;
    						it1=s.find(mp(D[x][y],ii(x,y)));
    						if(it1!=s.end())
    							s.erase(it1);
    						D[x][y]=cost1+v[x][y];
							s.insert(mp(D[x][y],ii(x,y)));
							// cout<<"dud"<<D[x][y]<<endl;						
    					}
    				}
    			}
    			// cout<<i<<" "<<j<<" "<<val<<endl;
    			ans=min(ans,val);
    		}
    	}

    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	// private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"011",
 "011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, optimalChoice(Arg0)); }
	void test_case_1() { string Arr0[] = {"01",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, optimalChoice(Arg0)); }
	void test_case_2() { string Arr0[] = {"111001",
 "001000",
 "111111",
 "001111",
 "001100",
 "001011",
 "111001",
 "010011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, optimalChoice(Arg0)); }
	void test_case_3() { string Arr0[] = {"001001101011",
 "110011001101",
 "111111000001",
 "111101010001",
 "011100101111",
 "110010111000",
 "111111110101",
 "111011110111",
 "111100100011",
 "000000000110",
 "101011011110",
 "011111000111",
 "101111001011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, optimalChoice(Arg0)); }
	void test_case_4() { string Arr0[] = {"110010100101010110100010001100111011",
 "001000000110100011010100000001001000",
 "011000110111101001011101110111000100",
 "111001011000100101111010100110110011",
 "111000011101001010000100001010000010",
 "111001110010100101000001001100011011",
 "111110100111010101100000100111000111",
 "011111111100100111111110000001110111",
 "110000010101001111100011110000001000",
 "010010110111111100011101100000011010",
 "110001100001111001101000101110110001",
 "110010000111011110000010110111010101",
 "100100110101001001101000001101101101",
 "001011101101001100111110101111001110",
 "111010111111111100110100000011111100",
 "110101101000001001000100101011100000",
 "011011001011010001001000100000110101",
 "011111111100000011010111010011010100",
 "111001111110001110001110010100111010",
 "000001111000001100101010000001101110",
 "010000110000010010111110111000010101",
 "100010010100110011000111101001101011",
 "111010110001101011010001111101111100",
 "000111110000110000000101100101000110",
 "110000010111001001110001101010111100",
 "011111101101001011011010011111100010",
 "110101111101010100110010000011001101",
 "101101111001010100101111100001110001",
 "000110010100101111011011110010010010",
 "110101010011101000111011100000010011",
 "110001010001110011010100110000010001",
 "111010101100111100100011001101010100",
 "011000000000100001011010000100010001",
 "100000110110000001010001001111010000",
 "100011111110010011011011001110011111",
 "101100001111100101001101100000100001",
 "010000111011010110011001110011111000",
 "100010100111110111001010100101111010",
 "000110011110111011111000101000001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, optimalChoice(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     GameOnABoard ___test;
      ___test.run_test(-1);
     // ___test.test_case_0();
      system("pause");
}
// END CUT HERE 
