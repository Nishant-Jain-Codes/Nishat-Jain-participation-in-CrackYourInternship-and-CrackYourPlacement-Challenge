class Solution {
public:
    // Helper function to solve the problem using recursion
    int helper(vector<int>& points, int start, int end, int k) {
        if (k == 0)
            return 0;
        if (start > end)
            return 0;
        if (start == end)
            return points[start];

        // Choose the maximum between taking points from the start or the end
        return max(points[start] + helper(points, start + 1, end, k - 1),
                   points[end] + helper(points, start, end - 1, k - 1));
    }
    
    // Recursive solution to the problem
    // Time Complexity: O(2^N)
    // Space Complexity: O(N) {auxiliary stack space}
    int recursiveSolution(vector<int>& cardPoints, int k) {
        return helper(cardPoints, 0, cardPoints.size() - 1, k);
    }

    // Sliding window solution to the problem
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    int slidingWindow(vector<int>& cardPoints, int k) {
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int windowSum = 0;
        int answer = INT_MIN;
        int n = cardPoints.size();

        // If k equals the size of cardPoints, return total sum
        if (k == n)
            return totalSum;

        // Calculate the initial window sum for the first n - k elements
        for (int i = 0; i < n - k; ++i)
            windowSum += cardPoints[i];

        // Initialize the answer with the sum outside the initial window
        answer = totalSum - windowSum;

        // Slide the window from the start to the end
        for (int i = n - k; i < n; ++i) {
            windowSum += cardPoints[i] - cardPoints[i - (n - k)];
            answer = max(answer, totalSum - windowSum);
        }

        return answer;
    }

    // Main function to get the maximum score
    int maxScore(vector<int>& cardPoints, int k) {
        return slidingWindow(cardPoints, k);
    }
};
