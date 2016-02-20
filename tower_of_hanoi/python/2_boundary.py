#! /usr/local/bin/python

##############################################################
#iNum : The number of plates
#sA   : The name of the first plate
#sB   : The name of the second plate
#sC   : The name of the third plate
#bFlag: Possibility as start or end, establish boundary needed
##############################################################

def core(iNum,sA,sB,sC,bFlag):
    if iNum>1:
        if bFlag:
            print "*** Start for layer",iNum,"***"
        core(iNum-1,sA,sC,sB,False) # Step1: move all but the last one from A to B
        core(1,sA,sB,sC,bFlag)      # Step2: move the last one from A to C
        if bFlag and iNum==2:       # This is the only special printting
            print "*** Start for layer 1 ***"
        core(iNum-1,sB,sA,sC,bFlag) # Step3: move all left from B to C
    else:
        print sA,"-->",sC     
        if bFlag:
            print "### End of this layer ###"

core(5,"A","B","C",True)
