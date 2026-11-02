#include <stdlib.h>
#include <string.h>

int *pos;
int *cols, *diag1, *diag2;

char ***result;
int resultSize = 0;
int capacity = 0;

int n;

void backtrack(int row) {
    if (row == n) {
        if (resultSize == capacity) {
            capacity = capacity == 0 ? 4 : capacity * 2;
            result = realloc(result, capacity * sizeof(char **));
        }

        result[resultSize] = malloc(n * sizeof(char *));

        for (int i = 0; i < n; i++) {
            result[resultSize][i] = malloc((n + 1) * sizeof(char));

            for (int j = 0; j < n; j++) {
                result[resultSize][i][j] =
                    (pos[i] == j) ? 'Q' : '.';
            }

            result[resultSize][i][n] = '\0';
        }

        resultSize++;
        return;
    }

    for (int col = 0; col < n; col++) {
        int d1 = row - col + n - 1;
        int d2 = row + col;

        if (cols[col] || diag1[d1] || diag2[d2])
            continue;

        pos[row] = col;

        cols[col] = 1;
        diag1[d1] = 1;
        diag2[d2] = 1;

        backtrack(row + 1);

        cols[col] = 0;
        diag1[d1] = 0;
        diag2[d2] = 0;
    }
}

char*** solveNQueens(int N, int* returnSize,
                     int** returnColumnSizes) {
    n = N;

    result = NULL;
    resultSize = 0;
    capacity = 0;

    pos = malloc(n * sizeof(int));
    cols = calloc(n, sizeof(int));
    diag1 = calloc(2 * n - 1, sizeof(int));
    diag2 = calloc(2 * n - 1, sizeof(int));

    backtrack(0);

    *returnSize = resultSize;

    *returnColumnSizes = malloc(resultSize * sizeof(int));

    for (int i = 0; i < resultSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    free(pos);
    free(cols);
    free(diag1);
    free(diag2);

    return result;
}
