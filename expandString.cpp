int kL(unsigned int kLength,unsigned int first,string s){
    if(first  - kLength == 0){
        return kLength;
    }
    if(!isdigit(s[first-kLength])){
        kLength--;
        return kLength;
    }
    
    kLength++;
    return kL(kLength,first,s);
}
void decode(string &decoded,string substr, int k){
    if(k==0) return;
    k--;
    decoded += substr;
    return decode(decoded,substr,k);
}
string reString(string& s) {
    unsigned int first = s.rfind('(');
	  if (first < 0 || first > s.size()) return s;
	  unsigned int second = s.find(')', first + 1);
	  unsigned int kLength = 1;
    kLength = kL(kLength,first,s);
	  int k = stoi(s.substr(first - kLength, kLength));
  	string be = s.substr(0, first - kLength);
	  string after = "";
	  if(second < s.size()-1) after = s.substr(second + 1);

	  string decoded = "";
	  string substr = s.substr(first + 1, second - first - 1);
	  decode(decoded,substr,k);
	  s = be + decoded + after;

	return reString(s);
}
string expand(string s) {
    return reString(s);
}
