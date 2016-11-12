// Map
// Reference: http://blog.csdn.net/glp_hit/article/details/8109594
// Reference: http://blog.csdn.net/iicy266/article/details/11906189

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    map<string, int> name_score_map;
    
    name_score_map["LiMin"] = 90;
    name_score_map["ZiLinMi"] = 79;
    name_score_map["BoB"] = 92;
    name_score_map.insert(make_pair("Bing",99));
    name_score_map.insert(make_pair("Albert",86));
    
    // Sort by the key, output the min Key-Value pair
    for (auto i : name_score_map) {
        cout << i.first <<" "<< i.second <<endl;
    }
    cout << endl;
    
    // Another way to output;
    for (auto i=name_score_map.begin(); i!=name_score_map.end(); ++i) {
        cout << i->first <<" "<< i->second <<endl;
    }
    
    
    
    return 0;
}
