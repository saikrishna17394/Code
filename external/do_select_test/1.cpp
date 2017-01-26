// C++ program to read an integer from STDIN and output it to STDOUT
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

typedef pair<int,int> pii;

int main() {
  // Declare the variable
  int n, k, A[1010];
  set<pii> s;
  long long int ans, mod = 1000000007;
  // Read the variable from STDIN
  cin >> n >> k;

  for(int i = 0; i < n; i++) {
  	cin >> A[i];
  	s.insert(pii(A[i], i));
  }
  
  int min_swaps = 0;

  for(int i = 0; i < n; i++) {
  	if(min_swaps == k)
  	  break;

  	pii p = *s.rbegin();

  	if(p.first != A[i]) {
	  min_swaps++;

	  s.erase(p);
	  s.erase(pii(A[i], i));
	  s.insert(pii(A[i], p.second));
	  swap(A[i], A[p.second]);
  	}
  	else
  	  s.erase(pii(A[i], i));

  }

  int diff = k - min_swaps;
  if(n > 1 && min_swaps > 0 && diff > 0 && diff%2 != 0)
  	swap(A[n-2], A[n-1]);

  ans = 0;

  for(int i = 0; i < n; i++) {
  	ans = ans*10 + (long long int)A[i];
  	ans %= mod;
  }

  // Output the variable to STDOUT
  cout << ans << endl;
  
  return 0;
}
