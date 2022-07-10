#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

set <string> words;

void creator(string s, int len, string chars, string used){
    int nums = s.size();
    if(nums==len){
        words.insert(s);
        return;
    }
    for(int i=0;i<len;i++){
        string d = to_string(i);
        if(used.find(d) == -1){
            s += chars[i];
            used += to_string(i);
            creator(s,len,chars,used);
            s.pop_back();
            used.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.length();
    creator("",n,s,"");
    cout << words.size() << "\n";
    for(string c : words){
        cout << c << "\n";
    }
}