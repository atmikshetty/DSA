class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() - 1;
        int leftSum = 0, rightSum = 0, maxSum = 0;
        // Taking the left side sums
        for (int i = 0; i < k; i++) {
            leftSum = leftSum + cardPoints[i];
        }
        maxSum = leftSum;

        // Right Sum
        int rightIndex = n;
        for (int i = k - 1; i >= 0; i--) {
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightIndex];
            rightIndex--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};