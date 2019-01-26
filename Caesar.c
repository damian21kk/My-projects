#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_key(char** key);
char* secret_message();
char* encrypted_message(int key, char* message);

int main(int argc, char* arg[])
{
    bool validity=check_key(arg);
    if (validity==false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k= atoi(arg[1]);
    char* secret=secret_message();
    char* code=encrypted_message(k, secret);
    printf("ciphertext:    %s\n", code);
    exit(EXIT_SUCCESS);
}

bool check_key(char** key)
{
    if (key[1]==NULL)
    {
        return false;
    }
    int n=strlen(key[1]);
    char check;
    for(int i=0;i<n;++i)
    {
        check=key[1][i];
        if(check<48||check>57)
        {
            return false;
        }
    }
    if (key[2]!=NULL)
    {
        return false;
    }
    return true;
}
char* secret_message()
{
    static char message[2000];
    printf("ciphertext:    ");
    scanf("%[^\n]s", message);
    return message;
}

char* encrypted_message(int key, char* message)
{
    static char code[2000];
    int n= strlen(message);
    for (int i=0;i<n;++i)
    {
        if(message[i]<123&&message[i]>96)
        {
            code[i]=97+((message[i]-97+key)%26);
        }
        else if(message[i]<91&&message[i]>64)
        {
            code[i]=65+((message[i]-65+key)%26);
        }
        else
        {
            code[i]=message[i];
        }
    }
    return code;
}