#include <stdio.h>
#include <string.h>


#define MAX(x,y) (x>y?x:y)

void histogram(int iA2Z, int iNumber, int iInvisible, int iOthers);
void horizontical(int iA2Z, int iNumber, int iInvisible, int iOthers);
void vertical(int iA2Z, int iNumber, int iInvisible, int iOthers);

int main()
{
    int c_Input=0;
    int iA2Z=0;
    int iNumber=0;
    int iInvisible=0;
    int iOthers=0;

    while((c_Input=getchar())!=EOF)
    {
        if ((c_Input>='a' && c_Input<='z') || (c_Input>='A' && c_Input<='Z'))
        {
            iA2Z++;
        }
        else if ((c_Input>='0' && c_Input<='9'))
        {
            iNumber++;
        }
        else if(c_Input==' ' || c_Input=='\n' ||c_Input=='\t')
        {
            iInvisible++;
        }
        else
        {
            iOthers++;
        }
    }

    histogram(iA2Z, iNumber, iInvisible, iOthers);
}

/*************************************************************
*iA2Z       : Sum of a~z and A~Z
*iNumber    : Sum of 0~9
*iInvisible : Sum of space, table, new-line
*iOthers    : Sum of other characters
*************************************************************/
void histogram(int iA2Z, int iNumber, int iInvisible, int iOthers)
{
    printf("\n\n\n[Histogram]\n");
    printf("I  %2d: a~z or A~Z\n",iA2Z);
    printf("II %2d: 0~9\n",iNumber);
    printf("III%2d: Invisible characters\n",iInvisible);
    printf("IV %2d: Other letters\n",iOthers);
    printf("\n\n\n");

    horizontical(iA2Z, iNumber, iInvisible, iOthers);
    vertical(iA2Z, iNumber, iInvisible, iOthers);
}

/*************************************************************
*iA2Z       : Sum of a~z and A~Z
*iNumber    : Sum of 0~9
*iInvisible : Sum of space, table, new-line
*iOthers    : Sum of other characters
*************************************************************/
void horizontical(int iA2Z, int iNumber, int iInvisible, int iOthers)
{
    int iLoop=0;
    int iMax=MAX(MAX(MAX(iA2Z,iNumber),iInvisible),iOthers)+10;


    printf("Horizon\n");

    printf("|\n");
    printf("|");
    for (iLoop=iA2Z;iLoop>0;iLoop--)
    {
        putchar('-');
    }
    printf("I\n");

    printf("|\n");
    printf("|");
    for (iLoop=iNumber;iLoop>0;iLoop--)
    {
        putchar('-');
    }
    printf("II\n");

    printf("|\n");
    printf("|");
    for (iLoop=iInvisible;iLoop>0;iLoop--)
    {
        putchar('-');
    }
    printf("III\n");

    printf("|\n");
    printf("|");
    for (iLoop=iOthers;iLoop>0;iLoop--)
    {
        putchar('-');
    }
    printf("IV\n");

    printf("|\n");
    for (iLoop=iMax;iLoop>0;iLoop--)
    {
        putchar('-');
    }
    printf("\n\n\n");
}

/*************************************************************
*iA2Z       : Sum of a~z and A~Z
*iNumber    : Sum of 0~9
*iInvisible : Sum of space, table, new-line
*iOthers    : Sum of other characters
*************************************************************/
void vertical(int iA2Z, int iNumber, int iInvisible, int iOthers)
{
    int iLoop=0;
    int iMax=MAX(MAX(MAX(iA2Z,iNumber),iInvisible),iOthers);
    int iNumber_offset=0;
    int iInvisible_offset=0;
    char a[5]={0};

    printf("Horizon\n");
    for (iLoop=1;iLoop>0;iLoop--)
    {
        printf("|\n");
    }

    for (iLoop=iMax+1; iLoop>0; iLoop--)
    {
        printf("|");

        /* a~z and A~Z part*/
        if (iLoop>iA2Z+1)
        {
            printf("    ");
        }
        else if (iLoop==iA2Z+1)
        {
            printf("   I");
        }
        else
        {
            printf("   |");
        }

        if (iLoop>iNumber+1)
        {
            printf("    ");
        }
        else if (iLoop==iNumber+1)
        {
            printf("   II");
            iNumber_offset=1;
        }
        else
        {
            printf("   |");
        }

        strcpy(a,"   ");
        if (iNumber_offset != 0)
        {
            a[2]='\0';
            iNumber_offset=0;
        }

        if (iLoop>iInvisible+1)
        {
            printf("%s ",a);
        }
        else if (iLoop==iInvisible+1)
        {
            printf("%sIII",a);
            iNumber_offset=2;
        }
        else
        {
            printf("%s|",a);
        }

        strcpy(a,"   ");
        if (iNumber_offset != 0)
        {
            a[1]='\0';
            iNumber_offset=0;
        }

        if (iLoop>iOthers+1)
        {
            printf("%s \n",a);
        }
        else if (iLoop==iOthers+1)
        {
            printf("%sIV\n",a);
        }
        else
        {
            printf("%s|\n",a);
        }
    }

    printf("-------------------\n\n\n");
}
