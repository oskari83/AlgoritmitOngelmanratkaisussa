#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x; 
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int k=0;k<n;k++){
        int x;
        cin >> x;
        vector<int> v = factors(x);
        ll ans = 1;
        int succ = 1;
        if(v.size()==1){
            ans=2;
        }else{
            for(int i=1;i<v.size();i++){
                if(v[i]==v[i-1]){
                    succ+=1;
                    if(i==v.size()-1){
                        ans*=(succ+1);
                    }
                }else{
                    ans*=(succ+1);
                    succ=1;
                    if(i==v.size()-1){
                        ans*=2;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}