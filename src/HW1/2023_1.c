#include <stdio.h>

int is_arithmetic_sequence(int arr[], int n) {
    if (n <= 2)
        return 1;

    // 등차 수열인지 확인
    int diff = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i-1] != diff)
            return 0;
    }
    return 1;
}

int main() {
    int N;
    int A[100] = {0};

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int result = is_arithmetic_sequence(A, N);
    printf("%d", result);

    return 0;
}

