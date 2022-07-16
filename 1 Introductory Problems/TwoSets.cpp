#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll s = (n*(n+1))/2;
    if(s%2==0){
        cout << "YES" << "\n";
        ll target = s/2;
        ll current = 0;
        ll c = 0;
        ll ans[n+1];

        for(int i=n; i>0; i--){
            if(current + i <= target){
                ans[i] = 1;
                current += i;
                c += 1;
            }else{
                ans[i] = 0;
            }
        }

        cout << c << "\n";
        for(int i=1;i<n+1;i++){
            if(ans[i]==1){
                cout << i << " ";
            }
        }
        cout << "\n"<< (n-c) << "\n";
        for(int i=1;i<n+1;i++){
            if(ans[i]==0){
                cout << i << " ";
            }
        }
    }else{
        cout << "NO";
    }
}