#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int ancestor[200005][31];
int n,q;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> q;
    ancestor[1][1]=0;
    ancestor[0][1]=0;
    for(int i=0;i<n-1;i++){
        cin >> ancestor[i+2][1];
    }

    for(int i=2;i<31;i++){
        ancestor[1][i]=0;
        ancestor[0][i]=0;
        for(int j=2;j<n+1;j++){
            ancestor[j][i]=ancestor[ancestor[j][i-1]][i-1];
        }
    }
    
    for(int i=0;i<q;i++){
        int x,k;
        cin >> x >> k;
        for(int i=29;i>=0;i--){
            if(k>>i&1)
                x=ancestor[x][i+1];
        }
        if(x!=0){
            cout << x << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
}