

def memoize(f):
    cache = {}
    def __wrapper__(n):
        if n not in cache:
            cache[n] = f(n)
        return cache[n]
    return __wrapper__

@memoize
def long_func(num:int) ->int:
    r=0
    for i in range(10000000):
        r += i*num
    
    return r



if __name__ == '__main__':

    for i in range(10):
        print(long_func(i))
    for i in range(10):
        print(long_func(i))

# def memoize(f):
#     cache = {}
#     def __wrapper__(n):
#         if n not in cache:
#             cache[n] = f(n)
#         return cache[n]
#     return __wrapper__

# @memoize
# def long_func(num: int) ->int:

#     r = 0
#     for i in range(10000000):
#         r += num*i
#     return r


# if __name__ == '__main__':
#     for i in range(10):
#         print(long_func(i))
#     for i in range(10):
#         print(long_func(i))



