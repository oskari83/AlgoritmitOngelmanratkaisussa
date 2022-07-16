#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll tree[900010];

void change(int k, int x, int n) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k] + tree[2*k+1];
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
    ll n;
    cin >> n;
    ll newN=1;
    ll arr[n];

    while(newN<n){
        newN*=2;
    }

    for(int i=newN;i<(newN+n);i++){
        cin >> arr[i-newN];
        tree[i]=1;
    }

    for(int i=newN+n;i<2*(newN);i++){
        tree[i]=0;
    }

    for(int i=newN-1; i>0;i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    
    for(int j=0;j<n;j++){
        int x;
        cin >> x;

        int left=0;
        int i=1;
        while(i<newN){
            if(left + tree[2*i]>=x){
                i = 2*i;
            }else{
                left+=tree[2*i];
                i = 2*i+1;
            }
        }

        cout << arr[i-newN] << " ";
        change(i-newN,0,newN);
    } 
}