void closestKPoints(Point points[], int n, Point& des_point, int k) {
    
    if(n==0 || k==0) return;
    
  vector<pair<Point, double>> distances;
  for (int i = 0; i < n; i++) {
    double distance = sqrt((points[i].x - des_point.x) * (points[i].x - des_point.x) +
                           (points[i].y - des_point.y) * (points[i].y - des_point.y));
    distances.push_back({points[i], distance});
  }

  sort(distances.begin(), distances.end(),[](pair<Point, double>& a, pair<Point, double>& b) 
  { return a.second < b.second; });

  vector<Point> closest_points;
  for (int i = 0; i < k && i < n; i++) {
    closest_points.push_back(distances[i].first);
  }

  for (int i = 0; i < k && i < n; i++) {
    closest_points[i].display();
    cout <<endl;
  }
  cout << endl;
}
