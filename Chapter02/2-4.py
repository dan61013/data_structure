# https://ithelp.ithome.com.tw/questions/10211197

def main():
    
    n = int(input('輸入正奇數: '))
    lst = []
    
    if n % 2 != 0:
        for i in range(1, ((n+1)*2-1), 2):
            lst.append(i)
        for i in range(1, len(lst), 2):
            lst[i] *= -1
        print(lst, len(lst))
    
    else:
        print("請輸入正奇數\n結束程式")

if __name__ == "__main__":
    main()