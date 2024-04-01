#include<bits/stdc++.h>
using namespace std;
int hashhhhh[100000000];  // 10^7

int main(){

    int n;
    cout << "Enter the total no of elements in the array: ";
    cin >> n;
    cout << endl;
    int arr[n];
    cout << " Enter the elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    // Pre Computation
    int hash[13] = {0};    // All values are currently zero
    for(int i=0; i<n;i++){
        hash[arr[i]] += 1;
    }

    cout << endl;

    cout << "Enter the total no of queries: ";
    int q;
    cin >> q;
    // Fetching method
    cout << "Enter the numbers to count occurences: ";
    while(q--){
        int number;
        cin >> number;
        //  Print the total occurences of the numbers
        cout << hash[number] << endl;
    }
    return 0;
}