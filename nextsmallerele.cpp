#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElements(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    vector<int> result = nextSmallerElements(arr);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
