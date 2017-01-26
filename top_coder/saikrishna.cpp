// Sai Krishna
// 110050059
// Room 137
// 9920131267

#include <bits/stdc++.h>
#define lli long long int
#define ii pair<int,int>
#define mod 1000000007

using namespace std;

bool check(string& s1,string& s2,int idx) {
    
    for(int i=0;i<s2.size();i++) {
        if(s1[i+idx]=='.')
            s1[i+idx]=s2[i];
        else if(s1[i+idx]!=s2[i])
            return false;
        else
            ;
    }
    return true;
}

int shortestLength(string a, string b, string c, string d) {
     //$CARETPOSITION$
	vector<string> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);

    sort(v.begin(),v.end());

    int ans=999;
    do {

        int val=999;

        for (int i = 0; i <= v[0].size(); i++) {
            
            int sz1 = max(i +(int)v[1].size(), (int)v[0].size());
            
            for (int j = i; j <= sz1; j++) {
                
                int sz2 = max(sz1, j +(int) v[2].size());
                
                for (int k = j; k <= sz2; k++) {
                    
                    int sz3 = max(sz2, k + (int)v[3].size());

                    string s="";
                    for(int z=0;z<sz3;z++)
                        s+='.';

                    if (check(s,v[0],0) && check(s,v[1],i) && check(s,v[2],j) && check(s,v[3],k)) {
                        val = min(val, sz3);
                    }
                }
            }
        }

        ans=min(ans,val);
    } while(next_permutation(v.begin(),v.end()));

    return ans;
}

int main() {

	int ans=shortestLength("abc","ab","bc","b");	
	cout<<ans<<endl;	

	ans=shortestLength("a","bc","def","ghij");
	cout<<ans<<endl;

	ans=shortestLength("top","coder","opco","pcode");
	cout<<ans<<endl;

	ans=shortestLength("thereare","arelots","lotsof","ofcases");
	cout<<ans<<endl;

	ans=shortestLength("aba","b","b","b");	
	cout<<ans<<endl;	

	ans=shortestLength("x","x","x","x");
	cout<<ans<<endl;

	return 0;
}