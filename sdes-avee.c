#include <stdio.h>
#include <stdlib.h>

// Permutation tables
int initialPermutation(int input) {

}

int expansion(int input) {
    // ... (unchanged)
}

int substitution(int input, int **sBox, int rows, int cols) {
    int row = ((input & 0x08) >> 2) | (input & 0x01);
    int col = (input & 0x06) >> 1;
    return sBox[row][col];
}

int permutation(int input) {
    // ... (unchanged)
}

// Key generation functions
int generateSubKey(int key, int round) {
    // ... (unchanged)
}

// Function to take S-box input from the user
void inputSBox(int ***sBox, int *rows, int *cols) {
    printf("Enter S-box matrix size (rows cols): ");
    scanf("%d %d", rows, cols);

    *sBox = (int **)malloc(*rows * sizeof(int *));
    for (int i = 0; i < *rows; ++i) {
        (*sBox)[i] = (int *)malloc(*cols * sizeof(int));
    }

    printf("Enter S-box values (%dx%d matrix, row-wise):\n", *rows, *cols);
    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *cols; ++j) {
            scanf("%d", &(*sBox)[i][j]);
        }
    }
}

// Function to take key and plaintext input from the user
void userInput(int *plaintext, int *key) {
    printf("Enter 8-bit plaintext (binary): ");
    scanf("%d", plaintext);

    printf("Enter 10-bit key (binary): ");
    scanf("%d", key);
}

// S-DES encryption function
int sdesEncrypt(int plaintext, int key, int **sBox, int rows, int cols) {
    // ... (unchanged)
}

// Function to free memory allocated for S-box
void freeSBox(int **sBox, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(sBox[i]);
    }
    free(sBox);
}

int main() {
    int plaintext, key;
    int **sBox;
    int rows, cols;

    // Take user input for S-box, plaintext, and key
    inputSBox(&sBox, &rows, &cols);
    userInput(&plaintext, &key);

    // Perform S-DES encryption
    int ciphertext = sdesEncrypt(plaintext, key, sBox, rows, cols);

    // Display results
    printf("Plaintext: %d\n", plaintext);
    printf("Key: %d\n", key);
    printf("Ciphertext: %d\n", ciphertext);

    // Free allocated memory for S-box
    freeSBox(sBox, rows);

    return 0;
}
