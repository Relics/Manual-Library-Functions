vector<string> split (string s, char delimiter) {
    string temp;
    stringstream ss(s);
    vector<string> res;
    while (getline(ss, temp, delimiter)) res.push_back(temp);
    return res;
}

vector<string> split (string s, char delimiter) {
    string temp;
    stringstream ss(s);
    vector<string> res;
    while (getline(ss, temp, delimiter)) if (temp != "") res.push_back(temp);
    return res;
}


vector<string> split (string s, char delimiter) {
    vector<string> res;
    int size = (int)s.size();
    int begin = 0;
    for (int i=0; i<size; ++i) {
        if (s[i] == delimiter) {
            string temp = s.substr(begin, i-begin);
            if (temp != "") res.push_back(temp);
            begin = i+1;
        }
    }
    string temp = s.substr(begin, size-begin);
    if (temp != "") res.push_back(temp);
    return res;
}

