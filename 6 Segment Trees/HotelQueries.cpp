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
        tree[k] = max(tree[2*k], tree[2*k+1]);
    }
}

int main() {
    ll n,m;
    cin >> n >> m;
    ll newN=1;
    while(newN<n){
        newN*=2;
    }

    for(int i=newN;i<(newN+n);i++){
        cin >> tree[i];
    }

    for(int i=newN+n;i<2*(newN);i++){
        tree[i]=0;
    }
    n=newN;
    for(int i=n-1; i>0;i--){
        tree[i]=max(tree[2*i],tree[2*i+1]);
    }

    for(int j=0;j<m;j++){
        int y;
        cin >> y;
        if(tree[1]<y){
            cout << 0 << " ";
        }else{
            int i=1;
            while(i<n && (tree[2*i]>=y || tree[2*i+1]>=y)){
                if(tree[2*i]>=y){
                    i = 2*i;
                }else{
                    i = 2*i+1;
                }
            }
            cout << i-n+1 << " ";
            change(i-n,tree[i]-y,n);
        }
    } 
}