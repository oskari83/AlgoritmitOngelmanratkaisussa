#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll a;
    ll n;
    cin >> n >> a;
    ll s = 0;
    for(int i=1;i<n;i++){
        ll x;
        cin >> x;
        if(x<a){
            s += (a-x);
        }else{
            a = x;
        }
    }
    cout << s;
}