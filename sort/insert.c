void insert_sort(int *array,int n)
{
    int i;
    for (i = 1; i < n; i++) {
       int key = array[i];
       int j = i - 1;
       while( j >= 0 && key < array[j]){
           array[j+1] = array[j];
           j--;
       }
       array[j+1] = key;
    }
}
