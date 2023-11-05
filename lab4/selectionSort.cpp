template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int size = end - start;
        for (int i = 0; i < size - 1; ++i) {
            int min = start[i];
            int min_index = i;
            for (int j = i + 1; j < size; ++j) {
                if (start[j] < min)  {
                    min = start[j];
                    min_index = j;
                }
            }
            int temp = start[i];
            start[i] = start[min_index];
            start[min_index] = temp;
            Sorting<T>::printArray(start, end);
    }
}
