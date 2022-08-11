#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
ll factorial[1000001];

ll power(ll a, ll b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    ll ans = power(a,b/2);
    if(b%2==0)
        return (ans*ans)%mod;
    return ((ans*ans)%mod * a)%mod;
}

ll inv (ll a){
    return (power(a,mod-2)%mod + mod)%mod;
}

ll binom(ll a, ll b){
    if(b<0 || a<0){
        return 0;
    }
    return (((factorial[a]*inv(factorial[b]))%mod * inv(factorial[a-b]))%mod + mod)%mod;
}

int main(){
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }

    factorial[0]=1;
    for(int i=1;i<1000001;i++){
        factorial[i]=(factorial[i-1]*i)%mod;
    }

    for(int i=0;i<n;i++){
        ll n = a[i].first;
        ll r = a[i].second;
        ll ans = binom(n,r);
        cout << ans << "\n";
    }
}