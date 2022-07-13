#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n,k;
    cin >> n >> k;
    ll b[n];
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    ll left = 0;
    ll max = 1e18;
    ll ans = 1e18;
    ll m2 = 1e9;
    while(left<=max){
        ll cur = (max+left)/2;
        ll t=0;
        for(int i=0;i<n;i++){
            t+=(min(cur/b[i],m2));
        }
        if(t>=k){
            if(cur<ans)
                ans=cur;
            max=cur-1;
        }else{
            left=cur+1;
        }
    }
    cout << ans;
}