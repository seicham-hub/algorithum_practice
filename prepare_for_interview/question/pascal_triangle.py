from typing import List
def generate_pascal_triangle(depth:int) -> List[List[int]]:
    data = [[1] * (i+1) for i in range(depth)]

    for line in range(2,depth):
        for i in range(1,line):
            data[line][i] = data[line-1][i-1]+data[line-1][i]

    return data

def print_pascal(data:List[int])->None:
    max_digit = len(str(max(data[-1])))
    width = max_digit + (max_digit%2) + 2
    for index,line in enumerate(data):
        numbers = ''.join([str(i).center(width,'*') for i in line])
        print((' '*int(width/2)) * (len(data)-index),numbers)


if __name__ == "__main__":
    
    r = generate_pascal_triangle(10)
    print_pascal(r)



# def get_pascal_triangle(height:int):
#     result = [[] for _  in range(height)]

#     w = 2*height-1
#     mid = w//2

    
    
#     for h in range(height):
#         result[h] = [" " for _ in range(2*height-1)]
#         print(result[0][1])
        
#         if h == 0:
#             result[h][mid] = 1
        
#         if h %2 == 0: 
#             for i in range(h//2+1) :
#                 if h >= 1 and mid-2*i-1 >=0 and mid-2*i+1 < w and mid+2*i-1>=0 and mid+2*i+1 < w:
#                     if result[h-1][mid-2*i-1] != ' ' and result[h-1][mid-2*i+1] != ' ' and result[h-1][mid+2*i-1] != '' and result[h-1][mid+2*i+1] != ' ':
#                         result[h][mid-2*i] = result[h-1][mid-2*i-1] + result[h-1][mid-2*i+1]
#                         result[h][mid+2*i] = result[h-1][mid+2*i-1] + result[h-1][mid+2*i+1]
#                     else:
#                         result[h][mid-2*i] = 1
#                         result[h][mid+2*i] = 1 
#                 else:
#                     result[h][mid-2*i] = 1
#                     result[h][mid+2*i] = 1    
#         else:
#              for i in range(h//2+1) :
#                 if h >= 1 and mid-1-2*i-1 >=0 and mid-1-2*i+1 < w and mid+1+2*i-1>=0 and mid+1+2*i+1 < w:
#                     if result[h-1][mid-1-2*i-1] != ' ' and result[h-1][mid-1-2*i+1] != ' ' and result[h-1][mid+1+2*i-1] != ' ' and result[h-1][mid+1+2*i+1] != ' ':
#                         result[h][mid-1-2*i] = result[h-1][mid-1-2*i-1] + result[h-1][mid-1-2*i+1]
#                         result[h][mid+1+2*i] = result[h-1][mid+1+2*i-1] + result[h-1][mid+1+2*i+1]
#                     else:
#                         result[h][mid-1-2*i] = 1
#                         result[h][mid+1+2*i] = 1 
#                 else:
#                     result[h][mid-1-2*i] = 1
#                     result[h][mid+1+2*i] = 1 
#     return result



# if __name__ == "__main__":
#     for r in get_pascal_triangle(7):
#         print(''.join([str(c) for c in r]))


    