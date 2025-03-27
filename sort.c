#include <stdio.h>

void printArray(int l[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", l[i]);
    }
    printf("\n");
}

void customSort(int l[], int size) {
    int st = 0;
    int end = size - 1;

    while (st < end) {
        int max = l[st];
        int min = l[st];
        int max_index = st;
        int min_index = st;

        for (int k = st; k <= end; k++) {
            if (l[k] > max) {
                max = l[k];
                max_index = k;
            }
            if (l[k] < min) {
                min = l[k];
                min_index = k;
            }
        }

        int temp = l[st];
        l[st] = l[min_index];
        l[min_index] = temp;

        if (max_index == st) {
            max_index = min_index;
        }

        temp = l[end];
        l[end] = l[max_index];
        l[max_index] = temp;

        st += 1;
        end -= 1;
    }
}

int main() {
    int testCases[10][5] = {
        {3, 7, 1, 9, 5},
        {8, 4, 6, 2, 10},
        {5, 5, 5, 5, 5},
        {10, 20, 30, 40, 50},
        {99, 88, 77, 66, 55},
        {1, 2, 3, 4, 5},
        {9, 3, 6, 2, 7},
        {-5, -3, -7, -2, -6},
        {11, 22, 11, 22, 11},
        {0, 0, 0, 0, 0}
    };

    for (int i = 0; i < 10; i++) {
        int l[5] = {testCases[i][0], testCases[i][1], testCases[i][2], testCases[i][3], testCases[i][4]};
        customSort(l, 5);
        printArray(l, 5);
    }

    return 0;
}


