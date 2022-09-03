#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

vector<int> z(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z; 
}

int main(){
    string st, pat;
    cin >> st >> pat;
    
    int m = pat.length();
    string nst = pat + "#" + st;

    vector<int> ztable = z(nst);

    int ans = 0;
    for(auto u : ztable){
        if(u==m){
            ans++;
        }
    }

    cout << ans;
}