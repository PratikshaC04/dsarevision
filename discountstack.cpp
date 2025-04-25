#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer = prices;
        stack<int> st;  // stack to store indices

        for (int i = 0; i < n; ++i) {
            // Check if current price is less than or equal to the one at the top of stack
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                int idx = st.top();
                st.pop();
                answer[idx] = prices[idx] - prices[i];  // apply discount
            }
            st.push(i);
        }

        return answer;
    }
};

