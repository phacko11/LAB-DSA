static void merge(T* left, T* middle, T* right){
    /*TODO*/
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
            
    int leftArr[leftSize], rightArr[rightSize];
    for (int i = 0; i < leftSize; ++i) 
            leftArr[i] = left[i];
    for (int j = 0; j < rightSize; ++j) 
            rightArr[j] = middle[j + 1];
                
    int leftIdx = 0;
    int rightIdx = 0;
    int mergedArrIdx = 0;
            
    while (leftIdx < leftSize && rightIdx < rightSize) {
            if (leftArr[leftIdx] <= rightArr[rightIdx]) {
                left[mergedArrIdx] = leftArr[leftIdx];
                ++leftIdx;
            }
            else {
                left[mergedArrIdx] = rightArr[rightIdx];
                ++rightIdx;
            }
            ++mergedArrIdx;
        }
            
    while (leftIdx < leftSize) 
        {
            left[mergedArrIdx] = leftArr[leftIdx];
            ++leftIdx;
            ++mergedArrIdx;
        }
    while (rightIdx < rightSize) {
            left[mergedArrIdx] = rightArr[rightIdx];
            ++rightIdx;
            ++mergedArrIdx;
        }
    Sorting::printArray(left, right);
}
static void mergeSort(T* start, T* end){
    /*TODO*/
    if(start<end){
        T* mid = start + (end-start)/2;
        mergeSort(start,mid);
        mergeSort(mid+1,end);
        merge(start,mid,end);
    }
}
