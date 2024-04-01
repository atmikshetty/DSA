#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<=n-2;i++){
        int mini = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

int main(){
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << endl;
    int arr[n];
    cout << "Enter the values :";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    selectionSort(arr, n);
    for(int i=0;i<=n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}