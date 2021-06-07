//# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>

int lengthUntilNull(char * str){
    int i = 0;
    while(str[i] != 0){
	i++;
    }
    return i;
}

void print(char * str){
    write(1, str, lengthUntilNull(str));
}


int main(){
    char buff[13] = "HELLO WORLD\n";
    print(buff);
    
    // structures in use
    //struct timeval {
    //    time_t      tv_sec;     // seconds
    //    suseconds_t tv_usec;    // microseconds
    //};
    //
    //struct timezone {
    //    int tz_minuteswest;     /* minutes west of Greenwich */
    //    int tz_dsttime;         /* type of DST correction */
    //};
    struct timeval timenow;
    char timestr[64];
    gettimeofday(&timenow, NULL);
    //printf("seconds : %ld\nmicro seconds : %ld",
    //    timenow.tv_sec, timenow.tv_usec);

    // tried to use a systemcall, but only found a library.
    // could have written it myself, but leap year and leap second are kinda annoying
    // as well as the general days in a month.
    strftime(timestr,sizeof timestr,"%Y-%m-%d %H:%M:%S", localtime(&(timenow.tv_sec)));
    
    // long ass redundant piece of code, not using it
    //int datelen = lengthUntilNull(timestr);
    //timestr[datelen] = '\n';
    //timestr[datelen+1] = 0;

    print(timestr);
    print("\n"); 
    //printf("%d\n", lengthUntilNull("\n"));
    exit(0);
}
