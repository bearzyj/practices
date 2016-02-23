#include "stdio.h"

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define ABC 198        /* 198='A'+'B'+'C' */


/*************************************************************
*iNum   : The number of plates
*cStart : The name of the starting plate
*cEnd   : The name of the ending plate
*bFlag  : Possibility as start or end, establish boundary needed
*************************************************************/

void core(int iNum, char cStart, char cEnd, BOOL bFlag)
{


    if (iNum >= 1)
    {
        if (bFlag)
        {
            printf("*** Start for layer %d ***\n",iNum);
        }
        core(iNum-1, cStart, ABC-cStart-cEnd,FALSE); /* Step1: move all but the last one from A to B */
        printf("%c --> %c\n",cStart,cEnd);           /* Step2: move the last one from A to C */
        if (bFlag)
        {
            printf("### End of this layer ###\n");
        }
        core(iNum-1, ABC-cStart-cEnd, cEnd,bFlag);   /* Step3: move all left from B to C */
    }
}

int main()
{
    core(5,'A','C',TRUE);
}
