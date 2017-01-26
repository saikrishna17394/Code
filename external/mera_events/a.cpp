#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int len = 1;
  int l = 0, r = 0;

  for( int i = 0; i < s.length(); i++) {
       // finding the longest palindrome centered at index i
      int cur_l, cur_r, cur_len;
      
      // even length palindrome
      cur_len = 2;
      cur_l = i;
      cur_r = i + 1;

      while( cur_l >= 0 && cur_r < s.length() ) {
        if(s[cur_l] == s[cur_r]) {
          if(cur_len > len) {
            len = cur_len;
            l = cur_l;
            r = cur_r;
          }
        }
        else
          break;
        cur_l--;
        cur_r++;
        cur_len += 2;
      }

     // odd length palindrome
      cur_len = 3;
      cur_l = i - 1;
      cur_r = i + 1;

      while( cur_l >= 0 && cur_r < s.length() ) {
        if(s[cur_l] == s[cur_r]) {
          if(cur_len > len) {
            len = cur_len;
            l = cur_l;
            r = cur_r;
          }
        }
        else
          break;
        cur_l--;
        cur_r++;
        cur_len += 2;
      }
  }

  // printing out the longest palindrom

  for(int i = l; i <= r; i++)
    cout << s[i];
  cout<<endl;

  return 0;
}