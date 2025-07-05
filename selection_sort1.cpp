void selection_sort(int arr[], int n) {
    int i, j, mini;

    for (i = 0; i < n - 1; i++) {
        mini = i;  // Assume the minimum is at the current index

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;  // Update index of the minimum element
            }
        }

        // Swap the found minimum element with the element at index i
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
