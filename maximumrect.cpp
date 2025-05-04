#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxArea = 0;
        int nCols = matrix[0].size();
        vector<int> height(nCols, 0);  // Histogram height

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < nCols; j++) {
                // Build histogram
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            maxArea = max(maxArea, getMaxArea(height));
        }

        return maxArea;
    }

    int getMaxArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);  // Sentinel to process all elements

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back();  // Clean up
        return maxArea;
    }
};

