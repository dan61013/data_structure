# Practice: https://ithelp.ithome.com.tw/articles/10237739

def main():
    # 入住名單
    arr = ["A", "c", "e", "r", "Y", "F", "R", "z", "G", "a"]

    # 退房
    arr[1] = ""
    arr[2] = ""
    arr[5] = ""
    arr[7] = ""
    arr[8] = ""

    # 換房
    arr[1] = arr[3]
    arr[3] = ""
    arr[2] = arr[6]
    arr[6] = ""
    arr[3] = arr[9]
    arr[9] = ""

    print(arr)

if __name__ == "__main__":
    main()
