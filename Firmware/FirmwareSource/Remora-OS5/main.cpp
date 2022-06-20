#include "mbed.h"
#include "platform/mbed_thread.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS  500

// Initialise the digital pins as outputs

DigitalOut HE1(PB_4);

int main()
{
    int i = 0;

    printf("SKRV2 is alive\n\r");
    

    while (true) {
        HE1 = !HE1;
        printf("i = %d\n\r",i);
        thread_sleep_for(BLINKING_RATE_MS);
        i++;
    }
}