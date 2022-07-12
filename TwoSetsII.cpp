#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

set <vector <int> > options;

void creator(vector <int> v, int len, int k, int curSum, int maxSum){
    if(curSum==maxSum){
        options.insert(v);
    }
    if(k>len || curSum>maxSum){
        return;
    }
    int newK = k + 1;
    int newSum = curSum + k;
    for(int i=0;i<2;i++){
        if(i==0){
            v.push_back(k);
            creator(v,len,newK,newSum,maxSum);
            v.pop_back();
        }else{
            creator(v,len,newK,curSum,maxSum);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    ll maxSum = (n*(n+1))/4;
    vector <int> vec;
    creator(vec,n,1,0,maxSum);
    //cout << options.size() << "\n";
    for(auto vec : options){
        int n2 = vec.size();
        int targetSum=0;
        for(int i=0;i<n2;i++){
            //cout << vec[i] << " ";
            if(i==0){
                if(vec[0]!=1){
                    for(int j=1;j<vec[i];j++){
                        targetSum+=j;
                    }
                }
            }else{
                for(int j=vec[i-1]+1;j<vec[i];j++){
                    targetSum+=j;
                }
            }
        }
        if(targetSum==maxSum){
           ans+=1;
        }
        //cout << "\n";
    }
    cout << ans;
}