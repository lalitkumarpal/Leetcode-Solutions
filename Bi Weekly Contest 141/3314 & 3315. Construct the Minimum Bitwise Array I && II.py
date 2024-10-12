# Problem 3314. Construct the Minimum Bitwise Array I

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        maxEle = max(nums)
        ans = []
        p = {}

        for i in range(1, maxEle + 1):
            k = i | (i + 1)
            if k not in p:
                p[k] = i
        for i in nums:
            if i in p:
                ans.append(p[i])
            else:
                ans.append(-1)

        return ans


# Probelm 3314 & 3315. Construct the Minimum Bitwise Array I && II

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n=len(nums)
        ans = [-1]*n
        for i in range(n):
            num=nums[i]
            found = False
            min_val=float('inf')
            for bit in range(31):
                candidate = num & ~(1<<bit)
                if candidate<0:
                    continue
                if candidate | (candidate + 1) == num:
                    if candidate<min_val:
                        min_val=candidate
                        found = True
            ans[i]=min_val if found else -1            
            
        
        return ans