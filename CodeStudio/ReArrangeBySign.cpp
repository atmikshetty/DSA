vector<int> alternateNumbers(vector<int> &a) {
  // Write your code here.
//   // Brute force O(N) + O(N)
  vector<int> pos;
  vector<int> neg;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] > 0)
      pos.push_back(a[i]);
    else
      neg.push_back(a[i]);
  }
  for(int i=0;i<n/2;i++){
      a[2*i] = pos[i];
      a[2*i+1]  = neg[i];
  }
  return a;
//   O(N)
    int n = a.size();
    vector<int> ans(n,0);
    int positive = 0, negative=1;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            ans[positive] = a[i];
            positive += 2;
        }else{
            ans[negative] = a[i];
            negative += 2;
        }
    }
    return ans;
}