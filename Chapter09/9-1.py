"""
Time Complexity Big-O(1)
"""

def main():
    list_a = []
    list_b = []
    
    for i in range(7):
        list_a.append(i)
    
    for i in range(70):
        list_b.append(i)
    
    print(f"ListA[2]: {list_a[2]}")
    print(f"ListB[3]: {list_b[3]}")

if __name__ == "__main__":
    main()