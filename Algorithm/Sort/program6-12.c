// heap sort using array
#include <conio.h>
#include <stdio.h>

int arr[20], n;

// display the array
void display() {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// insert num to loc(index)
void insert(int num, int loc) {
    // par is parent
    int par;

    // while not root node(0)
    while (loc > 0) {
        // set parent node (index-1)/2
        par = (loc-1)/2;
        // if num < parent value
        if (num <= arr[par]) {
            arr[loc] = num;
            return;
        }
        // if num > parent value, arr[loc] = parent value
        arr[loc] = arr[par];
        // let loc equal parent(index) and then compare with the above subtree
        loc = par;
    }
    // if line 29 doesn't return and then set arr[0] as num (root node)
    arr[0] = num;
}

// create heap
void createHeap() {
    int i;
    for (i = 0; i < n; i++) {
        insert(arr[i], i);
    }
}

// delete root node and put is to the rear of array
void delRoot(int last) {
    int left, right, i, temp;
    i = 0;
    // root=node(0)
    temp = arr[i];
    // change arr[0] to the last position
    arr[i] = arr[last];
    // assign the root value
    arr[last] = temp;

    // initialize left=node(1), right=node(2)
    left = 2*i + 1;
    right = 2*i + 2;

    while (right < last) {
        // if arr[current] >= left and right node
        if (arr[i] >= arr[left] && arr[i] >= arr[right]) {
            return;
        }
        // if right <= left, change each other
        if (arr[right] <= arr[left]) {
            temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            i = left;
        }
        // else change i and left
        else {
            temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            // i=right. since need to check the next larger value
            i = right;
        }
        left = 2*i + 1;
        right = 2*i + 2;
    }
    // produce the last node
    if (left == last - 1 && arr[i] < arr[left]) {
        temp = arr[i];
        arr[i] = arr[left];
        arr[left] = temp;
    }
}

void heapSort() {
    int last;

    // delRoot
    for (last = n - 1; last > 0; last--) {
        delRoot(last);
    }
}

void main() {
    int i;
    system("cls");
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nEntered list is: \n");
    display();

    createHeap();

    printf("\nHeap is: \n");
    display();

    heapSort();
    printf("\nSorted list is: \n");
    display();
    getch();
}