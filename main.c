#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if(argc < 2)
    {
        printf("Error: less than 1 args\n");
        return 0;
    }
    system("rm /etc/ntp.conf");
    FILE *fd = fopen("/etc/ntp.conf", "w");

    if (strcmp(argv[1], "server") == 0)
    {
        fprintf(fd, "%s %s\n", "server", argv[2]);
    }
    else if (strcmp(argv[1], "client") == 0)
    {
        fprintf(fd, "%s %s\n", "restrict", argv[2]);
    }


    else if (strcmp(argv[1], "backup") == 0)
    {

        system("cp /etc/ntp.conf /etc/ntp.conf.backup");
    }


    else
    {
       fprintf(fd, "%s %s\n", "server", "127.127.1.1");
    }






    fclose(fd);

    system("systemctl restart ntp");
    return 0;
}
