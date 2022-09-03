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
    string st;
    cin >> st;
    int n = st.length();
    vector<int> ztable = z(st);

    vector<int> ans;
    int ind = 0;
    for(auto u : ztable){
        if(u==(n-ind)){
            ans.push_back(u);
        }
        ind++;
    }

    int n2 = ans.size();
    for(int i=n2-1;i>=0;i--){
        cout << ans[i] << " ";
    }
}