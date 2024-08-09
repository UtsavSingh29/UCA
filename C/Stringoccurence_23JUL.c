#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256
int lengthOfLongestSubstringTwoDistinct(char *s)
{
    int len = strlen(s);
    if (len <= 2)
    {
        return len;
    }
    int char_count[MAX_CHAR] = {0};
    int distinct_char_count = 0;
    int ptr1 = 0, ptr2 = 0, ans = 0;
    for (ptr2 = 0; ptr2 < len; ptr2++)
    {
        if (char_count[s[ptr2]] == 0)
        {
            distinct_char_count++;
        }
        char_count[s[ptr2]]++;
        while (distinct_char_count > 2)
        {
            char_count[s[ptr1]]--;
            if (char_count[s[ptr1]] == 0)
            {
                distinct_char_count--;
            }
            ptr1++;
        }
        ans = (ptr2 - ptr1 + 1) > ans ? (ptr2 - ptr1 + 1) : ans;
    }
    return ans;
}
int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    int result = lengthOfLongestSubstringTwoDistinct(s);
    printf("Length of longest substring with at most two distinct characters: %d\n", result);
    return 0;
}