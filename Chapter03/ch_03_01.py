# Binary Tree
import numpy as np

def full_binary_tree_cal():
    
    num = int(input('請輸入level: '))
    print(f"完滿二元樹節點: {(2**num)-1}")

def fully_binary_tree():
    """輸入index查找位置，回傳該節點的左右子節點(Children)，超出範圍可退出函式(input > 7)"""
    arr = np.array([None,'A','B','C','D','E','F','G'])
    
    
    while True:
        index = int(input('範例:完滿二元樹(Level:3)\n輸入查找位置: '))
        
        if 1 <= index <= ((2**(3-1))-1):
            print(f"{index}的左子樹: {arr[2*index]}\n{index}的左子樹: {arr[2*index+1]}")
        
        elif ((2**(3-1))-1) < index <= (len(arr) - 1):
            print(f"{index}沒有子樹")
        
        else:
            print("超出範圍")
            return False

def main():
    
    fully_binary_tree()
    # full_binary_tree_cal()

if __name__ == "__main__":
    main()