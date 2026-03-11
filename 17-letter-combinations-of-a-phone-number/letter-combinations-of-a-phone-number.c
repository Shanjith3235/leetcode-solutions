/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char *phone[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len = strlen(digits);
    int i = 0;
    int j = 0;
    int n = 0;
    char **ps;
    char **reset;
    char **strings;
    
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }
    ps = (char **)calloc(len, sizeof(char *));
    reset = (char **)calloc(len, sizeof(char *));
    n = 1;
    for (i = 0; i < len; i++) {
        switch (*(digits+i)) {
            case '2': ps[i] = phone[0]; n *= 3; break;
            case '3': ps[i] = phone[1]; n *= 3; break;
            case '4': ps[i] = phone[2]; n *= 3; break;
            case '5': ps[i] = phone[3]; n *= 3; break;
            case '6': ps[i] = phone[4]; n *= 3; break;
            case '7': ps[i] = phone[5]; n *= 4; break;
            case '8': ps[i] = phone[6]; n *= 3; break;
            case '9': ps[i] = phone[7]; n *= 4; break;
        }
        reset[i] = ps[i];
    }
    *returnSize = n;
    strings = (char **)calloc(n, sizeof(char *));
    for (i = 0; i < n; i++) {
        strings[i] = calloc(len+1, sizeof(char));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < len; j++) {
            strings[i][j] = **(ps+j);
        }
        for (j = len-1; j >= 0; j--) {
            ps[j]++;
            if (**(ps+j) == '\0') {
                ps[j] = reset[j];
            } else {
                break;
            }
        }
    }

    free(ps);
    free(reset);
    return strings;
}