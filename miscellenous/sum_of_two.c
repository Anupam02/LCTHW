#include <stdio.h>
#include <time.h>

int A[10001];
int hash[10001];
int third_approach_with_limited_range(int *arr, int size, int k) {
    int i, count = 0;
    for ( i = 0; i < 10001; i++ )
        hash[i] = -1;
    for ( i = 0; i < size ; i++ )
        hash[arr[i]] = i;
    printf("The hash function till size 20\n");
    for ( i = 0; i < 20; i++ )
        printf("%d ", hash[i]);
    printf("\n");
    for ( i = 0; i < size ; i++ )
        printf("hash[k - arr[i]] = %d\n", hash[k-arr[i]]);
        if ( hash[k - arr[i]] != i && hash[k - arr[i]] != -1)
            count++;
    return count;
}

void insertion_sort( int *arr, int size) {
    int i , j, key;
    for ( i = 1; i < size; i ++ ) {
        key = arr[i];
        j = i - 1;
        while ( arr[j] >= key && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

int binary_search(int * arr, int left, int right, int elem) {
    while ( left <= right ) {

        int mid = ( left + right ) / 2;
        if ( elem == arr[mid] )
            return mid;
        else if ( elem < arr[mid] ) {
            return binary_search(arr , left , mid-1, elem);
        }
        else {
            return binary_search(arr, mid+1, right, elem);
        }
    }
    return -1;
}

        

int bruteforce( int * arr , int  size, int k) {
    int count, i , j;
    count = 0;
    for ( i = 0; i < size ; i ++ ) {
        for ( j = i+1; j < size; j ++ ) {
            if ( arr[i] + arr[j] == k ) {
                count++;
            }
        }
    }
    return count;
}

int sort_with_binary_search( int * arr, int size, int k) {
    insertion_sort( arr, size);
    // int i ;
    // for ( i = 0; i < size; i ++ )
    //     printf("%d ",arr[i]);
    // printf("\n");
    int pivot,count = 0,index = 0;
    for ( pivot = 0; pivot < size; pivot ++) {
        // printf("for pivot = %d , arr[%d] = %d \n", pivot, pivot, arr[pivot]);
        // 
        index = binary_search(arr, 0, size, k-arr[pivot]);
        // printf("index = %d\n",index);
        if ( index != -1 ) {
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    int t, n, k, i, count;
    count = 0;
    scanf("%d",&t);
    while( t-- ) {
        scanf("%d%d",&n,&k);
        for ( i = 0; i < n; i ++ ) {
            scanf("%d",&A[i]);
        }

        // for bruteforece
        clock_t tic = clock();
        int count = bruteforce(A, n, k);
        printf("The count from bruteforce = %d\n", count);
        clock_t toc = clock();
        printf("Elapsed: %f seconds for bruteforce\n", (double)(toc - tic) / CLOCKS_PER_SEC);

        // for second approach with sorting and binary search
        clock_t tic_1 = clock();
        // count = sort_with_binary_search(A, n, k);
        clock_t toc_1 = clock();
        printf("The count from sort_with_binary_search = %d\n",count);
        printf("Elapsed: %f seconds for insertion_sort_binary_search\n", (double)(toc_1 - toc_1) / CLOCKS_PER_SEC);
       
        // for third approach with using hashing
        clock_t tic_2 = clock();
        count = third_approach_with_limited_range(A, n, k);
        clock_t toc_2 = clock();
        printf("The count from third_approach_with_limited_range = %d\n", count);
        printf("Elapsed: %f seconds for third_approach_with_limited_range\n", (double)(toc_2 - tic_2) / CLOCKS_PER_SEC);

    
    }
    return 0;
}


