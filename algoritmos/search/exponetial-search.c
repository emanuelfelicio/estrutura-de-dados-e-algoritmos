// é bom quando o tamanho do array é muito grande ou indeterminado. em geral binary-search sozinho é suficiente
int exponential_search(int arr[], int n, int x)
{
    if (n == 0)
        return -1;

    // caso seja exatamente o primeiro elemento 
    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;

    int left = i / 2;
    int right = i < n ? i : n - 1;

    // usa binary-search
    return binary_search(arr, left, right, x);
}