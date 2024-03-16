int binarySearch(int a[], int f, int l, int x)
{
    int mid;
    while (f <= l)
    {
        mid = f + (l - f) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            return binarySearch(a, mid + 1, l, x);
        else
            return binarySearch(a, f, mid - 1, x);
    }
    return -1;
}