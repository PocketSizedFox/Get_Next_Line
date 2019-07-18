#include "get_next_line.h"
#include <stdio.h>

int main(int argc,char **argv)
{
	char *str;
	int res;
	int fd = open(argv[1], O_RDONLY);
    
	str = (char *)malloc(50);
    while (get_next_line(fd, &str))
	printf("%s\n",str);
    //while (get_next_line(fd, &str))
        //printf("%s\n",str);
}



