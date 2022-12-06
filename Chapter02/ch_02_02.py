# Stack
import os, sys

def main():
    
    stack_list = []
    
    while True:
        
        user_command = input('1: Push\n2: Pop\n3: Peek\n4. Exit\n請輸入指令: \n')
        
        # Push
        if user_command == "1":
            data = input('請輸入新增資料: ')
            stack_list.append(data)
            print(list(reversed(stack_list)))
        
        # Pop
        elif user_command == "2":
            try:
                print('刪除最頂端的一筆資料')
                stack_list.pop()
                print(list(reversed(stack_list)))
            except:
                print("沒有資料可已刪除\nThe result stack: {}".format(stack_list))
        
        # Peek
        elif user_command == "3":
            if len(stack_list) >= 1:
                reversed_stack_list = list(reversed(stack_list))
                for i in reversed_stack_list:
                    print(i)
                print("最頂端的資料: {}".format(reversed_stack_list[0]))
            else:
                print("The stack is empty.")
        
        # Exit
        elif user_command == "4":
            print("Exit\nThe result stack: {}".format(list(reversed(stack_list))))
            return False
        
        # Error
        else:
            print("請輸入正確指令")

if __name__ == "__main__":
    main()