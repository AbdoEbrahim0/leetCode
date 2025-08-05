void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //1 000 000 000  
    //2 147 483 647
    //nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    //[1,2,2,3,5,6]
    //int temp = nums1[0];;
    int* arr = (int*)malloc((m+n) * sizeof(int)); //  Valid in C
    int arrIndex = 0;
    int a, b;
    int push;
    int i = 0, j = 0;
    for ( i = 0; i < m && j < n; )
    {
        for (j = 0; j < n && i < m;)
        {
            //nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
            //[1,2,2,3,5,6]
            a = nums1[i], b = nums2[j];
            if (nums1[i] < nums2[j])
            {
                push = nums1[i];
                arr[arrIndex] = nums1[i];
                
                i++;
                
                //temp = nums1[i];
            }
            else
            {
                push = nums2[j];
                arr[arrIndex] = nums2[j];
                
                j++;
            }
            arrIndex++;
        }
    
    }
    //i < m&& j < n
    int last;
    if (i >= m)// nums1  completed to its end so use remaining of nums2
        {
        last = j;
        for (int z = last; z < n; z++)
            {
            arr[arrIndex] = nums2[z];
            arrIndex++;
            
            }
        }
    ////nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    else if (j >= n) //nums2  completed to its end so use remaining of nums1
    {
        last = i;
        for (int z = last; z < m; z++)
        {
            arr[arrIndex] = nums1[z];
            arrIndex++;
        }

    }

    for (int x = 0; x < m + n; x++)
    {
        
        
        nums1[x] = arr[x];
        printf("%d", nums1[x]);
        printf("\n");
    }

}