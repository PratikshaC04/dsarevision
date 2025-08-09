class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long prev = 0;

        for (int num : nums) {
            if (num == prev) continue; 
            long long gap = num - prev - 1;

            if (gap >= k) {
                sum += (long long)(prev + 1 + prev + k) * k / 2;
                return sum;
            } else {
                sum += (long long)(prev + 1 + num - 1) * gap / 2;
                k -= gap;
            }

            prev = num;
        }
        sum += (long long)(prev + 1 + prev + k) * k / 2;

        return sum;
    }
};
long long minimalsum(vector<int>& nums,int k)
{
    for(int num :num)
    {

 if (gap >= k) 
 {
                sum += (long long)(prev + 1 + prev + k) * k / 2;
                return sum;
     } else 
     {
                sum += (long long)(prev + 1 + num - 1) * gap / 2;
                k -= gap;
            }

            prev = num;
        }
        sum += (long long)(prev + 1 + prev + k) * k / 2;

        return sum;
    }

