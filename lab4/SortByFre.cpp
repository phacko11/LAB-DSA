void sortByFrequency(int arr[], int n){
    if (n==0 || n==1) return;
  vector<pair<int,int>> freq;
  int temp[n];
  for(int i = 0;i<n;i++) temp[i]=arr[i];

  int val;
  int count = 1;
  int index = 0;
  bool check = false;
  for(int i = 0;i<n;i++){
     //Check neu da dem tan so thi bo qua
      for(unsigned int k = 0;k<freq.size();k++){
          if(freq[k].first == temp[i]){
              check = true;
              break;
          }
      }
      if(check){
          check=false;
          continue;
      }
     
      //Dem so lan xuat hien va day vao mang
      val = temp[i];
      count = 1;
      int j = i+1;
      while(j<n){
          if(temp[j] == val){
              count++;
          }
          j++;
      }
      freq.push_back({val,count});
      index++;
      
  }
  //Sap xep lai mang theo tan so;
  sort(freq.begin(),freq.end(),[](pair<int,int> &a, pair<int,int> &b){return a.second>b.second;});
  int index2 = 0;
  //Chinh sua mang ban dau 
  for(int i = 0;i<index;){
         while(freq[i].second){
          arr[index2] = freq[i].first;
          index2++;
          freq[i].second--;
      }
      i++;
  }
}
