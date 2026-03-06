char* intToRoman(int num) {
    static char out[32];
    out[0] = '\0';   // empty string

    char *roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int value[]    = {1000,900,500,400,100, 90, 50, 40, 10,  9,  5,  4,  1};

    for (int i = 0; i < 13; i++) {
        while (num >= value[i]) {
            strcat(out, roman[i]); 
            num -= value[i];
        }
    }

    return out;
}