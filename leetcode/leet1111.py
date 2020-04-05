# -*- coding: utf-8 -*-
"""
Created on Sun Apr  5 18:50:04 2020

@author: user
"""
import json
import io
import sys

class Solution:
    def maxDepthAfterSplit(self, seq: str):
        arr=[0 for i in range(len(seq))]
        for j in range(len(seq)-1):
            if(seq[j]==seq[j+1]):
                arr[j+1]=1-arr[j]
            else:
                arr[j+1]=arr[j]

        return arr

def stringToString(input):
    return input[1:-1].decode('string_escape')

def integerListToString(nums, len_of_list=None):
    if not len_of_list:
        len_of_list = len(nums)
    return json.dumps(nums[:len_of_list])

def main():
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            seq = stringToString(line)
            
            ret = Solution().maxDepthAfterSplit(seq)

            out = integerListToString(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()