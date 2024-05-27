#include <stdio.h>
#include <string.h>

int main() {
    char ch, ar1[100] = "01111110", ar2[50];
    int count = 0, i = 8, j, k = 0;
    printf("Enter data to be transmitted: ");

    // Read data until a newline character is encountered
    while ((ch = getchar()) != '\n') {
        if (ch == '1')
            count++;
        else
            count = 0;

        ar1[i++] = ch;

        if (count == 5) {
            ar1[i++] = '0';
            count = 0;
        }
    }

    strcat(ar1, "01111110");
    printf("\nTransmitted bit stream (after stuffing) at the transmitter side is: %s", ar1);

    // Destuffing process
    j = strlen(ar1);
    count = 0;
    k = 0;

    for (i = 8; i < j - 8; i++) {
        if (ar1[i] == '1')
            count++;
        else
            count = 0;

        ar2[k++] = ar1[i];

        if (count == 5 && ar1[i + 1] == '0') {
            i++;
            count = 0;
        }
    }
    ar2[k] = '\0';

    printf("\nDestuffed data at the receiver is: %s\n", ar2);

    return 0;
}