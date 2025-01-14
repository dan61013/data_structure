# insertion sort

DATA = [5, 11, 34, 1, 12]

def main():
    n = len(DATA)
    for j in range(1, n):
        temp = DATA[j]
        i = j - 1
        while i >= 0 and temp < DATA[i]:
            DATA[i+1] = DATA[i]
            i -= 1
        DATA[i+1] = temp
    print(DATA)

if __name__ == "__main__":
    main()
