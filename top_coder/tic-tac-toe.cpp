#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/* Complete the function below to print 2 integers separated by a single space which will be your next move 
   */
void nextMove(char player, vector <string> s){
  
  int val=0;
  for(int i=0;i<3;i++)  
    for(int j=0;j<3;j++)
      if(s[i][j]!='_')
        val++;

  if(val==0) {
    printf("0 0\n");
    return;
  }

  if(val==1) {
    if(s[1][1]!='_') {
      printf("0 0\n");
    }
    else {
      printf("1 1\n");
    }
    return ;
  }
  
}
int main(void) {

  char player;
  vector <string> board;

  //If player is X, I'm the first player.
  //If player is O, I'm the second player.
  cin >> player;

  //Read the board now. The board is a 3x3 array filled with X, O or _.
  for(int i=0; i<3; i++) {
    string s; cin >> s;
    board.push_back(s);
  }

 nextMove(player,board);

  return 0;
}
