"""
Quick Sort
Using Array(list) and recursive
Original: https://ithelp.ithome.com.tw/articles/10278644
"""

def quick_sort(arr):
    n = len(arr)
    # if there's only one element, return array
    if n <= 1:
        return arr
    # set the variables
    left_arr = []
    right_arr = []
    # set the pivot pointer
    piv = arr[0]
    for i in range(1, n):
        if arr[i] < piv:
            left_arr.append(arr[i])
        else:
            right_arr.append(arr[i])
    # sort the sublist
    return quick_sort(left_arr) + [piv] + quick_sort(right_arr)

def main():
    data = []
    number_of_elements = int(input("Enter the number of elements: "))
    for i in range(number_of_elements):
        ele = int(input(f"Enter the number {i + 1}: "))
        data.append(ele)
    print(quick_sort(data))

if __name__ == "__main__":
    main()
