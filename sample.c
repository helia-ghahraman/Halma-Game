#include <stdio.h>


void printMap(int n) {
    int i, j, m, p;
    m = 2 * n;
    p = 3 * n;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= p; j++) {
            if (i == 0) {
                if (j == 0) {
                    printf("%c", 201);
                }
                else if (j == p) {
                    printf("%c", 187);
                }
                else if (j % 3 == 0) {
                    printf("%c", 203);
                }
                else {
                    printf("%c%c", 205, 205);
                }
            }
            else if (i == m) {
                if (j == 0) {
                    printf("%c", 200);
                }
                else if (j == p) {
                    printf("%c", 188);
                }
                else if (j % 3 == 0) {
                    printf("%c", 202);
                }
                else {
                    printf("%c%c", 205, 205);
                }
            }
            else if (i > 0 && i < m) {
                if (i % 2 == 0) {
                    if (j == 0) {
                        printf("%c", 204);
                    }
                    else if (j == p) {
                        printf("%c", 185);
                    }
                    else if (j % 3 == 0) {
                        printf("%c", 206);
                    }
                    else {
                        printf("%c%c", 205, 205);
                    }
                }
                else {
                    if (j % 3 == 0) {
                        printf("%c", 186);
                    }
                    else {
                        printf("  ");
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    printMap(n);
    return 0;
}
