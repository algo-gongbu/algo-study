class Solution:
    
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        left = 0
        right = len(nums) - 1
        result = []
        snum = []
        
        for idx, num in enumerate(nums):
            snum.append((num, idx))
        # 부족한 만큼의 숫자를 찾도록 해야하나
        
        snum.sort(key = lambda x : x[0])
        
        while left < right:
            print("left" , left)
            print("right" ,  right)
            
            l = snum[left][0]
            r = snum[right][0]
            lidx = snum[left][1]
            ridx = snum[right][1]
            
            if l + r == target:    
                result.append(lidx)
                result.append(ridx)
                break
            elif l + r < target:
                left += 1
            elif l + r > target:
                right -= 1
        
        return result