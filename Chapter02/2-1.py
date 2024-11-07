# Python實做Singly Linked List
# 參考資料: https://lovedrinkcafe.com/python-single-linked-list/

import os

# Node節點，包含data & pointer(next)
class Node():
    def __init__(self, data=None, next_node=None) -> None:
        self.data = data
        self.next_node = next_node

# 單向LinkedList，head指向第一個node, tail指向最後一個node
class SingleLinkedList():
    def __init__(self) -> None:
        self.head = None
        self.tail = None

    # append -> 從tail新增資料
    def append(self, data):

        new_node = Node(data)

        # 如果是空的linked list，則head and tail指向new_node
        if self.head is None:
            self.head = new_node
            self.tail = new_node

        # 如果不是空的，則tail.next_node指向new_node, tail就變成指向new_node
        else:
            self.tail.next_node = new_node
            self.tail = self.tail.next_node

    def delete(self):

        # linkedlist is empty
        if self.head is None:
            return print('This list is empty.')

        # if linkedlist只有1，則self.head等於空(刪除1 -> 0)
        if len(self) == 1:
            self.head = None

        else:
            # 大於1，則當前node則從頭開始
            current_node = self.head

            # 當前node的next_node不是空值
            while current_node.next_node != None:
                # list tail = 當前的node
                self.tail = current_node
                # 當前的node換成當前的node的下一個node，然後繼續執行
                current_node = current_node.next_node
            # while current_node.next_node = None, 則當前的tail, next為None
            self.tail.next_node = None

    def insert(self, index, data):
        """
        Insert the data to specific index.
        """
        if self.head is None:
            print("You can only insert the data to a not empty list.")
        # 超出範圍，如果index不是在1~len(self)的範圍內
        if not 1 <= index <= len(self):
            print(f'{index} is not in range.')

        elif index == 1:
            # 建立Node(data)
            new_node = Node(data)
            # new_node.next_node = self
            new_node.next_node = self.head
            # self.head，head改成new_node
            self.head = new_node

        else:
            # initialized the index = 1
            current_index = 1
            # create the new_node
            new_node = Node(data)
            # 從頭開始
            current_node = self.head

            # 當前的index + 1 如果不等於index則:
            while current_index + 1 != index:

                # 當前node變成當前的下一個node
                current_node = current_node.next_node
                # index + 1 (繼續執行到等於index停止)
                current_index += 1

            # 等於index時，new_node.next_node 等於當前node的下一個值
            new_node.next_node = current_node.next_node
            # 當前node的下一個值等於new_node
            current_node.next_node = new_node

    def delete_node_by_index(self, index):
        """
        Delete the specific node.
        """
        if self.head is None:
            print("You can only delete the data from a not empty list.")

        # 如果串列大於1，而刪除第一個node，則head換成下一個node
        if index == 1 and len(self) > 1:
            self.head = self.head.next_node

        # 串列跟index都是1，則整個linked list為空
        elif index == 1 and len(self) == 1:
            self.head = None
            self.tail = None

        # 如果index不是head or tail
        elif 1 < index < len(self):
            current_index = 1
            current_node = self.head

            while current_index != index:
                # 前一個node等於當前node
                previous_node = current_node
                # 當前node等於當前node的下一個node
                current_node = current_node.next_node
                # index + 1, 並繼續執行到當前index等於index
                current_index += 1
            # 前一個node的next，等於要刪除的current_node的next_node
            previous_node.next_node = current_node.next_node

        # 如果index是tail
        elif index == len(self):
            # 一樣從head開始
            current_index = 1
            current_node = self.head
            while current_index != index:
                # 前一個node等於現在這個node
                previous_node = current_node
                # 目前node = 目前node的下一個
                current_node = current_node.next_node
                # index 增加
                current_index += 1
            # tail等於前一個node
            self.tail = previous_node

        else:
            print("index is out range.")

    def reverse(self):
        """
        reverse the order of the list.
        """
        previous_node = None
        # 當前的node等於head
        current_node = self.head
        # tail等於當前的node
        self.tail = current_node
        # 下一個node等於當前node的下一個
        next_node = current_node.next_node

        # 當下一個node不是None
        while next_node is not None:
            # 當前node的下一個node，等於前一個node(reverse)
            current_node.next_node = previous_node
            # 前後互換
            previous_node = current_node
            # 前後互換
            current_node = next_node
            next_node = next_node.next_node

        current_node.next_node = previous_node
        self.head = current_node

    def __len__(self):

        length = 0
        current_node = self.head
        while current_node is not None:
            length += 1
            current_node = current_node.next_node
        return length

    def __str__(self):

        current_node = self.head
        chain = []
        index = 1
        while current_node is not None:
            chain.append("["+str(index)+"]"+str(current_node.data))
            index += 1
            current_node = current_node.next_node
        return " --> ".join(chain)

def main():

    l = SingleLinkedList()
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')
        print(__doc__)
        print(l)
        print(f"這個鏈結串列的長度為:{str(len(l))}")
        print("-"*20)
        opt = input("1. 加入資料\n2. 刪除資料\n3. 插入資料\n4. 刪除特定資料\n5. 反轉串列\n0. 結束程式\n 請輸入要使用的功能: ")

        if opt == "1":
            data = input("請輸入要加入的資料: ")
            l.append(data)
            print(l)

        elif opt == "2":
            l.delete()
            print(l)

        elif opt == "3":
            index = input("請輸入要插入的資料的index: ")
            data = input("請輸入要插入的資料")
            l.insert(int(index), data)
            print(l)

        elif opt == "4":
            index = input("請輸入要刪除的資料的index: ")
            l.delete_node_by_index(int(index))
            print(l)

        if opt == "5":
            l.reverse()
            print(l)

        if opt == "0":
            print(f"This Final result is {l}")
            return False

        print("請輸入合法指令")

if __name__ == "__main__":
    main()
