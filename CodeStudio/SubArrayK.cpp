int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Brute Force O(N3)
    int len = 0;
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long sum = 0;
            for(int m=i;m<=j;m++){
                sum += a[m];
            }
            if(sum == k){
                len = max(len, j-i+1);
            }
        }
    }
    return len;

  // O(N2)
  int len = 0;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    long sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      if (sum == k) {
        len = max(len, j - i + 1);
      }
    }
  }
  return len;

// O(2N)
int n = a.size();
int left = 0, right = 0;
long long sum = a[0];
int maxLen = 0;
while(right < n){
    while(left <= right && sum>k){
        sum -= a[left];
        left++;
    }
    if(sum == k){
        maxLen = max(maxLen, right-left+1);
    }
    right++;
    if(right <n){
        sum += a[right];
    }
}
return maxLen;
}