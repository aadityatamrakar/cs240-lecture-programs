// https://www.tutorialspoint.com/c_standard_library/c_function_setvbuf.htm
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char buff[1024];

    // memset is used to fill a block of memory with a particular value.
    // void *memset(void *str, int c, size_t n)
    // str − This is a pointer to the block of memory to fill.
    // c − This is the value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
    // n − This is the number of bytes to be set to the value.
    memset(buff, '\0', sizeof(buff));

    fprintf(stdout, "Going to set full buffering on\n");
    // setvbuf is used to set the buffering mode of a stream.
    // int setvbuf(FILE *stream, char *buffer, int mode, size_t size)
    // stream − This is the pointer to a FILE object that identifies the stream.
    // buffer − This is the pointer to a user-provided buffer.
    // mode − This is the buffering mode to be used. It can be one of the following three macros defined in stdio.h −
    // _IOFBF Full buffering
    // _IOLBF Line buffering
    // _IONBF No buffering
    // size − This is the size of the buffer pointed to by the buffer argument.
    
    setvbuf(stdout, buff, _IONBF, 1024);

    fprintf(stdout, "This output will go into buff\n");

    // fflush is used to flush the output buffer of a stream.
    fflush(stdout);

    fprintf(stdout, "and this will appear when programm\n");
    fprintf(stdout, "will come after sleeping 3 seconds\n");

    // sleep is used to suspend execution of the calling thread for (at least) seconds seconds.
    sleep(5);
    
    return (0);
}