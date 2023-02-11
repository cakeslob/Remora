
#include "mbed.h"

#define WAIT_TIME_MS 500 

//DigitalOut HE1(PB_4);

int main()
{
    int i;

    printf("butt This is hello world running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

    while (true)
    {
        printf("Remora BUTT SPIDER_KING is alive %d\n\r", i);
        //HE1 = !HE1;
        i++;
        thread_sleep_for(WAIT_TIME_MS);
    }
}