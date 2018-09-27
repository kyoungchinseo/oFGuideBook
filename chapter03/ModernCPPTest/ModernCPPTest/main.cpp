#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
//    vector<int> vec;
//
//    vec.assign(5, 10);
//    for(int i=0;i<5;i++) {
//        vec.push_back(50);
//    }
//
//    for(int i=0;i<vec.size();i++) {
//        cout << vec[i] << " ";
//    }
//    cout << endl;
//
//    vec[3] = 300;
//    vec[5] = 500;
//    vec[7] = 700;
//
//    vector<int>::iterator it;
//    for(it = vec.begin();it < vec.end(); it++) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//
//    it = vec.begin();
//    vec.insert(it+3,1234);
//    it = vec.begin();
//    vec.insert(it+7,4321);
//
//    for(auto item: vec) {
//        cout << item << " ";
//    }
//    cout << endl;


    map<string,int> player;

    player.insert(make_pair("soccer",11));
    player.insert(make_pair("baseball", 9));
    player.insert(make_pair("volleyball", 6));
    player["football"] = 11;
    player["basketball"] = 5;
    player["handball"] = 7;

    cout << "before:" << endl;
    map<string,int>::iterator mt;
    for(mt=player.begin(); mt != player.end(); mt++) {
        cout << "key : " << mt->first << "," << "value : " << mt->second << endl;
    }

    player.erase("football");
    mt = player.find("volleyball");
    player.erase(mt);

    cout << "after: " << endl;
    for(auto it : player) {
        cout << "key : " << it.first << "," << "value : " << it.second << endl;
    }
    
    return 0;
}
