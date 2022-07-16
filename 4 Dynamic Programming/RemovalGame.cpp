#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int a;
    cin >> a;
    ll b[a];
    ll t[a][a];
    ll sums[a][a];
    for(int i=0;i<a;i++){
        cin >> b[i];
        t[i][i]=b[i];
        sums[i][i]=b[i];
    }
    for(int i=1;i<a;i++){
        for(int j=0; j<(a-i);j++){
            sums[j][j+i]=sums[j][j+i-1]+b[j+i];
            ll cs = sums[j][j+i];
            t[j][j+i]=max(cs-(t[j][j+i-1]),cs-(t[j+1][j+i]));
        }
    }
    cout << t[0][a-1];
}