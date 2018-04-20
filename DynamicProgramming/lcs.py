#!/usr/bin/env python
# -*- coding: utf-8 -*-

# longest common subsequence problem
# author:wangtao
def comput_lcs(strA,strB):
    len_A = len(strA)
    len_B = len(strB)
    retstr = []
    #create a muti-array row = len_A+1 coloum = len_B+1 
    ret = [[0 for i in range(len_B+1)] for j in range(len_A+1)]
    for i in range(1,len_A+1):
        for j in range(1,len_B+1):
            if(i == 0 or j == 0):
                ret[i][j] = 0
            elif(strA[i-1] == strB[j-1]):
                ret[i][j] = ret[i-1][j-1]+1
                retstr.append(strA[i-1])
            elif(strA[i-1] != strB[j-1]):
                ret[i][j] = max(ret[i-1][j],ret[i][j-1])
    print retstr
    return ret
strA = "135689"
strB = "1247890"
retvalue = [[0 for i in range(len(strA)+1)] for j in range(len(strB)+1)]
retvalue = comput_lcs(strA,strB)

print retvalue
