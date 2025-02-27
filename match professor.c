#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 将字符串转换为小写（不修改原字符串）
void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// 在大字符串 `text` 中查找是否包含 `keyword`（忽略大小写）
int case_insensitive_search(const char* text, const char* keyword) {
    char lower_text[100], lower_keyword[50]; // 假设最长 100 和 50
    strncpy(lower_text, text, sizeof(lower_text) - 1);
    strncpy(lower_keyword, keyword, sizeof(lower_keyword) - 1);
    lower_text[sizeof(lower_text) - 1] = '\0';
    lower_keyword[sizeof(lower_keyword) - 1] = '\0';

    to_lowercase(lower_text);
    to_lowercase(lower_keyword);

    return strstr(lower_text, lower_keyword) != NULL; // strstr() 查找子串
}

int main() {
    char position1[] = "Professor";
    char position2[] = "Assistant professor";
    char position3[] = "Senior Lecturer";

    if (case_insensitive_search(position1, "professor")) {
        printf("%s 匹配\n", position1);
    }
    if (case_insensitive_search(position2, "professor")) {
        printf("%s 匹配\n", position2);
    }
    if (case_insensitive_search(position3, "professor")) {
        printf("%s 不匹配\n", position3);
    }

    return 0;
}
