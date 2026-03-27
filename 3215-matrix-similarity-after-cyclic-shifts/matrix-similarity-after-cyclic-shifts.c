bool areSimilar(int** m, int n, int* mcs, int k) {
    int cols = mcs[0];
    k = k % cols;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < cols; j++){
            int newIndex;
            if(i % 2 == 0) {
                newIndex = (j + k) % cols;
            } else {
                newIndex = (j - k + cols) % cols;
            }
            if(m[i][j] != m[i][newIndex]) {
                return false;
            }
        }
    }
    return true;
}