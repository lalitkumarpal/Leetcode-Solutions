class Solution {
public:
    int longest(int start, vector<int>& nums){
        int length = 1;
        while(start<nums.size()-1 && nums[start]<nums[start+1]){
            length++;
            start++;
        }
        return length;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int length = longest(0,nums);
        int i = length;
        int ans = length/2;
        while(i<nums.size()){
            int new_length = longest(i,nums);
            ans = max(ans,new_length/2);
            ans = max(ans,min(length,new_length));
            length = new_length;
            i = i+length;
        }
        return ans;
    }
};