#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
 
int n, mxn=0;
int t2[1000001];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(x>mxn){
            mxn=x;
        }
        t2[x]+=1;
    }
    int ans;
    for(int i=1;i<mxn+1;i++){
        int cnt = 0;
        for(int j=i;j<mxn+1;j+=i){
            if((t2[j]>=1) && (j%i==0)){
                cnt+=t2[j];
            }
        }
        if(cnt>1){
            ans = i;
        }
    }
    cout << ans;
}