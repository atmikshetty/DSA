#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    // Pre computation
    int hash[256] = {0};
    for(int i=0; i<s.size();i++){
        // hash[s[i] - 'a']++; For lowercase only 
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        // Fetching
        // cout << hash[c-'a'] << endl;   For lower case only
        cout << hash[c] << endl;
    }
    return 0;
}