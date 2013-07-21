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

int main(int argc, const char *argv[])
{
    int array[5] = { -2, 5 , 0 , 3 , 1};
    insert_sort(array,5);
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
