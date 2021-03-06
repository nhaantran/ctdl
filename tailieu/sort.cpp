#include <iostream>
using namespace std;
void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
void swap(int &x, int &y)
{
    int temp=x;
    x=y;
    y=temp;
}


    // SELECTION SORT giam dan
void selectionsort(int a[], int n)
{
    int max;
    for (int i = 0; i < n-1; i++)
    {
        cout << "i=" << i << ":"<< endl;
        max = i;
        for (int j = i+1; j<n; j++)
        {
            if (a[j]>a[max]) max = j;
        }
        cout << "Max = " << "a[" << max << "] = " << a[max] << endl;
        swap(a[max],a[i]);
        cout << "Mang sau khi sap xep " << i+1 << " phan tu dau tien la: "; xuat(a,n);
    }
}

    // selection sort tang dan
void selectionsort(int a[], int n)
{
    int max;
    for (int i = 0; i < n-1; i++)
    {
        cout << "i=" << i << ":"<< endl;
        max = i;
        for (int j = i+1; j<n; j++)
        {
            if (a[j]<a[max]) max = j;
        }
        cout << "Max = " << "a[" << max << "] = " << a[max] << endl;
        swap(a[max],a[i]);
        cout << "Mang sau khi sap xep " << i+1 << " phan tu dau tien la: "; xuat(a,n);
    }
}


    // INSERTION SORT giam gan
void insertionsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        int temp = a[i];
        while (temp>a[j] && j >= 0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        cout << "Vi tri chen cua a[" << i << "] la " << j+1 << endl;
        xuat(a,n);
    }
}

    // insertion sort tang dan
void insertionsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        int temp = a[i];
        while (temp<a[j] && j >= 0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        cout << "Vi tri chen cua a[" << i << "] la " << j+1 << endl;
        xuat(a,n);
    }
}

    //HEAP SORT TANG DAN
void heapify(int *a, int i, int n)
{
    int largest=i;
    int left=i*2 + 1;
    int right=i*2 + 2;
    if(left<n&&a[largest]<a[left])largest=left;
    if(right<n&&a[largest]<a[right])largest=right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,largest,n);
    }
}
void heapsort(int *a, int n)
{
    for(int i=n/2 -1;i>=0;i--) heapify(a,i,n);
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}

// HEAPSORT GIAM DAN
void heapify(int *a, int i, int n)
{
    int largest=i;
    int left=i*2 + 1;
    int right=i*2 + 2;
    if(left<n&&a[largest]>a[left])largest=left;
    if(right<n&&a[largest]>a[right])largest=right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,largest,n);
    }
}
void heapsort(int *a, int n)
{
    for(int i=n/2 -1;i>=0;i--) heapify(a,i,n);
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}

    // QUick sort
              //string
void quicksort(int a[], int low, int high)
{
    if (low <= high)
    {
        //string 
        int pivot = a[(low + high) / 2];
        int left = low, right = high;
        while (left <= right)
        {
            while (a[left] < pivot) left++;
            while (a[right] > pivot) right--;
            if (left <= right)
            {
                swap(a[left], a[right]);
                left++;
                right--;
            }
        }
        if (low < right) quicksort(a, low, right);
        if (high > left) quicksort(a, left, high);
    }
}

// quicksort(a,0,n-1) trong main

    // merge sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    /* T???o c??c m???ng t???m */
    int L[n1], R[n2];
    /* Copy d??? li???u sang c??c m???ng t???m */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    /* G???p hai m???ng t???m v???a r???i v??o m???ng arr*/
    i = 0; // Kh???i t???o ch??? s??? b???t ?????u c???a m???ng con ?????u ti??n
    j = 0; // Kh???i t???o ch??? s??? b???t ?????u c???a m???ng con th??? hai
    k = l; // IKh???i t???o ch??? s??? b???t ?????u c???a m???ng l??u k???t qu???
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copy c??c ph???n t??? c??n l???i c???a m???ng L v??o arr n???u c?? */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copy c??c ph???n t??? c??n l???i c???a m???ng R v??o arr n???u c?? */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l l?? ch??? s??? tr??i v?? r l?? ch??? s??? ph???i c???a m???ng c???n ???????c s???p x???p */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // T????ng t??? (l+r)/2, nh??ng c??ch n??y tr??nh tr??n s??? khi l v?? r l???n
        int m = l+(r-l)/2;
        // G???i h??m ????? quy ti???p t???c chia ????i t???ng n???a m???ng
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
// mergeSort(arr,0,n-1);

    // bubble sort
void bubblesort(int *a, int i, int n)
{
    int j=n-1;
    if(n>i)
    {
        while(j>=i)
        {
            if(a[j]<a[j-1]) 
            {
                cout<<a[j]<<" "<<a[j-1]<<endl;
                swap(a[j],a[j-1]);
            }
            j--;
        }
        bubblesort(a,i+1,n);
    }
}
// bubble sort(a,0,n)