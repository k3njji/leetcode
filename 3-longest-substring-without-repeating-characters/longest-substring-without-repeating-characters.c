int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int max_len = 0;
    int used[128] = {0};        

    int left = 0;
    for (int right = 0; right < n; right++) {
        char c = s[right];

        while (used[c] == 1) {
            used[s[left]] = 0; 
            left++;
        }

        used[c] = 1;          
        int current_len = right - left + 1;

        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    return max_len;
}