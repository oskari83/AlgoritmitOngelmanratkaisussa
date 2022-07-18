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

ll getMax(int a, int b,int n) {
    a += n; b += n;
    ll x = tree[a];
    while (a <= b) {
        if (a%2 == 1){
            x = max(x, tree[a++]);
        }
        if (b%2 == 0){ 
            x = max(x, tree[b--]);
        }
        a /= 2; b /= 2;
    }
    return x;
}

int main() {
    ll n;
    cin >> n;
    ll newN=1;
    while(newN<n){
        newN*=2;
    }

    vector<int> indexes;
    int values[n];

    for(int i=newN;i<(newN+n);i++){
        int a;
        cin >> a;
        indexes.push_back(-a);
        values[i-newN]=a;
        tree[i]= 0;
    }

    for(int i=newN+n;i<2*(newN);i++){
        tree[i]=0;
    }


    for(int i=newN-1; i>0;i--){
        tree[i]=max(tree[2*i],tree[2*i+1]);
    }

    sort(indexes.begin(),indexes.end());
    
    for(int j=0;j<n;j++){
        int x = values[j];
        auto it = lower_bound(indexes.begin(),indexes.end(),-x);
        int index = it-indexes.begin();
        index = n-1-index;
        int max = getMax(0,index-1,newN) + 1;
        change(index,max,newN);
    } 

    cout << getMax(0,newN-1,newN);
}