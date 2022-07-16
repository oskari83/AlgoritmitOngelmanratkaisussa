#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll tree[400010];

void change(int k, int x, int n) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k]+tree[2*k+1];
    }
}

ll getSum(int a, int b,int n) {
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

    for(int i=n;i<2*n;i++){
        cin >> tree[i];
    }

    for(int i=n-1; i>0;i--){
        tree[i]=tree[2*i]+tree[2*i+1];
    }

    for(int i=0;i<q;i++){
        int type;
        ll a2, a3;
        cin >> type >> a2 >> a3;
        if(type==1){
            change(a2-1,a3,n);
        }else{
            ll sum = getSum(a2-1,a3-1,n);
            cout << sum << "\n";
        }
    }
    
}