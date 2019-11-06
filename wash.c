#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdlib.h>



int GetTime(char a[][100], char word[100])
{printf("%s", word);
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if(a[i][j] == ' ')
                return i;
            if(a[i][j] != word[j])
                break;
            else
                j++;
        }
    }
}





int main()
{
    int f1, f2;
    char *send_buf = "Hello";
    char recv_buf[128] = {0};
    int stat = 0;
    int id = getpid();
    scanf("%d", &stat);
    if (mkfifo("mk.fifo", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1 && errno != EEXIST)
        error(0, errno, "mkfifo() error");

    f1 = open("mk.fifo", O_RDWR);
    int f, fz = 0;
    if (f1 == -1 )
        printf("Open error 1");
    FILE* fp1 = fopen("file1.txt", "r");
    FILE* fp2 = fopen("file2.txt", "r");
    FILE* fp = fopen("file.txt", "r");
    char str1[100][100], str2[100][100], str[100][100];
    int Num = 0;
    int Time = 0;
    int TABLE_LIMIT = 10;
    int N = 0;

    for(int i = 0; i < 100; i++)
    {
        int j = 0;
        while(1)
        { printf("ka");
            fscanf(fp1, "%c", &str1[i][j]);
            if(str1[i][j] == EOF)
                break;
            if(str1[i][j] == '\n' || str1[i][j] == '\0')
            {
                i++;
                break;
            }
            else
                j++;
        }
        if(str1[i][j] == EOF)
            break;

    }


    for(int i = 0; i < 100; i++)
    {
        int j = 0;
        while(1)
        {
            fscanf(fp2, "%c", &str1[i][j]);
            if(str2[i][j] == EOF)
                break;
            if(str2[i][j] == '\n' || str2[i][j] == '\0')
            {
                i++;
                break;
            }
            else
                j++;
        }
        if(str2[i][j] == EOF)
            break;

    }

    int time[100] = {};

    for(int i = 0; i < 100; i++)
    {

        int j = 0;
        while(1)
        {

            fscanf(fp, "%c", &str[i][j]);
            if(str[i][j] == ' ')
                time[i] = atoi(str[i] + j);
            if(str[i][j] == EOF)
            {
                Num = i;
                break;
            }

            if(str[i][j] == '\n' || str[i][j] == '\0')
                i++;
            else
                j++;

        }

        if(str[i][j] == EOF)
        {
            Num = i;
            break;
        }
    }



    while(1)
    {
        fork();
        if(getpid() == id)
        {
            for(int i = 0; i < Num; i++)
            {
                char string[100];
                int numoft;
                for(int j = 0; j < 100; j++)
                {
                    if(str1[i][j] == ' ')
                    {
                        numoft = atoi(str1[i] + j + 1);
                        break;
                    }
                    else
                    {
                        str1[i][j] = string[j];
                    }
                }
                int t = GetTime(str, string);
                for(int i = 0; i < numoft; i++)
                {
                    Time += t;
                    while(N >= TABLE_LIMIT)
                    {}
                    N++;
                }


            }
        }
        else
        {
            for(int i = 0; i < Num; i++)
            {
                char string[100];
                int numoft;
                for(int j = 0; j < 100; j++)
                {
                    if(str2[i][j] == ' ')
                    {
                        numoft = atoi(str2[i] + j + 1);
                        break;
                    }
                    else
                    {
                        str2[i][j] = string[j];
                    }
                }
                int t = GetTime(str, string);
                for(int i = 0; i < numoft; i++)
                {
                    Time += t;
                    while(N <= 0)
                    {}
                    N--;
                }


            }


        }
        break;
    }


}
