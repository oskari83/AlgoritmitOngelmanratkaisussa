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
    int n;
    cin >> n;
    vector<ll> pairs[n];
    vector<ll> rights;
    vector<ll> rights2;

    for(int i=0;i<n;i++){
        ll left, right;
        cin >> left >> right;
        pairs[i].push_back(left);
        pairs[i].push_back(right);
        pairs[i].push_back(i);
        rights.push_back(right);
        rights2.push_back(-right);
        tree[i+n] = 0;
    }

    for(int i=n-1; i>0;i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    sort(pairs,pairs+n, [ ]( const auto& lhs, const auto& rhs )
    {
        if(lhs[0]==rhs[0])
            return lhs[1] > rhs[1];
        return lhs[0] < rhs[0];
    });

    sort(rights.begin(),rights.end());
    sort(rights2.begin(),rights2.end());

    ll answers[n];
    ll answers2[n];

    for(int i=0;i<n;i++){
        auto it = lower_bound(rights.begin(),rights.end(),pairs[i][1]);
        int index = it-rights.begin();
        ll summa = getSum(index,n-1,n);
        answers[pairs[i][2]]=summa;
        change(index,tree[n+index]+1,n);
    }

    for(int i=0;i<(2*n);i++){
        tree[i] = 0;
    }

    for(int i=n-1;i>=0;i--){
        auto it = lower_bound(rights2.begin(),rights2.end(),-pairs[i][1]);
        int index = it-rights2.begin();
        index = n-1-index;
        ll summa = getSum(0,index,n);
        answers2[pairs[i][2]]=summa;
        change(index,tree[n+index]+1,n);
    }

    for(int i=0;i<n;i++){
        cout << answers2[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n;i++){
        cout << answers[i] << " ";
    }
}