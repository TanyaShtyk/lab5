#include <stdio.h>

int main() {
    int data[7];
    int received[7];
    int error_position = 0;

    printf("Введіть 4 біти, через пробіл:\n");
    scanf("%d %d %d %d", &data[2], &data[4], &data[5], &data[6]);

    data[0] = data[2] ^ data[4] ^ data[6]; // P1
    data[1] = data[2] ^ data[5] ^ data[6]; // P2
    data[3] = data[4] ^ data[5] ^ data[6]; // P4

    printf("Закодоване повідoмлення: ");
    for (int i = 0; i < 7; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    printf("Введіть отримане повідомлення (7 бітів), через пробіл:\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &received[i]);
    }

    int p1 = received[0] ^ received[2] ^ received[4] ^ received[6];
    int p2 = received[1] ^ received[2] ^ received[5] ^ received[6];
    int p4 = received[3] ^ received[4] ^ received[5] ^ received[6];

    error_position = p1 + (p2 << 1) + (p4 << 2);

    if (error_position == 0) {
        printf("Повідoмлення не мiстить помилок!\n");
    } else {
        printf("Помилка в біті %d!\n", error_position);

        received[error_position - 1] ^= 1;
        printf("Виправлене повідомлення: ");
        for (int i = 0; i < 7; i++) {
            printf("%d", received[i]);
        }
    }
    return 0;
}