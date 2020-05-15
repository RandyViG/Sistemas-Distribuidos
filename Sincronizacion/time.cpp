#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

int main( void ) {
  struct timeval start;
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [14];

  while(1){
    gettimeofday(&start, NULL);
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,22,"Hora: %H:%M:%S",timeinfo);
    printf("%s.%ld\n",buffer,start.tv_usec );
  }

  return 0;
}
