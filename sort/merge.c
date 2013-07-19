#include <stdlib.h>
#include <limits.h>

void merge(int *array,int l,int med,int r)
{
    int n_f,n_s;
    
    n_f = med - l + 1;
    n_s = r - med;

    int *f_array,*s_array;
    f_array = calloc(n_f+1,sizeof(int));
    s_array = calloc(n_s+1,sizeof(int));


    memcpy(f_array,array,n_f);
    memcpy(s_array,array+med+1,n_s);
        
    int i;
    int j=0,k=0;
    for (i = l; i < r; i++) {
        if(f_array[j] <= s_array[k])
        {
            array[i] = f_array[j];
            j++;
        } else {
            array[i] = s_array[k];
            k++;
        }
    }
}

void merge_sort(int *array,int l,int r)
{
    if (r - l <= 1)
    {
        return;
    } else if (r > l) {
        merge_sort(array,l,r/2);
        merge_sort(array,(r/2)+1,r);
        merge(array,l,(r/2),r);
    }
}

int main(int argc, const char *argv[])
{
    int arr[5] = { 12 , 0 ,-3, 4 ,5};
    merge_sort(arr,0,4);
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
