#include <cs50.h>
#include <stdio.h>

int number_rows();
void pyramid(int h);

int main(void)
{
    int h=number_rows();
    pyramid(h);
}

int number_rows()
{
    char c[200];
    int n=0;
    while (true)
    {
    printf("What is the height of the pyramid?\n");
    scanf("%s", c);
    n=atoi(c);
    if (n>0&&n<9)
    {
        return n;
    }
    }
    
}

void pyramid(int h)
{
    for(int i=0;i<h;++i)
    {
        for(int l=i+1;l<h;++l)
        {
             printf(" ");
        }
        for(int k=h-i;k<h+1;++k)
        {
             printf("#");
        }
        printf("  ");
          for(int n=h-i;n<h+1;++n)
        {
             printf("#");
        }
        printf("\n");
    }
}