#include<bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	// Heap approach
	int n = arr.size();
	vector<int> elements(n-1, 0);
	priority_queue<pair<long double, int>> pq;
	for(int i=0;i<n-1;i++){
		pq.push({arr[i+1] - arr[i], i});
	}
	for(int  i =1; i<=k;i++){
		auto tp = pq.top();
		pq.pop();
		int secIndex = tp.second;
		elements[secIndex]++;
		long double indDiff = arr[secIndex + 1] - arr[secIndex];
		long double newSecLen = indDiff / (long double) (elements[secIndex] + 1);
		pq.push({newSecLen, secIndex});
	}	
	return pq.top().first;
}
