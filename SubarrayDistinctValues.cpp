#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    ll n,k;
    cin >> n >> k;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ll rightP=0;
    ll sum=0;
    ll curK=1;
    map <int,int> used;
    used[arr[0]] = 1;
    for(int i=0;i<n;i++){
        if(i!=0){
            used[arr[i-1]] -=1;
            if(used[arr[i-1]] ==0){
                curK-=1;
            }
        }
        while((curK<k && rightP<(n-1)) || (rightP<(n-1) && used[arr[rightP+1]]>=1)){
            rightP +=1;
            if(used.count(arr[rightP])){
                if(used[arr[rightP]]==0){
                    curK+=1;
                }
                used[arr[rightP]] +=1;
            }else{
                used[arr[rightP]] = 1;
                curK+=1;
            }
            sum += (rightP-i);
        }
        sum+=1;
    }
    cout << sum;
}