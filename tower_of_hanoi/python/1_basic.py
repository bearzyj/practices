#! /usr/local/bin/python

##############################################################
#iNum : The number of plates
#sA   : The name of the first plate
#sB   : The name of the second plate
#sC   : The name of the third plate
##############################################################

def core(iNum,sA,sB,sC):
    if iNum >= 1:
        core(iNum-1,sA,sC,sB) # Step1: move all but the last one from A to B
        print sA,"-->",sC     # Step2: move the last one from A to C
        core(iNum-1,sB,sA,sC) # Step3: move all left from B to C

core(5,"A","B","C")
