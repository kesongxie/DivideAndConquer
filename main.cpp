//
//  main.cpp
//  MergeSort
//
//  Created by Xie kesong on 4/29/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//

#include <iostream>
#include <vector>

#include <stdlib.h>     /* srand, rand */
#include <time.h>


std::vector<int> MergeSortRecurssive(std::vector<int> array){
    long length = array.size();
    if(length == 1){
        return array;
    }else if (length == 2){
        if(array.at(0) > array.at(1)){
            int temp = array.at(0);
            array.at(0) = array.at(1);
            array.at(1) = temp;
            return array;
        }
    }
    
    
    std::vector<int> result;
    //get the left half
    std::vector<int> left, right;
    for(long i=0; i < length/2; i++){
        left.push_back(array.at(i));
    }
    for(long i=length/2; i < length; i++){
       right.push_back(array.at(i));
    }
    
    
    left = MergeSortRecurssive(left); //sorted left
    right= MergeSortRecurssive(right); //sorted right
    
    //merge left and right
    long maxLeft = length/2-1;
    long maxRight;
    if(length%2==0){
        maxRight = length/2-1;
    }else{
        maxRight = length/2;
    }
    for (long i =0,k=0,j=0; i < length; i++){
        if( k <= maxLeft && j <= maxRight){
            if(left.at(k) < right.at(j)){
                result.push_back(left.at(k));
                k++;
            }else{
                result.push_back(right.at(j));
                j++;
            }
        }else if (k > maxLeft){
            result.push_back(right.at(j));
            j++;
        }else if(j > maxRight){
            result.push_back(left.at(k));
            k++;
        }
    }
    return result;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    srand (time(NULL));
    std::vector<int> unsorted,sorted;
    
    for (int i=0; i<1210424; i++)
    {
        unsorted.push_back(rand()%1210424+1);
    }
    
    
    for (std::vector<int>::iterator it = unsorted.begin(); it != unsorted.end(); ++it)
    {
        std::cout <<*it<<std::endl;
    }

    std::cout<<"----------------"<<std::endl;

    
    sorted = MergeSortRecurssive(unsorted);
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
    {
        std::cout <<*it<<std::endl;
    }
    return 0;
}
