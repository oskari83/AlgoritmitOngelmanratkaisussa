#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll max=0;
    ll mod = 1e9+7;
    pair<int,int> a[n];
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
        if(a[i].first>max){
            max=a[i].first;
        }
    }

    ll in[max+1];
    in[1]=1;
    for(int i=2;i<max+1;i++){
        in[i]=mod - (mod/i) * in[mod%i]%mod;
    }

    ll m[max+1];
    ll mi[max+1];
    m[0]=1;
    mi[0]=1;

    for(int i=1;i<max+1;i++){
        m[i]=(m[i-1]*i)%mod;
        mi[i]=mi[i-1]*in[i]%mod;
    }

    for(int i=0;i<n;i++){
        cout << m[a[i].first] * mi[a[i].first-a[i].second]%mod * mi[a[i].second]%mod << "\n";
    }
}