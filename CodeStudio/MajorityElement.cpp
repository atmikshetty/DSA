#include <bits/stdc++.h>
int majorityElement(vector<int> v) {
	// // Brute Force  O(N2)
	// int n = v.size();
	// for(int i=0;i<n;i++){
	// 	int count = 0;
	// 	for(int j=0;j<n;j++){
	// 		if(v[i] == v[j]) count++;
	// 	}
	// 	if(count > n/2) return v[i];
	// }
	// return -1;

	// // HashMap  O(NLOGN) + O(N)
	// int n = v.size();
	// map<int,int> mpp;
	// for(int i=0;i<n;i++){
	// 	mpp[v[i]]++;
	// }
	// for(auto it: mpp){
	// 	if(it.second > n/2) return it.first;
	// }
	// return -1;

	// Moore's Voting Algorithm
	int n = v.size();
	int count = 0;
	int temp;
	for(int i=0;i<n;i++){
		if(count == 0){
			count = 1;
			temp = v[i];    // max count element is stored here
		}
		else if(v[i] == temp){
			count++;
		}
		else count --;
	}
	int count1;
	for(int i=0;i<n;i++){
		if(v[i] == temp) count1++;
	}
	if(count1 > n/2) return temp;
	return -1;
}