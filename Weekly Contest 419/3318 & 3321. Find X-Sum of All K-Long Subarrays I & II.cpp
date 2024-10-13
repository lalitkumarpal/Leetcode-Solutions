// For 3318


class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        set<pair<long long, long long>> sums;   
        unordered_map<long long, long long> mp; 
        vector<int> ans;


        for (int i = 0; i < k && i < n; i++) {
            int to_add = nums[i];
            sums.erase(
                {mp[to_add], to_add}); 
            mp[to_add]++;
            sums.insert({mp[to_add], to_add});
        }


        auto calculate_top_x_sum = [&](int x) -> long long {
            long long sum = 0;
            int count = x;
            for (auto it = sums.rbegin(); it != sums.rend() && count > 0;
                 ++it, --count) {
                sum += it->first * it->second; 
            }
            return sum;
        };

        ans.push_back(calculate_top_x_sum(x));

        for (int i = k; i < n; i++) {
            int to_remove = nums[i - k];
            int to_add = nums[i];

            sums.erase({mp[to_remove], to_remove}); 
            mp[to_remove]--;
            if (mp[to_remove] > 0) {
                sums.insert({mp[to_remove],
                             to_remove}); 
            }


            sums.erase(
                {mp[to_add], to_add}); 
            mp[to_add]++;
            sums.insert({mp[to_add], to_add}); 
            ans.push_back(calculate_top_x_sum(x));
        }

        return ans;
    }
};

// for 3318 and 3321

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size(); 
        unordered_map<long long, long long> freq;   
        set<pair<long long, long long>> left, right; 
        long long sum = 0;              
        vector<long long> ans;          

        auto add_right = [&](long long count, long long value) {
            right.insert({count, value}); 
            sum +=   count * value;   
            if (right.size() > x) {       \
                auto smallest = *right.begin();   
                sum -=  smallest.first * smallest.second; 
                left.insert(smallest);    
                right.erase(right.begin()); 
            }
        };

        auto remove_right = [&](long long count, long long value) {
            auto smallest = *right.begin(); 
            auto current = make_pair(count, value); 
            if (current >= smallest) {  
                sum -=  count * value; 
                right.erase(current);    
                if (left.size() && right.size() < x) { 
                    auto largest = *left.rbegin(); 
                    sum +=  largest.first * largest.second; 
                    right.insert(largest); 
                    left.erase(largest);   
                }
            } else {
                left.erase(current); 
            }
        };

        int i = 0; 
        for (int j = 0; j < n; j++) { 
            
            if (freq[nums[j]] > 0) {
                remove_right(freq[nums[j]], nums[j]); 
            }
            freq[nums[j]]++; 
            add_right(freq[nums[j]], nums[j]); 

            
            if (j - i + 1 > k) { 
                remove_right(freq[nums[i]], nums[i]); 
                freq[nums[i]]--; 
                if (freq[nums[i]] > 0) { 
                    add_right(freq[nums[i]], nums[i]);
                }
                i++; 
            }

            
            if (j - i + 1 == k) {
                ans.push_back(sum); 
            }
        }

        return ans; 
    }
};
