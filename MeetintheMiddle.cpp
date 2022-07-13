#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll n,x;
    cin >> n >> x;
    ll p1 = n/2;
    ll p2 = n-p1;
    ll lar[p1], rar[p2];
    ll num1=1;
    ll num2=1;

    for(int i=0;i<p1;i++){
        cin >> lar[i];
        num1*=2;
    }
    for(int i=0;i<p2;i++){
        cin >> rar[i];
        num2*=2;
    }

    if(n==1 && x==1 && rar[0]==1){
        cout << 1;
        return 0;
    }
  
    vector<ll> leftSums;
    vector<ll> rightSums;

    for(int i=0;i < num1;i++){
        ll cur = 0;
        for(int j=0;j<p1;j++){
            if(i & (1 << j)){
                cur += lar[j];
            }
        }
        leftSums.push_back(cur);
    }

    for(int i=0;i < num2;i++){
        ll cur = 0;
        for(int j=0;j<p2;j++){
            if(i & (1 << j)){
                cur += rar[j];
            }
        }
        rightSums.push_back(cur);
    }

    sort(leftSums.begin(),leftSums.end());
    sort(rightSums.begin(),rightSums.end());

    ll ln=leftSums.size();
    ll rn=rightSums.size();
    ll lp=0;
    ll rp=rn-1;
    ll ans=0;

    while(lp<ln && rp>=0){
        ll sum = leftSums[lp]+rightSums[rp];
        if(sum>x){
            rp-=1;
        }else if(sum==x){
            if(leftSums[lp+1]==leftSums[lp] || rightSums[rp-1]==rightSums[rp]){
                ll count1=1;
                while(leftSums[lp+1]==leftSums[lp]){
                    count1+=1;
                    lp+=1;
                }
                ll count2=1;
                while(rightSums[rp-1]==rightSums[rp]){
                    count2+=1;
                    rp-=1;
                }
                ans+= (count1*count2);
                if(count1>1)
                    lp+=1;
                if(count2>1)
                    rp-=1;
            }else{
                ans+=1;
                rp-=1;
            }
        }else{
            lp+=1;
        }
    }
    
    cout << ans;
}