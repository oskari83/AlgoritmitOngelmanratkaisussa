#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
 
ll calc(ll nm){
    string num = to_string(nm);
    if(nm==-1){
        return 0;
    }
 
    ll t[19];
    t[0]=1;
    for(int i=1;i<19;i++){
        t[i] = t[i-1]*9;
    }
 
    int nL = num.length();
    ll ans = 0;
    for(int i=0;i<nL;i++){
        ans += t[i];
    }
    bool isValid = true;
    for(int i=0;i<nL;i++){
        if(i==0){
            int l = num[0] - '0' - 1;
            ans += l*t[nL-i-1];
        }else{
            int l2 = num[i] - '0';
 
            if(num[i]>num[i-1]){
                l2-=1;
            }else if(num[i]==num[i-1]){
                isValid=false;
            }
            ans+=l2*t[nL-i-1];
        }
        if(isValid==false){
            return ans;
        }
    }
    if(isValid)
        ans+=1;
    return ans;
}
 
int main() {
    ll a,b;
    cin >> a >> b;
    ll sol1 = calc(b);
    ll sol2 = calc(a-1);
    ll sol = sol1-sol2;
    cout << sol;
}