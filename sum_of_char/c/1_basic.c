#include <stdio.h>

void histogram(int i_A2Z, int i_Number, int i_Invisible, int i_Others);
void horizontical(int i_A2Z, int i_Number, int i_Invisible, int i_Others);
void vertical(int i_A2Z, int i_Number, int i_Invisible, int i_Others);

/*************************************************************
*iNum   : The number of plates
*cStart : The name of the starting plate
*cEnd   : The name of the ending plate
*bFlag  : Possibility as start or end, establish boundary needed
*************************************************************/

int main()
{
    int c_Input=0;
    int i_A2Z=0;
    int i_Number=0;
    int i_Invisible=0;
    int i_Others=0;

    while((c_Input=getchar())!=EOF)
    {
        if ((c_Input>='a' && c_Input<='z') || (c_Input>='A' && c_Input<='Z'))
        {
            i_A2Z++;
        }
        else if ((c_Input>='0' && c_Input<='9'))
        {
            i_Number++;
        }
        else if(c_Input==' ' || c_Input=='\n' ||c_Input=='\t')
        {
            i_Invisible++;
        }
        else
        {
            i_Others++;
        }
    }

    histogram(i_A2Z, i_Number, i_Invisible, i_Others);
}

void histogram(int i_A2Z, int i_Number, int i_Invisible, int i_Others)
{
    printf("\n\n\n[Histogram]\n");
    printf("I  %2d: a~z or A~Z\n",i_A2Z);
    printf("II %2d: 0~9\n",i_Number);
    printf("III%2d: Invisible characters\n",i_Invisible);
    printf("IV %2d: Other letters\n",i_Others);
    printf("\n\n\n");

    horizontical(i_A2Z, i_Number, i_Invisible, i_Others);
}

void horizontical(int i_A2Z, int i_Number, int i_Invisible, int i_Others)
{
    int i_Loop;


    printf("Horizon\n");

    printf("|\n");
    printf("|");
    for (i_Loop=i_A2Z;i_Loop>0;i_Loop--)
    {
        putchar('-');
    }
    printf("I\n");

    printf("|\n");
    printf("|");
    for (i_Loop=i_Number;i_Loop>0;i_Loop--)
    {
        putchar('-');
    }
    printf("II\n");

    printf("|\n");
    printf("|");
    for (i_Loop=i_Invisible;i_Loop>0;i_Loop--)
    {
        putchar('-');
    }
    printf("III\n");

    printf("|\n");
    printf("|");
    for (i_Loop=i_Others;i_Loop>0;i_Loop--)
    {
        putchar('-');
    }
    printf("IV\n");

    printf("|\n");
    printf("-----------------------------------------\n");
}

void vertical(int i_A2Z, int i_Number, int i_Invisible, int i_Others)
{

}
