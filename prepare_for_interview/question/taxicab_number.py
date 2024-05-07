# 1729 = Ta(2) = 1**3 + 12**3 = 9**3 + 10**3
# Input 1, 2 => [(1729, [(1,12),(9,10)])]
# Input 2, 2 => [(1729,[(1,12),(9,10)]),(4104,[(2,16),(9,15)])]
# Input 1,3 => [(87539319,[(167,436),(228,423),(255,414)])]


from collections import defaultdict
from typing import List,Tuple


def taxi_cab_number(max_results_num: int ,required_pairs_num:int =2)->list[tuple[int,List[Tuple[int,int]]]]:
    results = []
    current_number = 1

    while len(results) < max_results_num:

        pairs = defaultdict(list)

        max_param = int(current_number**(1/3)) +1
        for x in range(1,max_param):
            for y in range(x+1,max_param):
                if x**3+y**3 == current_number:
                    pairs[current_number].append((x,y))
        
        if len(pairs[current_number]) == required_pairs_num:
            results.append((current_number,pairs[current_number]))

        current_number += 1
    
    return results

if __name__ == '__main__':
    print(taxi_cab_number(1,3))

def find_taxi_cab_num(count:int,conbination_count:int) -> List[Tuple]:    

    results:list[tuple] = []
    num = 1

    while True:
        x = 1
        y = 2
        conbination:list[tuple] = []
        
        while (x**3 + y**3) <= num:

            while (x**3 + y**3) <= num:
                if (x**3 + y**3) == num:
                    conbination.append((x,y))
                y += 1
            x +=1
            y = x+1

        if len(conbination) == conbination_count:
            results.append((num,conbination))

        if len(results) == count:
            break
        
        num += 1
    
    return results


# if __name__ == '__main__':
#     print(find_taxi_cab_num(2,2))