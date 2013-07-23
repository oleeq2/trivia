void counting_sort(int *array,int n,int *result_arr,int max_el)
{
    int temp_array[max_el+1]; 
    int i;
    for(i = 0; i <= max_el;i++){
        temp_array[i] = 0;
    }
    for(i = 0; i < n; i++){
        temp_array[array[i]]++;
    }
    for(i = 1; i <= max_el;i++){
        temp_array[i] = temp_array[i-1] + temp_array[i]; 
    }

    for(i = 0; i < n ; i++){
        result_arr[temp_array[i]--] = array[i];
    }
}

int main(int argc, const char *argv[])
{
    int arr[5] = { 1 ,2, 5, 2, 0};
    int res[5]; 
    counting_sort(arr,5,res,5);
    int i;
    for(i=0;i < 5;i++)
        printf("%d ",res[i]);
    return 0;
}
