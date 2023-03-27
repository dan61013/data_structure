"""
Time Complexity Big-O(n^2)
"""

def main():
    
    list_a = [1, 2, 3]
    list_b = [4, 5, 6]
    
    for i in list_a:
        for j in list_b:
            print(i * j)

if __name__ == "__main__":
    main()