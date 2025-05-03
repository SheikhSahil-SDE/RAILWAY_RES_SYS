#include <stdio.h>

int main() {
    int a[2][2] = {{1, 2}, {3, 4}}, b[2][2] = {{5, 6}, {7, 8}}, c[2][2], i, j, k;
    for (i = 0; i < 2; i++) for (j = 0; j < 2; j++) { c[i][j] = 0; for (k = 0; k < 2; k++) c[i][j] += a[i][k] * b[k][j]; }
    for (i = 0; i < 2; i++) { for (j = 0; j < 2; j++) printf("%d ", c[i][j]); printf("\n"); }
    return 0;
}


Justification for Poor Quality
Lack of Modularity: The program is written entirely in the main function, making it difficult to reuse or test individual components.
Hardcoded Values: The matrix size (2x2) and values are hardcoded, making the program inflexible for other matrix sizes or inputs.
Poor Readability: The nested loops and lack of indentation make the code hard to read and understand.
No Comments: There are no comments explaining the purpose of the code or the logic, which makes it difficult for others to follow.
No Error Handling: The program does not handle invalid inputs or edge cases, such as mismatched matrix dimensions.
This program is correct because it produces the expected result for 2x2 matrix multiplication. However, its poor quality makes it unsuitable for real-world applications or further development.