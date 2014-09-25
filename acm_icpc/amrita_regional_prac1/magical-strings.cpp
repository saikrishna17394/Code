#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool palin(string s) {
    for(int i=s.length()-1;i>=0;i--) {
        if(s[i]!=s[s.length()-i-1])
            return false;
    }
    return true;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int t;
    cin>>t;
    string s;
    while(t--) {
        cin>>s;
        if(palin(s))
            printf("YES\n");
        else
            printf("NO\n");
            
    }
    return 0;
}


