#define LEFT(i) 2*i
#define RIGHT(i) 2*i+1
#define PARENT(i) i/2

void max_heapify(int *array,int i,int heap_size)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;

    if(l <= heap_size && array[l] > array[i])
        largest = l;
    else if (l <= heap_size && array[r] > array[i])
        largest = r;
    if(largest != i)
    {
        int tmp;
        tmp = array[largest];
        array[largest] = array[i];
        array[i] = tmp;
        max_heapify(array,largest,heap_size);
    }
}

void build_max_tree(int *array,int n)
{
    int i;
    for (i = n/2; i >= 0; i--) {
        max_heapify(array,i,n);
    }
}

void heapsort(int *array,int n)
{
    int i;
    int ns = n-1;
    build_max_tree(array,n);
    for(i = n-1; i >= 1;i--){
        int tmp = array[1];
        array[1] = array[i];
        array[i] = tmp;
        max_heapify(array,1,ns--);
    }
}
