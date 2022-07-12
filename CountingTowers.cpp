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
    ll mx=0;
    ll mod = 1e9+7;
    for(int i=0;i<a;i++){
        cin >> b[i];
        if(b[i]>mx){
            mx=b[i];
        }
    }
    ll t[mx+1][5];  
    t[1][0]=2;
    t[1][1]=1;
    t[1][2]=1;
    t[1][3]=1;
    t[1][4]=1;
    for(int i=2;i<=mx;i++){
        for(int j=0;j<5;j++){
            if(j==0){
                t[i][j]=t[i-1][0]+t[i-1][1] + t[i-1][0]+t[i-1][2]+t[i-1][3]+t[i-1][4];
                t[i][j]%=mod;
            }else if(j==1){
                t[i][j]=t[i-1][0]+t[i-1][1];
                t[i][j]%=mod;
            }
            else{
                t[i][j]=t[i-1][0]+t[i-1][2]+t[i-1][3]+t[i-1][4];
                t[i][j]%=mod;
            }
        }
    }
    
    for(int i=0;i<a;i++){
        cout << t[b[i]][0]%mod << "\n";
    }
}