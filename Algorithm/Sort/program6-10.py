"""
Merge sort with recursive
Original: https://ithelp.ithome.com.tw/articles/10278179
"""

def merge(left, right):
    result = []

    while len(left) and len(right):
        if (left[0] < right[0]):
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
    result = result + left if len(left) else result + right
    return result

def merge_sort(arr):
    # Array只有1個元素 直接return
    if (len(arr) < 2):
        return arr
    
    mid = len(arr) // 2
    left_arr = arr[:mid]
    right_arr = arr[mid:]

    return merge(merge_sort(left_arr), merge_sort(right_arr))

if __name__ == "__main__":
    data = [54, 3, 12, 11, 7, 61]
    print(merge_sort(data))
