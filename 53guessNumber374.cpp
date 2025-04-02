/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

    long long guessNumber(long long n) {
        long long left=1;
        long long right=n;
        while(left<=right)
        {
            long long mid=(left+right)/2;
            int res=guess(mid);
            if(res==0)
            {
                return mid;
            }
            else if(res==-1)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return -1;
    }
};
