vector<string> split (string s, char separator) {
    vector<string> res;
    int size = (int)s.size();
    int begin = 0;
    for (int i=0; i<size; ++i) {
        if (s[i] == separator) {
            string temp = s.substr(begin, i-begin);
            if (temp != "") res.push_back(temp);
            begin = i+1;
        }
    }
    string temp = s.substr(begin, size-begin);
    if (temp != "") res.push_back(temp);
    return res;
}