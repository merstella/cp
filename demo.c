#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

typedef struct
{
    char studentID[11];
    char submitDate[11];
    char submitTime[10];
    int result;
} LOG;
//=======================================================================
// Hàm d?c log và luu vào m?ng log logArr
// Hàm tr? v? s? lu?ng dòng log d?c du?c qua tên hàm
// k?t thúc dòng log s? là giá tr? -1
int readLog(LOG *logArr)
{
    int i = 0;
    while (1) {
        if (i < MAX_SIZE) {
            scanf("%s", logArr[i].studentID);
            if (strcmp(logArr[i].studentID, "-1") == 0) break;
            else
                scanf(" %s %s %d", logArr[i].submitDate, logArr[i].submitTime, &logArr[i].result);

            i++;
        }
        else  break;
    }

    return 0;
}

// hàm th?ng kê s? lu?ng sinh viên dã g?i bài d?a trên d? li?u log t? m?ng Log
// s? lu?ng log trong m?ng là size
int numberofSubmits(LOG *logArr, int size)
{
    // sinh viên code t?i dây
    int cnt = 0;
    int a[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (a[i] == 0)
            cnt++;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(logArr[i].studentID, logArr[j].studentID) == 0) {
                //a[i]=1;
                a[j] = 1;
            }

        }
    }
    return cnt;
}
int main()
{

    LOG* logArr = NULL;
    int size;
    logArr = (LOG*) malloc(MAX_SIZE * sizeof(LOG));
    char nextCommand[100];
    while (1)
    {
        fgets(nextCommand, sizeof(nextCommand), stdin);
        nextCommand[strcspn(nextCommand, "\r\n")] = 0;
        if (strlen(nextCommand) == 0) continue;
        if (nextCommand[0] != '?') break;
        if (strcmp(&nextCommand[2], "readLog") == 0) {
            size = readLog(logArr);
        }
        else if (strcmp(&nextCommand[2], "numberofSubmits") == 0) {
            int numSubmits = numberofSubmits(logArr, size);
            printf("Number of Submits: %d\n", numSubmits);
        }
    }
    free(logArr);
    return 0;
}