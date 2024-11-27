#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d\n", &N);

    char timestamp[256], log_entry[256], *longitude, *latitude, *end;
    for (int i = 0; i < N; i++) {
        fgets(timestamp, 256, stdin);
        fgets(log_entry, 256, stdin);

        longitude = strstr(log_entry, "\"longitude\":");
        latitude = strstr(log_entry, "\"latitude\":");
        if (longitude == NULL || latitude == NULL) {
            printf("01/01/1970 00:00:00 AM\n");
            return 0;
        }

        double lon_val = strtod(longitude + 12, &end);
        if (*end != ',') {
            printf("01/01/1970 00:00:00 AM\n");
            return 0;
        }

        double lat_val = strtod(latitude + 11, &end);
        if (*end != ',') {
            printf("01/01/1970 00:00:00 AM\n");
            return 0;
        }`

        if (lon_val != 0 && lat_val != 0) {
            printf("%s", timestamp);
            return 0;
        }
    }

    printf("01/01/1970 00:00:00 AM\n");
    return 0;
}
