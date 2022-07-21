#include <iostream>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    int succ[n+1][31];
    for(int i=1;i<n+1;i++){
        cin >> succ[i][1];
    }

    for(int j=2;j<31;j++){
        for(int i=1;i<n+1;i++){
            succ[i][j]=succ[succ[i][j-1]][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int x,k;
        cin >> x >> k;
        for(int i=29;i>=0;i--){
            if(k>>i&1)
                x=succ[x][i+1];
        }
        cout << x << "\n";
    }
}