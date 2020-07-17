#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int* A;
    int size;
    int length;
};

void _()
{
    printf("\n");
}

void Display(struct Array arr)
{
    printf("Elements are :  ");
    for (int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    _();
    _();
}

void Append(struct Array* arr, int x)
{
    if (arr->length<arr->size)
    {
        arr->A[arr->length++]=x;
    }
    else
    {
        printf("Full");
    }
    _();
}

void Insert(struct Array* arr, int x, int index)
{
    if (arr->size == arr->length)
    {
        printf("Full");
    }
    else if (index>=0 && index<=arr->length)
    {
        for (int i=arr->length;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
    else
    {
        printf("\nInvalid index");
    }
}

int Delete(struct Array* arr,int index)
{
    int x;
    if (arr->length==0)
    {
        printf("Empty");
        return -1;
    }
    if (index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for (int i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    printf("Invalid index");
    return -1;
}

int LinearSearch(struct Array arr, int key)
{
    for (int i=0;i<arr.length;i++)
    {
        if (arr.A[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int mid,l=0,h=arr.length-1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if (key==arr.A[mid]) return mid;
        else if (key>arr.A[mid]) l=mid+1;
        else if (key<arr.A[mid]) h=mid-1;
    }
    return -1;

}

//Rbinsearch do it

int Get(struct Array arr,int index)
{
    if (index>=0 &&  index <arr.length)
    {
        return arr.A[index];
    }
    printf("Invalid index");
    return -1;
}

void Set(struct Array* arr,int x, int index)
{
    if (index>=0 && index < arr->length)
    {
        arr->A[index]=x;
    }
    else
    {
        printf("Invalid index");
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i=1;i<arr.length;i++)
    {
        if (arr.A[i]>max) max=arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i=1;i<arr.length;i++)
    {
        if (arr.A[i]<min) min=arr.A[i];
    }
    return min;
}


int Sum(struct Array arr)
{
    int sum=0;
    for (int i=0;i<arr.length;i++)
    {
        sum+=arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Reverse(struct Array* arr)
{
    for (int i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

void InsertSort(struct Array* arr,int x)
{
    if (arr->length==arr->size)
    {
        printf("Full");
        return;
    }
    int i = arr->length-1;
    while (i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    for (int i=0;i<arr.length-1;i++)
    {
        if (arr.A[i]>arr.A[i+1]) return 0;
    }
    return 1;
}

void reArrange(struct Array* arr)
{
    int i=0,j=arr->length-1;
    while (i<j)
    {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0) j--;
        if (i<j) swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
    struct Array* arr3 = (struct Array*) malloc (sizeof(struct Array));
    arr3->A = (int*) malloc((arr1->length+arr2->length+10)*sizeof(int));
    int i=0,j=0,k=0;
    while (i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
        { 
            arr3->A[k++]=arr1->A[i++];
        }
        else
        {
             arr3->A[k++]=arr2->A[j++];
        }
    }
    while(i<arr1->length)
    {
        arr3->A[k++]=arr1->A[i++];
    }
    while(j<arr2->length)
    {
        arr3->A[k++]=arr2->A[j++];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->length+arr2->length+10;
    return arr3;
}

struct Array* Union(struct Array* arr1, struct Array* arr2)
{
    struct Array* arr3 = (struct Array*) malloc (sizeof(struct Array));
    arr3->A = (int* ) malloc((arr1->length+arr2->length+10)*sizeof(int));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
        }
        else if (arr2->A[j]<arr1->A[i])
        {
            arr3->A[k++]=arr2->A[j++];
        }
        else
        {
            arr3->A[k++]=arr1->A[i++];j++;
        }
    }
    while(i<arr1->length)
    {
        arr3->A[k++]=arr1->A[i++];
    }
    while(j<arr2->length)
    {
        arr3->A[k++]=arr2->A[j++];
    }
    arr3->length=k;
    arr3->size=arr1->length+arr2->length+10;
    return arr3;
}

struct Array* Intersection(struct Array* arr1, struct Array* arr2)
{
    struct Array* arr3 = (struct Array*) malloc (sizeof(struct Array));
    arr3->A = (int* ) malloc((arr1->size)*sizeof(int));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
        {
            //arr3->A[k++]=arr1->A[i++];
            i++;
        }
        else if (arr2->A[j]<arr1->A[i])
        {
            //arr3->A[k++]=arr2->A[j++];
            j++;
        }
        else
        {
            arr3->A[k++]=arr1->A[i++];j++;
        }
    }
    arr3->length=k;
    arr3->size=arr1->size;
    return arr3;
}

struct Array* Difference(struct Array* arr1, struct Array* arr2)
{
    struct Array* arr3 = (struct Array*) malloc (sizeof(struct Array));
    arr3->A = (int* ) malloc((arr1->size)*sizeof(int));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
        }
        else if (arr2->A[j]<arr1->A[i])
        {
            //arr3->A[k++]=arr2->A[j++];
            j++;
        }
        else
        {
           // arr3->A[k++]=arr1->A[i++];j++;
           i++;j++;
        }
    }
    while(i<arr1->length)
    {
        arr3->A[k++]=arr1->A[i++];
    }/*
    while(j<arr2->length)
    {
        arr3->A[k++]=arr2->A[j++];
    }*/
    arr3->length=k;
    arr3->size=arr1->size;
    return arr3;
}

int main()
{
    struct Array arr;

    //initialise + user input

    //actual initialisation

    /* Actual code
    printf("Enter size : (10) ");scanf("%d",&arr.size);
    arr.A = (int*) malloc(arr.size*sizeof(int));
    arr.length=0;
    int n;
    printf("\nEnter number of numbers :(5) ");
    scanf("%d",&n);
    printf("\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr.A[i]);
    }
    arr.length = n;
    */
    //display

    //ready made input

    printf("Enter size : (10) ");//scanf("%d",&arr.size);
    arr.A = (int*) malloc(10*sizeof(int));
    arr.length=0;
    int n;
    printf("\nEnter number of numbers :(5) 1 2 3 4 5 ");
    arr.A[0]=2;arr.A[1]=3;arr.A[2]=4;arr.A[3]=5;arr.A[4]=6;
    arr.length = 5;
    arr.size = 10;//Danger

    Display(arr);

    //Append
    printf("10 appended");
    Append(&arr,10);
    Display(arr);

    //Insert
    printf("Inserting 1 at 0\n");
    Insert(&arr,1,0);
    Display(arr);

    //Delete
    printf("Deleting at 0\n");
    int res = Delete(&arr,0);
    printf("Deleted : %d\n",res);
    Display(arr);

    //Searches
    printf("Linear search on 4\n");
    printf("pos : %d \n",LinearSearch(arr,4));
    printf("Binary search on 5\n");
    printf("pos : %d \n",BinarySearch(arr,5));

    //Other functions
    Display(arr);
    printf("Get at pos 2 : %d\n",Get(arr,2));
    printf("Set value at pos 0 to 1\n");Set(&arr,1,0);
    Display(arr);
    printf("Resetting\n");Set(&arr,2,0);
    Display(arr);
    printf("Max is %d, min is %d, sum is %d, avg is %f\n",Max(arr),Min(arr),Sum(arr),Avg(arr));

    //Reversing
    printf("\nReversing\n");Reverse(&arr);Display(arr);
    printf("\nRe-Reversing\n");Reverse(&arr);Display(arr);

    //New Array B for Insert Sort
    printf("\nNew Array 2 3 5 10 15\n");
    struct Array arr1;
    arr1.A = (int*) malloc(10*sizeof(int));
    arr1.A[0]=2;arr1.A[1]=3;arr1.A[2]=5;arr1.A[3]=10;arr1.A[4]=15;
    arr1.length = 5;
    arr1.size=10; //Danger
    Display(arr1);

    InsertSort(&arr1,20);
    Display(arr1);
    InsertSort(&arr1,7);
    Display(arr1);
    printf("Sorted ? : %d\n",isSorted(arr1));

    //Re-arrange
    printf("\nNew Array 1 2 -3 -4 5 6 -7 -8 \n");
    struct Array arr2;
    arr2.A = (int*) malloc(10*sizeof(int));
    arr2.A[0]=1;arr2.A[1]=2;arr2.A[2]=-3;arr2.A[3]=-4;arr2.A[4]=5;arr2.A[5]=6;arr2.A[6]=-7;arr2.A[7]=-8;
    arr2.length = 8;
    Display(arr2);
    reArrange(&arr2);
    Display(arr2);

    //Merging arr and arr1
    printf("\nMerging arr and arr1\n");
    struct Array* arr3;
    arr3 = Merge(&arr,&arr1);
    Display(*arr3);
    free(arr3);

    //Union
    printf("\nUnion of arr and arr1\n");
    struct Array* arr4;
    arr4 = Union(&arr,&arr1);
    Display(*arr4);
    free(arr4);

    //Intersection
    printf("\nIntersection of arr and arr1\n");
    struct Array* arr5;
    arr5 = Intersection(&arr,&arr1);
    Display(arr);Display(arr1);
    Display(*arr5);
    free(arr5);

    //Difference
    printf("\nDifference of arr and arr1\n");
    struct Array* arr6;
    arr6 = Difference(&arr,&arr1);
    Display(*arr6);
    free(arr6);
    

    return 0;
}