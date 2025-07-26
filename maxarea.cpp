class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int maxi = 0;

        while (start < end) {
            int h = min(height[start], height[end]);
            int w = end - start;
            int area = h * w;
            maxi = max(maxi, area);

            // Move the pointer with the smaller height
            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }

        return maxi;
    }
};