"""
Time Complexity Big-O(n)
"""

def main():
    list_a = []
    list_b = []
    
    for i in range(3):
        list_a.append(i)
    
    for i in range(70):
        list_b.append(i)
    
    for i in list_a:
        print(f"ListA[{i}]: {i}")
    
    for i in list_b:
        print(f"ListB[{i}]: {i}")

if __name__ == "__main__":
    main()