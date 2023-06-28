/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeak(MountainArray &arr, int n){
        int start = 0;
        int end = n-1;

        while(start < end){
            int mid = start + (end - start) / 2;
            int midVal = arr.get(mid);
            if(midVal > arr.get(mid + 1) && midVal > arr.get(mid-1)){
                return mid;
            } 
            else if(midVal < arr.get(mid + 1)){
                start = mid;
            }
            else{
                end = mid;
            }
        }

        return -1;
    }

    int findInRightMountain(MountainArray &arr, int start, int end, int target){
        while(start <= end){

            int mid = start + (end-start)/2;

            int midVal = arr.get(mid);
            // cout << midVal;

            if(midVal == target){
                return mid;
            }
            else if(midVal < target){
                end = mid - 1;
            }
            else{
                start = mid+1;
            }

        }

        return -1;
    }

    int findInLeftMountain(MountainArray &arr, int start, int end, int target){

        while(start <= end){

            int mid = start + (end-start)/2;

            int midVal = arr.get(mid);
            // cout << midVal;

            if(midVal == target){
                return mid;
            }
            else if(midVal < target){
                start = mid + 1;
            }
            else{
                end = mid-1;
            }

        }

        return -1;
    
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        //finding the peak element index;
        int peak = findPeak(mountainArr, mountainArr.length());
        // return peak;

        int left = -1;
        int right = -1;
        
        int start = 0;
        int end = peak;

        left = findInLeftMountain(mountainArr, start, end, target);
        
        if(left == -1){
            // cout << "Entered right part";
            start = peak+1;
            end = mountainArr.length() - 1;
            right = findInRightMountain(mountainArr, start, end, target);

            return right;
        }

        return left;
    }
};