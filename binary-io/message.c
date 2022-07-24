#include <stdio.h>          // freopen, fread, 
#include <stdint.h>         // uint16_t



// "cast" 2 unsigned char into 1 unsigned 16bit integer
uint16_t CharToInt(char* representation)
{
    uint16_t integer = 0;
    integer += representation[0];
    integer << 8;
    integer += representation[1];
    
    return integer;
}


uint16_t ReadMessageLength(char* charLength)
{
    // read binary length from stdin
    fread(charLength, 1, 2, stdin);
    
    return CharToInt(charLength);
}


void ReadMessage(char* buffer, uint16_t length)
{
    // read binary input message from stdin
    fread(buffer, 1, length, stdin);
}



// Useful reading:
// General C IO info:
// https://stackoverflow.com/questions/35178520/how-to-read-parse-input-in-c-the-faq
// Specific functions used in a file:
// https://pubs.opengroup.org/onlinepubs/000095399/functions/freopen.html
// https://pubs.opengroup.org/onlinepubs/009695399/functions/fread.html
// https://pubs.opengroup.org/onlinepubs/009695399/functions/feof.html



int main()
{
    // state
    unsigned char charLength[2];
    uint16_t length;
    // currently unused but delimit messages with this
    unsigned char delimeter = '\n';
    
    // open binary stdin stream
    freopen(NULL, "rb", stdin);
    
    while (feof(stdin) == 0)
    {        
        // read length
        length = ReadMessageLength(charLength);

        // create buffer
        unsigned char buffer[length];

        // read message
        ReadMessage(buffer, length);
    }

    return 0;
}
