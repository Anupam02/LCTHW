#include <stdio.h>

int A[10];
int main(int argc, char **argv) {
    int t,index;
    A[9] = 1;
    scanf("%d",&t);
    while( t-- ) {
        scanf("%d",&index);
        printf("%d\n",A[index]);
    }
    return 0;
}
