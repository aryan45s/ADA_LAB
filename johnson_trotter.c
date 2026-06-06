#include <stdio.h>
#include <stdlib.h>

// Function to print the permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Function to find the largest mobile element
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {
        // Check if moving left
        if (dir[i] == -1 && i != 0) {
            if (perm[i] > perm[i - 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
        // Check if moving right
        if (dir[i] == 1 && i != n - 1) {
            if (perm[i] > perm[i + 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

// Johnson-Trotter algorithm
void johnsonTrotter(int n) {
    int perm[n], dir[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = -1; // -1 means left, 1 means right
    }

    printPermutation(perm, n);

    while (1) {
        int mobileIndex = getMobile(perm, dir, n);

        if (mobileIndex == -1)
            break;

        int swapIndex = mobileIndex + dir[mobileIndex];

        // Swap elements
        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        // Swap directions as well
        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        // Change direction of all elements greater than mobile
        int mobileValue = perm[swapIndex];
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobileValue) {
                dir[i] = -dir[i];
            }
        }

        printPermutation(perm, n);
    }
}

// Driver code
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}