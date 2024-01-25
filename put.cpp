#include "head/netcom.h"

#include <cstdio>
#include <iostream>

char ip[1005];
char file[1005];
char temp[100055];

int main()
{
    scanf("%s", ip);
    for (;;)
    {
        scanf("%s", file);
        FILE *fin = fopen(file, "rb");
        char c = '\0';
        int cnt = 0;
        temp[0] = '#';
        temp[1] = '\0';
        char file_name[1005];
        file_name[0] = '\0';
        for (int i = 0; i < strlen(file); i++)
        {
            sprintf(file_name, "%s%c", file_name, file[i]);
            if (file[i] == '\\')
            {
                file_name[0] = '\0';
            }
        }
        char temp_name[1005];
        temp_name[0] = '\0';
        sprintf(temp_name, "&%s", file_name);
        net::Send(ip, 8888, temp_name);
        printf("Start put %s\n", temp + 1);
        for (; (c = fgetc(fin)) != EOF;)
        {
            cnt++;
            temp[cnt] = c;
            temp[cnt + 1] = '\0';
            if (cnt == 100000)
            {
                net::Send(ip, 8888, temp);
                temp[0] = '#';
                cnt = 0;
            }
        }
        net::Send(ip, 8888, temp);
        net::Send(ip, 8888, "% ");
        fclose(fin);
        printf("Successful put %s\n", temp + 1);
    }
    return 0;
}