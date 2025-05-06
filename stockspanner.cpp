class StockSpanner {
private:
    stack<pair<int, int>> s; // {price, span}

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        // Accumulate spans while the current price is greater or equal
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }

        s.push({price, span});
        return span;
    }
};

