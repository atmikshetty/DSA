#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i -1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j = j -1;
        }
        arr[j+1] = temp;
    }
}

int main(){
    
    vector<int> arr = { 12, 11, 13, 5, 6 };
    cout << "before sorting" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    insertionSort(arr);
    cout << "after sorting" << endl;
    for(auto i: arr){
        cout << i << " ";
    }
}