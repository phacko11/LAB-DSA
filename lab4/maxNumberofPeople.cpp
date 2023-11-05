int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    if(rooms.empty() || people.empty()) return 0;
  sort(rooms.begin(), rooms.end());
  sort(people.begin(), people.end());

  int i = 0;
  int j = 0;

  int max_people = 0;

  while (j < people.size() && i < rooms.size()) {

    if (rooms[i] < people[j] - k) i++;
    
    else if (rooms[i] > people[j] + k) j++;
    
    else {
        max_people++;
        j++;
        i++;
    }
  }

  return max_people;
}
