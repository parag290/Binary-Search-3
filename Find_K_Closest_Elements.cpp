



/**
 * Approach 1 : This will fail for most of corner cases
 * 
 * 
*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>diffArray;
        vector<int>result;
        int minDiff = INT_MAX;
        int index;

        for(int i=0; i<arr.size(); i++){
            int diff = std::abs(x - arr[i]);
            diffArray.push_back(diff);
            if (diff < minDiff){
                minDiff = diff;
                index = i;
            }
        }

        if(index-k <=0){
            for(int i=0; i<k; i++){
                result.push_back(arr[i]);
            }
        } else if (index+k-1 >= arr.size()-1){
            for(int i=arr.size()-k; i<arr.size(); i++){
                result.push_back(arr[i]);
            }
        } else {
            int low = index;
            int high = index;
            while(high - low + 1 != k){
                if(diffArray[low] <= diffArray[high]){
                    low--;
                } else {
                    high++;
                }
            }

            for(int i=low; i<= high; i++){
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};


/**
 * Approach 2 : Optimised solution (Space optimized as well)
 * This covers all corner cases.
 * 
 * 
*/



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>result;
        int low = 0;
        int high = arr.size() - 1;

        while(high - low + 1 > k){
            if(std::abs(arr[high] - x) < std::abs(arr[low] - x)) low++;
            else high--;
        }

        for(int i=low; i<low+k; i++){
            result.push_back(arr[i]);
        }

        return result;
    }
};