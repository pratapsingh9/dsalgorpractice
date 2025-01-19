import slidignWindow as s

class Solution(object):
    def sortArrayByParityII(self, nums):
        answer = nums
        n = len(answer)
        oddidx = 1
        evenidx = 0

        while oddidx < n and evenidx < n:
            while evenidx < n and answer[evenidx] % 2 == 0:
                evenidx += 2
            while oddidx < n and answer[oddidx] % 2 == 1:
                oddidx += 2

            if evenidx < n and oddidx < n:
                nums[evenidx], nums[oddidx] = nums[oddidx], nums[evenidx]
        return answer


class Values:
    def vales(self, price):
        for i in price:
            print(price)


class Solution(object):
    def finalPrices(self, prices):
        n = len(prices)
        result = prices[:]

        for i in range(n):
            for j in range(i + 1, n):
                if prices[j] <= prices[i]:
                    result[i] -= prices[j]
                    break
        return result


class Cycle:
    car=0
    def __init__(self, car: int, subject: str):
        self.car = car
        self.subject = subject
        
    def printworking():
        print("wroking the procces worked out")
