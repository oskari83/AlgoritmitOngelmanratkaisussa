#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll tree[900010];

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
    int n,q;
    cin >> n >> q;
    vector<ll> pairs[q];
    ll arr[n];
    map <int,int> lastSeen;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        tree[i+n] = 0;
    }

    for(int i=n-1; i>0;i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    cout << "\n";

    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        pairs[i].push_back(a);
        pairs[i].push_back(b);
        pairs[i].push_back(i);
    }

    sort(pairs,pairs+q);
    int answers[q];

    int j=q-1;

    for(int i=n-1;i>=0;i--){
        int cur = arr[i];
        if(lastSeen.count(cur)){
            change(lastSeen[cur],tree[lastSeen[cur]+n]-1,n);
        }
        lastSeen[cur]=i;
        change(i,1,n);
        while(j>-1 && pairs[j][0]-1==i){
            int summa = getSum(i,pairs[j][1]-1,n);
            answers[pairs[j][2]]=summa;
            j--;
        }
    }
    
    for(int i=0;i<q;i++){
        cout << answers[i] << "\n";
    }
}