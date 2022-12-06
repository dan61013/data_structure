# Queue

def main():
    
    queue_list = []
    
    while True:
        
        user_command = input("1. Add\n2. Delete\n3. Front\n4. Exit\n請輸入指令: ")
        
        if user_command == "1":
            data = input("請輸入新增資料: ")
            queue_list.append(data)
            print(queue_list)

        elif user_command == "2":
            if len(queue_list) >= 1:
                queue_list.pop(0)
                print(queue_list)
            else:
                print("The queue is empty.")
        
        elif user_command == "3":
            if len(queue_list) >= 1:
                print(queue_list)
                print("最前端的資料:{}".format(queue_list[0]))
            else:
                print("The queue is empty, you have to add a data.")
        
        elif user_command == '4':
            print("Exit\nThe result: {}".format(queue_list))
            return False
        
        else:
            print("請輸入正確指令")
            
if __name__ == "__main__":
    main()