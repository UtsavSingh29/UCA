#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void exc(int arr[], int i, int j)   
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        exc(arr, i, min);
    }
}
void test_simple_output()
{
    int input[] = {5, 4, 3, 2, 1};
    int expected_output[] = {1, 2, 3, 4, 5};
    int n = 5;
    selection_sort(input, n);
    for (int i = 0; i < n; i++)assert(input[i] == expected_output[i]);
}
long long time_elapsed(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)arr[i] = rand() % 10000;
    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec * 1000LL + before.tv_usec / 1000;
    selection_sort(arr, n);
    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec * 1000LL + after.tv_usec / 1000;
    return after_millis - before_millis;
}
int main()
{
    test_simple_output();
    long long t1 = time_elapsed(200);
    long long t2 = time_elapsed(1000);
    if (t1 == 0)
        t1 = 1;
    if (t2 == 0)
        t2 = 1;
    printf("Time for n=200: %lld ms\n", t1);
    printf("Time for n=1000: %lld ms\n", t2);
    printf("Ratio: %lf\n", t2 * 1.0 / t1);
    return 0;
}
