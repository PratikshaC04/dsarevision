class Solution {
public:
    bool check(vector<int> candies,long long&k ,long long maxCandies)
    {
        long long  allocated = 0;
        cout<<maxCandies<<endl;
        for(int i = 0;i < candies.size();i++)
        {
            allocated += candies[i]/maxCandies;
            if(allocated >= k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        if(accumulate(candies.begin(),candies.end(),0LL) < k) return 0;
        long long l = 1;
        long long r = (accumulate(candies.begin(),candies.end(),0LL) / k);
        long long ans = 0;
        while(l <=r )
        {
            long long mid = l + (r - l)/2;
            if(check(candies,k,mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return static_cast<int> (ans);
    }
};