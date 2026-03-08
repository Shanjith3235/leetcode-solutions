#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    qsort(strs, strsSize, sizeof(char*), cmp);

    char* first = strs[0];
    char* last = strs[strsSize - 1];

    int i = 0;
    while (first[i] && first[i] == last[i]) {
        i++;
    }

    char* res = (char*)malloc((i + 1) * sizeof(char));
    strncpy(res, first, i);
    res[i] = '\0';

    return res;
}