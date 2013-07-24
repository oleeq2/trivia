int partition(int *array,int l,int r)
{
    int i = l-1;
    int x = array[r];
    int j;
    for(j = l;j < r;j++){
        if(x <= array[j]){
            ++i;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i+1];
    array[i+1] = array[r];
    array[r] = temp;
    return i+1;
}

void quicksort(int *array,int l,int r)
{
    if(l<r){
        int q = partition(array,l,r);
        quicksort(array,l,q-1);
        quicksort(array,q+1,r);
    }
}
