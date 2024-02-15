#include <stdio.h>
#include <string.h>
int main()
{
    char s[20];
    char p[20];
    scanf("%s",&s);
    scanf("%s",&p);
    int lenght_s ;
    int lenght_p;
    lenght_s=strlen(s);
    lenght_p=strlen(p);
    int position_p = 0,position_s = 0;
    int position_star = lenght_p;
    for(int i=0; i<lenght_p; i++)
    {
        if(p[i]=='*') position_star=i;
    }
    int checker=1;
    position_p = lenght_p-1;
    position_s = lenght_s - 1;
    int found = 0;
    if(position_star!=lenght_p)
    {
        for( ;position_p>position_star && checker==1; )
        {
            if(p[position_p]==s[position_s] || p[position_p]=='.')
            {
                position_p--;
                position_s--;
                found++;
            }
            else
            {
                checker=0;

            }

        }
    }
    int s_found_pos=(position_star==lenght_p)? lenght_s : lenght_s - found;
    if(checker)
    {
        position_p=0;
        position_s=0;
        int checker2=1;
        while(position_p<=position_star && position_s <s_found_pos && checker2)
        {
            if(s[position_s]==p[position_p] || p[position_p]=='.')
            {
                position_s++;
                position_p++;

            }
            else if(p[position_p]=='*' && (p[position_p-1] == '.' || p[position_p-1] == s[position_s]))
            {

                position_s++;


            }
            else
            {
                checker2=0;

            }

        }
        if(position_star==lenght_p)
        {
            if(lenght_s!=lenght_p) checker2=0;
        }
        else
        {
            if(!(position_s==s_found_pos && position_p>= (position_star-2))) checker2=0;
        }
        if(checker2) printf("true\n");
        else printf("false\n");

    }
    else
    {
        printf("false\n");
    }

}