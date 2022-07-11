#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    priority_queue < pair <int,int> > rooms;
    vector <vector <int> > a;
    for(int i=0;i<n;i++){
        vector <int> temp;
        int a1; int a2;
        cin >> a1 >> a2;
        temp.push_back(a1);
        temp.push_back(a2);
        temp.push_back(i);
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    int num=0;
    int nums[n];
    for(int i=0;i<n;i++){
        if(rooms.empty()==true){
            num=1;
            rooms.push(make_pair(-a[i][1],num));
            nums[a[i][2]]=num;
        }else if(rooms.top().first<=-a[i][0]){
            num += 1;
            rooms.push(make_pair(-a[i][1],num));
            nums[a[i][2]]=num;
        }else{
            int rn = rooms.top().second;
            rooms.pop();
            rooms.push(make_pair(-a[i][1],rn));
            nums[a[i][2]]=rn;
        }
    }
    cout << num << "\n";
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
}