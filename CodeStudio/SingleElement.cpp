// Find The Single Element
#include<bits/stdc++.h>
int getSingleElement(vector<int> &arr){
	// O(3n)
	int maxi = arr[0];
	for(int i=0;i<arr.size();i++){
		maxi = max(maxi, arr[i]);
	}
	int hash[maxi+1] = {0};
	for(int i=0;i<arr.size();i++){
		hash[arr[i]]++;
	}	
	for(int i=0;i<arr.size();i++){
		if(hash[arr[i]] == 1){
			return arr[i];
		}
	}
	return -1;

	// Using HashMap:   O(Nlogn)
	int n = arr.size();
	int maxi = arr[0];
	for(int i=0;i<n;i++){
		maxi = max(maxi, arr[i]);
	}

	map<int,int> mpp;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}

	for(auto it: mpp){
		if(it.second == 1){
			return it.first;
		}
	}
	return -1;

	// Xor operation : Most optimal but code studio still gives a failed testcase dk why
	int xor1 = 0;
	for(int i=0;i<arr.size();i++){
		xor1 = xor1 ^ arr[i];
	}
	return xor1;

    // Easier approach

	for(int i=0;i<arr.size();i+=2){

        if(arr[i]!=arr[i+1])return arr[i];

    }
}