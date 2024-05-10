"""
Input 5,20
Output
[[7],[6,3],[6,0,15],[4,20,1,8],[6,4,4,1,0]]


min_path = 12
"""

from typing import List,Optional
import random

def generate_triangle_list(depth: int,max_num:int) -> List[List[int]]:
    return [[random.randint(0,max_num) for _ in range(i)] for i in range(1,depth+1)]


def print_triangle(data:List[List[int]])->None:
    max_digit = len(str(max([max(l) for l in data])))
    width = max_digit + (max_digit%2) +2

    for index,line in enumerate(data):
        numbers = ''.join([str(i).center(width,' ') for i in line])
        print(' '*int(width/2)*(len(data)-index),numbers)

def sum_min_path(triangle:list[list[int]])->Optional[int]:
    tree_sum = triangle[:]

    j,len_triangle = 1,len(triangle)
    if not len_triangle:
        return
    
    while j < len_triangle:
        line = triangle[j]
        line_path_sum = []
        for i,value in  enumerate(line):
            if i == 0:
                sum_value = line[i] + tree_sum[j-1][0]
            elif i == len(line)-1:
                sum_value = line[i] + tree_sum[j-1][i-1]
            else:
                min_path = min(tree_sum[j-1][i-1],tree_sum[j-1][i])
                sum_value = line[i] + min_path

            line_path_sum.append(sum_value)
        tree_sum[j] = line_path_sum
        j += 1

    return min(tree_sum[-1])
                



if __name__ == "__main__":
    t = generate_triangle_list(5,20)
    print_triangle(t)

    print('min path =',sum_min_path(t))


# import random
# from typing import List

# def generate_triangle(h:int,max_num:int) -> List[List[int]]:

#     triangle = []

#     for i in range(h):
#         triangle.append([random.randint(0,max_num) for _ in range(i+1)])

#     return triangle

# def get_minimum_path(triangle:List[List[int]]):
#     result = []

#     def _get_minimum_path(now_position:tuple,point:int):

#         y:int = now_position[0]
#         x:int = now_position[1]

#         point += triangle[y][x]

#         if y >= len(triangle)-1:
#             result.append(point)
#             return
        

#         _get_minimum_path((y+1,x),point)
#         _get_minimum_path((y+1,x+1),point)

#     start_point = 0
#     start = (0,0)

#     _get_minimum_path(start,start_point)

#     return min(result)


# if __name__ == "__main__":
#     tri = generate_triangle(5,20)

#     ans = get_minimum_path(tri)
#     print(ans)