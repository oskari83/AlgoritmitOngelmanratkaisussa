#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll l[n];
    ll c = 1;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        l[x-1]=i;
    }

    for(int i=1;i<n;i++){
        if(l[i]<l[i-1]){
            c+=1;
        }
    }
    cout << c;
}