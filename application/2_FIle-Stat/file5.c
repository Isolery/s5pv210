#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <dirent.h>

int main(void)
{
    DIR *pdir = NULL;
    struct dirent *pent = NULL;

    pdir = opendir("2_File-Stat");
    if(pdir == NULL)
    {
        perror("opendir");
        return -1;
    }

    while(1)
    {
        pent = readdir(pdir);
        if(pent != NULL)
        {
            printf("name: %s  ", pent->d_name);
            if(pent->d_type == DT_REG)
            {
                printf("is normal file...\n");
            }
            else
            {
                printf("is not normal file...\n");
            }
        }
        else
        {
            break;
        }
    }
    
    return 0;
}
