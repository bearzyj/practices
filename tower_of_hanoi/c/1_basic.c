#include "stdio.h"

#define ABC 198        /* 198='A'+'B'+'C' */

void core(int iNum, char cStart, char cEnd)
{
    if (iNum >= 1)
    {
        core(iNum-1, cStart, ABC-cStart-cEnd); /* Step1: move all but the last one from A to B */
        printf("%c --> %c\n",cStart,cEnd);     /* Step2: move the last one from A to C */
        core(iNum-1, ABC-cStart-cEnd, cEnd);   /* Step3: move all left from B to C */
    }
}

int main()
{
    core(5,'A','C');
}

