#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll sum = (n*(n+1))/2;
    ll mod = 1e9+7;
    if(sum%2==0){
        ll t=sum/2;

        int ways[sum+1];
        ways[0]=1;
        for(int i=1;i<=sum+1;i++){
            ways[i]=0;
        }

        for(int k=1;k<=n;k++){
            for(int x=t;x>=0;x--){
                if(ways[x]>0){
                    ways[x+k] += ways[x];
                    ways[x+k] %= mod;
                }
            }
        }
        
        if(ways[t]%2==1){
            ways[t]+=mod;
        }
        cout << (ways[t]/2);
    }else{
        cout << 0;
    }
}