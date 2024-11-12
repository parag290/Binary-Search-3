
/*
Leetcode : https://leetcode.com/problems/powx-n/

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


*/



/*
Approach 1 : Using while loop rerecursive
This is not an optimised solution. 

Time complexity is O(n) which faces time limit issue.
*/

class Solution {
public:
    double myPow(double x, int n) {

        double result = 1;
        int new_n = std::abs(n);
        while(new_n != 0){
            result *= x;
            new_n--;
        }
        if(n <0) return 1/result;
        return result;
    }
};


/*
Approach 2 : Optimized solution : 
Time complexity is log(n) due to use of binary way of multiplication.
Watch viodeo to understand more - https://www.youtube.com/watch?v=vzsY7cb8mhw

*/


class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double result = myPow(x, n/2);

        if(n%2 == 0){
            return result * result;
        } else {
            if(n < 0){
                return result * result * 1/x;
            } else {    
                return result * result * x;
            }
        }
    }
};