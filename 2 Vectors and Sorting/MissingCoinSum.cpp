#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll sum = 0;
    for(int i = 0; i<n; i++){
        if (sum+1<arr[i]){
            break;
        }
        sum+=arr[i];
    }
    cout << sum+1;
}