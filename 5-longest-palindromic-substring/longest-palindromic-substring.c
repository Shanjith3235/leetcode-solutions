char* longestPalindrome(char* s) {
    int len = strlen(s);
    int start = 0, maxLen = 1;

    for (int i = 0; i < len; i++) {
        int l = i, r = i;
        while (l >= 0 && r < len && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
        l = i; r = i + 1;
        while (l >= 0 && r < len && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }

    char* ans = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(ans, s + start, maxLen);
    ans[maxLen] = '\0';
    return ans;
}