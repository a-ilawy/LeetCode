class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        numsWithoutZero = []
        isZero=False
        countZeros=0
        res=[]
        # check zeros in nums
        for n in nums:
            if n==0:
                countZeros+=1
                if countZeros==2: break
                isZero=True
            else:
                numsWithoutZero.append(n)
        if countZeros==2:
            for n in nums:
                res.append(0)
            return res
        else:
            mlt = 0 if len(numsWithoutZero) == 0 else 1
            for n in numsWithoutZero:
                mlt*=n
        
            for n in nums:
                if isZero:
                    if n!=0:
                        res.append(0)
                    else:
                        res.append(mlt)
                else:
                    res.append(int(mlt/n))
            return res