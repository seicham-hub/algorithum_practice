# 偶数要素が先に来るように並べろ
# [0,1,3,4,2,4,5,1,6,9,8] → [0,4,2,4,6,8,1,3,5,1,9]
# 新しく配列は作成せず、既存配列をいじって実装 stableでなくてOK

from typing import List

def order_even_first_odd_last_v2(numbers:List[int])->None:
    i,j = 0,len(numbers)-1
    while i< j:
        if numbers[i] %2 == 0:
            i += 1
        else:
            numbers[i],numbers[j] = numbers[j],numbers[i]
            j -= 1


if __name__ == '__main__':
    l = [0,1,3,4,2,4,5,1,6,9,8]
    order_even_first_odd_last_v2(l)
    print(l)