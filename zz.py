from heapq import *

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        minq = []
        maxq = []
        ans = []
        d = {} 
        
        for i in range(k):
            heappush(maxq, -nums[i])
        
        for _ in range(k//2):
            heappush(minq, -heappop(maxq))
            
        for i in range(k, len(nums)):
            if k % 2 == 0:
                ans.append((-maxq[0] + minq[0])/2)
            else:
                ans.append(-maxq[0])
                
            rm = nums[i-k]
            add = nums[i]
            
            bal = 0
            if rm <= -maxq[0]:
                bal -= 1
                if rm == -maxq[0]:
                    heappop(maxq)
                else:
                    d[rm] = d.get(rm, 0) + 1
            else:
                bal += 1
                if rm == minq[0]:
                    heappop(minq)
                else:
                    d[rm] = d.get(rm, 0) + 1
                    
            if maxq and add <= -maxq[0]:
                bal += 1
                heappush(maxq, -add)
            else:
                bal -= 1
                heappush(minq, add)
                
            while bal < 0:
                heappush(maxq, -heappop(minq))
                bal += 2
            while bal > 0:
                heappush(minq, -heappop(maxq))
                bal -= 2
                
            while maxq and d.get(-maxq[0], 0) > 0:
                d[-maxq[0]] -= 1
                heappop(maxq)
            while minq and d.get(minq[0], 0) > 0:
                d[minq[0]] -= 1
                heappop(minq)
                
        if k % 2 == 0:
            ans.append((-maxq[0] + minq[0])/2)
        else:
            ans.append(-maxq[0])
            
        return ans