//
//  reversionArray.cpp
//  reversionArrayDivideConquer
//
//  Created by Xie kesong on 5/1/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>



std::vector<int> sortAndCountReversion(std::vector<int> arr,int &sum){
    long size = arr.size();
    if(size == 1){
        return arr;
    }else if(size == 2){
        if(arr.at(0) > arr.at(1)){
            sum++;
            int temp = arr.at(0);
            arr.at(0) = arr.at(1);
            arr.at(1) = temp;
        }
        return arr;
    }
    
    std::vector<int> left, right;
    //get the left half of the array
    for(long i = 0; i < size/2; i++){
        left.push_back( arr.at(i) );
    }
    for(long i = size/2; i < size; i++){
        right.push_back( arr.at(i) );
    }


    //sort the left and right
    left = sortAndCountReversion(left, sum);
    right = sortAndCountReversion(right, sum);

    //merge left and right
    std::vector<int> result;
    long maxLeft = size/2 - 1;
    long maxRight;
    if(size % 2 == 0){
        maxRight = size/2 -1;
    }else{
        maxRight = size/2;
    }


    for(long i = 0, k = 0, j = 0; i < size; i++){
        if( k <= maxLeft && j <= maxRight){
            if(left.at(k) < right.at(j) ){
                result.push_back(left.at(k++));
            }else{
                //the number of reversion, in this case,  should be the remading elements of the left half of the array
                sum += maxLeft - k + 1;
                result.push_back(right.at(j++));
            }
        }else if(k > maxLeft){
            result.push_back(right.at(j++));
        }else if( j > maxRight){
            result.push_back(left.at(k++));
        }
    }
    return result;
}


int getReversionCount(std::vector<int>  arr){
    int sum = 0;
    sortAndCountReversion(arr, sum);
    return sum;
}




int main(int argc, const char * argv[]) {
    std::vector<int> array;
    srand(time(NULL));
    for(int i = 0; i < 4; i++){
        array.push_back(rand() % 10);
    }
    
    for(std::vector<int>::iterator itr = array.begin(); itr != array.end(); itr++){
        std::cout<<(*itr)<<" ";
    }
    
    std::cout<<"\n--------------------------";
    int reversionCount = getReversionCount(array);
    std::cout<<"number of reversion is "<<reversionCount<<std::endl;
    return 0;
}
