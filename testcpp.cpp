#include <iostream>
//using namespace std;
//int main(){
//    cout << "hello world" << endl;
//}

#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool compare(pair<string, float> p1, pair<string, float> p2){
    return p1.second > p2.second;
}
void printKeyValue(map<string,float> m){
    vector<pair<string,float> > vec;
    map<string,float>::iterator iter;
    
    for(iter=m.begin(); iter != m.end(); iter++){   
        vec.push_back(make_pair(iter->first, iter->second));
    }
    sort(vec.begin(), vec.end(), compare);
    int i = 0;
    for(i = 0; i < vec.size(); i++){
        cout << "key=" << vec[i].first << ",value=" << vec[i].second << endl;
    }
}

int main() {
    //int a;
    //cin >> a;
    map<string, float> m = {{"aa",1},{"bb",2},{"cc", -1}};
    printKeyValue(m);
    cout << "Hello World!" << endl;
}
