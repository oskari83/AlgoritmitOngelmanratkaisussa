#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
 
ll tree[900010];
 
void change(ll k, ll x, ll n) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k]+tree[2*k+1];
    }
}
 
ll getSum(ll a, ll b,ll n) {
    a += n; b += n;
    ll s = 0;
    while (a <= b) {
        if (a%2 == 1) s += tree[a++];
        if (b%2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}
 
int main() {
    ll n,q;
    cin >> n >> q;
    ll arr[n+1];
    arr[0]=0;
 
    for(int i=1;i<n+1;i++){
        cin >> arr[i];
        tree[i-1+n] = arr[i]-arr[i-1];
    }
 
    for(int i=n-1; i>0;i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
 
    for(int i=0;i<q;i++){
        int type;
        cin >> type;
        if(type==2){
            ll val;
            cin >> val;
            ll ans = getSum(0,val-1,n);
            cout << ans << "\n";
        }else{
            ll a,b,delta;
            cin >> a >> b >> delta;
 
            change(a-1,tree[n+a-1]+delta,n);
            if(b!=n){
                change(b,tree[n+b]-delta,n);
            }
        }
    }
}