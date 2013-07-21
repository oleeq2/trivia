#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *array,int l,int med,int r)
{
    int n_f,n_s;
    int i;
    int j;
    n_f = med - l +1; 
    n_s = r - med;

    int *f_array = calloc(n_f+1,sizeof(int));
    int *s_array = calloc(n_s+1,sizeof(int));


    for(i = l,j=0; i <= med;j++,i++){
        f_array[j] = array[i];
    }

    for(i = med+1,j=0; i <= r; i++,j++){
        s_array[j] = array[i];
    }

    f_array[n_f] = INT_MAX;
    s_array[n_s] = INT_MAX;

    int f=0,s=0;
    for (i = l; i <= r; i++) {
        if (f_array[f] <= s_array[s]) {
           array[i] = f_array[f];
           f++;
        }else {
            array[i] = s_array[s];
            s++;
        }
        printf("%d ",array[i]);
    }
    putchar('\n');
}

void merge_sort(int *array,int l,int r)
{
    if(l < r)
    {
        int q = (l+r)/2;
        merge_sort(array,l,q);
        merge_sort(array,q+1,r);
        merge(array,l,q,r);
    }
}

