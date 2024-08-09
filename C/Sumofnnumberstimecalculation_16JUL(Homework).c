#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<sys/resource.h>
int main(){ 
    clock_t starttime,endtime;
    double timeused;
    struct rusage usagestart;
    getrusage(RUSAGE_SELF,&usagestart);
    starttime=clock();
    int number;
    scanf("%d",&number);
    int sum = (number*(number + 1) / 2);
    for(int i=1;i<=number;i++)
        {
            sum+=i;
        }
    endtime=clock();
    struct rusage usageend;
    getrusage(RUSAGE_SELF,&usageend);
    timeused=((double)endtime-starttime)/CLOCKS_PER_SEC;
    long memoryused=usageend.ru_maxrss-usagestart.ru_maxrss;
    printf("%f\n",timeused);
    printf("Memory used:%ld KB\n",memoryused);
}