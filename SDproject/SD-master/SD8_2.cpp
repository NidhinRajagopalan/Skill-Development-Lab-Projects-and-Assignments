#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX_LEN 50
using namespace std;
void selectionSort(char arr[][MAX_LEN], int n) 
{ 
    int i, j, min_idx; 
   
    // One by one move boundary of unsorted subarray 
    char minStr[MAX_LEN]; 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        int min_idx = i; 
        strcpy(minStr, arr[i]); 
        for (j = i+1; j < n; j++) 
        { 
            // If min is greater than arr[j] 
            if (strcmp(minStr, arr[j]) < 0) 
            { 
                // Make arr[j] as minStr and update min_idx 
                strcpy(minStr, arr[j]); 
                min_idx = j; 
            } 
        } 
   
        // Swap the found minimum element with the first element 
        if (min_idx != i) 
        { 
            char temp[MAX_LEN]; 
            strcpy(temp, arr[i]); //swap item[pos] and item[i] 
            strcpy(arr[i], arr[min_idx]); 
            strcpy(arr[min_idx], temp); 
        } 
    } 
} 
   
// Driver code 
int main() 
{     
    int n,i;
    cout<<"\n Enter the number of people";
    cin>>n;
    char arr[n][MAX_LEN] ; 
    cout<<"\n Enter the Names";
    for(int j=0;j<n;j++)
        {cin>>arr[j];}
    cout<<"Given array is\n"; 
    for (i = 0; i < n; i++) 
      printf("%d: %s \n", i, arr[i]); 
    selectionSort(arr, n);    
    printf("\nSorted array is\n"); 
    for (i = 0; i < n; i++) 
        printf("%d: %s \n", i, arr[i]);    
    return 0; 
}

