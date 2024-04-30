#include <bits/stdc++.h>
#include <vector>
int subarrayWithMaxProduct(vector<int> &arr) {
  // // Brute Force O(N3)
  // int n = arr.size();
  // int maxProd = INT_MIN;
  // for(int i=0;i<n;i++){
  // 	for(int j=i;j<n;j++){
  // 		int product = 1;
  // 		for(int k=i;k<=j;k++){
  // 			product = product * arr[k];
  // 		}
  // 		maxProd = max(maxProd, product);
  // 	}
  // }
  // return maxProd;

//   // O(N2)
//   int n = arr.size();
//   int maxProd = INT_MIN;
//   for (int i = 0; i < n; i++) {
//     int product = 1;
//     for (int j = i; j < n; j++) {
//       product = product * arr[j];
//       maxProd = max(maxProd, product);
//     }
//   }
//   return maxProd;

	// O(N)
	int n = arr.size();
	int pre = 1, suff = 1;
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		if(pre == 0) pre = 1;
		if(suff == 0) suff = 1;

		pre = pre * arr[i];
		suff = suff * arr[n-i-1];
		ans = max(ans, max(pre,suff));
	}
	return ans;
}