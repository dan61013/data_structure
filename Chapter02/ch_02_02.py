# Stack
import os, sys

def main():
    
    stack_list = []
    
    while True:
        
        user_command = input('1: Push\n2: Pop\n3: Peek\n4. 離開\n')
        
        if user_command == "1":
            a = input('請輸入要加入的資料: ')
            stack_list.append(a)
            print(stack_list)
        
        elif user_command == "2":
            try:
                print('刪除最頂端的一筆資料')
                stack_list.pop()
                print(stack_list)
            except:
                print("沒有資料可已刪除\nThe result stack: {}".format(stack_list))
                return False
        
        elif user_command == "4":
            print("Exit\nThe result stack: {}".format(stack_list))
            return False

if __name__ == "__main__":
    main()