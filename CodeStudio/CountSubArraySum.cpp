int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
  // Brute force O(N2)
  int count = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      if (sum == k) {
        count++;
      }
    }
  }
  return count;

// O(N)
  int n = arr.size();
  int count  = 0;
  int left = 0, right = 0;
  int sum = arr[0];
  while(right<n){
    while(left<=right && sum>k){
      sum -= arr[left];
      left++;
    }
    if(sum == k){
      count++;
    }
    right++;
    if(right<n){
      sum += arr[right];
    }
  }
  return count;

// Hashmap O(N)
map<int,int> mpp;
mpp[0] = 1;
int prefSum = 0, count = 0;
for(int i=0;i<arr.size();i++){
  prefSum += arr[i];
  int remove = prefSum - k;
  count += mpp[remove];
  mpp[prefSum] += 1;
}
return count;
}
