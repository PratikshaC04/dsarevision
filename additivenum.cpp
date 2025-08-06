class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long long> path;
        return backtrack(num, 0, path);
    }

private:
    bool backtrack(const string& num, int index, vector<long long>& path) {
        if (index == num.size()) {
            return path.size() >= 3;
        }

        long long currentNum = 0;
        for (int i = index; i < num.size(); ++i) {
            if (num[index] == '0' && i > index) break;

            // Overflow-safe digit build-up
            int digit = num[i] - '0';
            if (currentNum > (LLONG_MAX - digit) / 10) break; // prevent overflow
            currentNum = currentNum * 10 + digit;

            if (path.size() >= 2) {
                long long expectedSum = path[path.size() - 1] + path[path.size() - 2];
                if (currentNum < expectedSum) continue;
                if (currentNum > expectedSum) break;
            }

            path.push_back(currentNum);
            if (backtrack(num, i + 1, path)) return true;
            path.pop_back();
        }

        return false;
    }
};
