#include<stdio.h>
#include<stdlib.h>



char* Split(char* string, char*** strings, char* tokens, int* tokensCount);

int main()
{
    char str[100];
    int val = 2;
    char* strings[100];
    for(int i = 0; i < 100; i++)
    {
        strings[i] = malloc(sizeof(char)*100);
    }
    char* string = malloc(sizeof(char)*1000);
    char* tokens = malloc(sizeof(char)*10);
    int number_of_tokens = 0;


    //scanf("%d", &number_of_tokens);

    char tok;
    for(int i = 0; i < 3; i++)
    {

        tok = getchar ();
        tokens[i] = tok;
    }
    printf("%c ", tokens[0]);
    printf("%c ", tokens[1]);
    printf("ss");
    fgets(string, 120, stdin);
    printf("%s", string);


    Split(string, &strings, tokens, &val);
    for(int i = 0; i < 10; i++)
    {
        printf("%s ", strings[i]);
    }




  return 0;
}


char* Split(char* string, char*** strings, char* tokens, int* tokensCount)
{
    int i = 0;
    int bpos = 0;
    int l = 0;
    while(string[i] != '\0' && string[i] != '\n')
    {
        for(int j = 0; j < tokensCount; j++)
        {
            if(string[i] == tokens[j])
            {
                for(int k = 0; k < i-bpos; k++)
                {
                    strings[l][k] = string[bpos + k];
                }
                l++;
                bpos = i;
                break;
            }
        }
        i++;
    }
}
