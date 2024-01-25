#include "head/netcom.h"
#include <cstring>

char temp[1000055];

int main()
{
    for (;;)
    {
        temp[0] = '\0';
        for (; temp[0] != '&';)
        {
            strcpy(temp, net::Listen(8888));
        }
        printf("Start get %s\n", temp + 1);
        FILE *fout = fopen(temp + 1, "wb");
        strcpy(temp, net::Listen(8888));
        for (; temp[0] == '#';)
        {
            fprintf(fout, "%s", temp + 1);
            fflush(fout);
            strcpy(temp, net::Listen(8888));
        }
        fclose(fout);
        printf("Successful get %s\n", temp + 1);
    }
}