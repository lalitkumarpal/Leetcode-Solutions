// Brute Force

class Solution {
public:
    
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        while(k--){
            int index = max_element(nums.begin(),nums.end())- nums.begin();
            ans+=nums[index];
            int r=ceil(nums[index]/3.0);
            nums[index]=r;
        }
        return ans;
    }
};

// Optimised

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto i : nums) {
            pq.push(i);
        }
        long long ans = 0;
        while (k--) {
            auto p = pq.top();
            pq.pop();
            ans += p;
            pq.push(ceil(p / 3.0));
        }
        return ans;
    }
};