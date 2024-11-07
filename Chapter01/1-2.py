# Multidimensional Arrays

def main():

    # One-Dimensional
    arr = [1, 2, 3]
    print(arr[0])

    # Two-Dimensional
    arr = [[1, 2], [3, 4]]
    print(arr[0][1])

    # Three-Dimensional
    arr = [
        [
            [1, 2, 3],
            [4, 5, 6]
        ],
        [
            [7, 8, 9],
            [10, 11, 12]
        ]
    ]

    print(arr[0][1][2])  # 6
    print(arr[1][0][1])  # 8

if __name__ == "__main__":
    main()
