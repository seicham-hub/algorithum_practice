# Fermat's Last Theorem x**2 + y**2 = **2
# 3**2 + 4**2 = 5**2 OR 6**2 + 8**2 == 10**2
# Input 10, 2 => [(3,4,5),(6.8,10)]
# (x or y <= 10)
# Input 10, 3 => []
# Input 10, 4 => []
# Input 10, 5 => []

from typing import List,Tuple
import sys

def fermat_last_theory_v1(max_num:int,squire_num:int)->List[Tuple]:

    result:List[tuple] = []
    if squire_num <2:
        return result
    
    max_z = int(pow((max_num-1)**squire_num + max_num**squire_num,1.0/squire_num))
    for x in range(1,max_num+1):
        for y in range(x+1,max_num+1):
            for z in range(y+1,max_z):
                if x**squire_num + y**squire_num==z**squire_num:
                    result.append((x,y,z))

    return result

def fermat_last_theory_v2(max_num:int,squire_num:int)->List[Tuple]:

    result:List[tuple] = []
    if squire_num <2:
        return result
    
    for x in range(1,max_num+1):
        for y in range(x+1,max_num+1):
            pow_sum = pow(x,squire_num) + pow(y,squire_num)

            if pow_sum > sys.maxsize:
                raise ValueError(x,y,squire_num,pow_sum)

            z = pow(pow_sum,1.0/squire_num)
            z = int(z)
            z_pow = pow(z,squire_num)

            if pow_sum == z_pow:
                result.append((x,y,z))

    return result



if __name__ == '__main__':
    import time

    for n in range(2,10):
        start = time.time()
        print('v1',fermat_last_theory_v1(20,n))
        print('v1',time.time()-start)

        start = time.time()
        print('v2',fermat_last_theory_v2(20,n))
        print('v2',time.time()-start)