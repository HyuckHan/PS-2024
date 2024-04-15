#include <stdio.h>

int count_lucky_number(int N, int K, int A[]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int current = A[i];
        while (current > 0) {
            int digit = current % 10;
            if (digit == K) {
                count++;
            }
            current /= 10;
        }
    }
    return count;
}

int main() {
    int N, K;
    int A[1000];
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int result = count_lucky_number(N, K, A);
    printf("%d", result);

    return 0;
}
