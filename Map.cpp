#include<bits/stdc++.h>
using namespace std;

// Time Complexity: Log(N)
// First Preference should be unordered map  O(1)

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    //  Pre computation
    map<int, int> mpp;    // stores all values in the sorted manner
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    // Iterate in the map
    for(auto it: mpp){
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    while(q--){
        int number;
        cin >> number;
        // Fetching
        cout << mpp[number] << endl;

    }
    return 0;
}