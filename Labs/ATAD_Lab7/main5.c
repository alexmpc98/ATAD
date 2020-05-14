#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef unsigned long long timestamp_t;

static timestamp_t get_timestamp();

int main(){
    //Calculate time taken by a code segment
    printf("Timer starts\n");

    timestamp_t t0 = get_timestamp();

    // CODE TO TESTE <---- HERE ---->

    printf("Timer ends\n");
    double secs = (t1-t0) / 1000000.0L;

    printf("The program took %f microseconds to execute",secs);
    return EXIT_SUCCESS;
}

static timestamp_t get_timestamp(){
    struct timeval now;
    gettimeofday(&now,NULL);
    return now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}