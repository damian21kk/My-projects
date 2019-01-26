#include <cs50.h>
#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>
#include <string.h>

bool check_key(char** key);
char* broken_code(char* arg[]);

int main(int argc, char* arg[])
{
    bool validity=check_key(arg);
    if (validity==false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    char* encrypted_message=broken_code(arg);
    printf("%s\n", encrypted_message);
    return 1;
}

bool check_key(char** key)
{
    if (key[1]==NULL)
    {
        return false;
    }
    int n=strlen(key[1]);
    if(n!=13)
    {
        return false;
    }
    if (key[2]!=NULL)
    {
        return false;
    }
    return true;
}
char* broken_code(char* arg[])
{
    char salt[2];
    int s1=arg[1][0];
    int s2=arg[1][1];
    salt[0]=s1;
    salt[1]=s2;
    char pass[]="LOOL";
    static char key[5];
    for (int l5=65;l5<123;++l5)
    {
        if(l5>90&&l5<97)
        {
            continue;
        }
        for (int l4=65;l4<123;++l4)
        {
            if(l4>90&&l4<97)
            {
                continue;
            }
            for (int l3=65;l3<123;++l3)
            {
                if(l3>90&&l3<97)
                {
                    continue;
                }    
                for (int l2=65;l2<123;++l2)
                {
                    if(l2>90&&l2<97)
                    {
                        continue;
                    }
                    for (int l1=65;l1<123;++l1)
                    {
                        if(l1>90&&l1<97)
                        {
                            continue;
                        }
                        key[0]=l1;
                        if (strcmp(crypt(key, salt),arg[1])==0)
                        {
                           return key;
                        }
                    }
                    key[1]=l2;
                    if (strcmp(crypt(key, salt),arg[1])==0)
                    {
                        return key;
                    }
                }
                key[2]=l3;
                if (strcmp(crypt(key, salt),arg[1])==0)
                {
                   return key;
                }
            }
            key[3]=l4;
            if (strcmp(crypt(key, salt),arg[1])==0)
            {
               return key;
            }
        }
        key[4]=l5;
        if (strcmp(crypt(key, salt),arg[1])==0)
        {
           return key;
        }
    }
    return 0;
}