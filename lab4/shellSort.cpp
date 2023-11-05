// TODO: Write your code here

static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    // TODO
}

static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    // TODO
    // Note: You must print out the array after sorting segments to check whether your algorithm is true.
    for (int phase = num_phases - 1; phase >=0; phase--)
        {
            int gap = num_segment_list[phase];
          
            for(int i = gap;i<(end-start);i+=1){
                int temp = start[i];
                int j;
                for(j  = i;j>=gap && start[j-gap] > temp; j-=gap)
                {
                    start[j] = start[j - gap];
                }
                start[j] = temp;
            }
            cout<<num_segment_list[phase]<<" segments: ";printArray(start,end); 
        }
     
}
