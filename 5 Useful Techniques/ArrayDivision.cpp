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
    ll left = 0;
    ll right = 0;
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(b[i]>left){
            left=b[i];
        }
        right+=b[i];
    }
    ll ans = right;
    while(left<=right){
        ll cur = (left+right)/2;
        ll sm = 0;
        ll resets = 1;
        for(int i=0;i<n;i++){
            sm+=b[i];
            if(sm>cur){
                sm=b[i];
                resets+=1;
            }
        }
        if(resets>k){
            left = cur + 1;
        }else{
            right = cur - 1;
            if(cur<ans)
                ans = cur;
        }
    }

    cout << ans;
}