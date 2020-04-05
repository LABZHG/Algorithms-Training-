# -*- coding: utf-8 -*-
"""
Created on Sun Apr  5 19:27:13 2020

@author: user
"""
import math

class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x + y < z:
            return False
        if(x == 0 or y == 0):
            return(z == 0 or x + y == z)
        if(z % math.gcd(x,y)):
            return False
        else:
            return True

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            x = int(line);
            line = next(lines)
            y = int(line);
            line = next(lines)
            z = int(line);
            
            ret = Solution().canMeasureWater(x, y, z)

            out = (ret);
            print(out)

        except StopIteration:
            break

if __name__ == '__main__':
    main()