#include "manager.h"
#include "crud_cpp.h"

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

void saveData(Clothes *c); //데이터 저장

int loadData(Clothes *c, string filename) {
    ifstream inf(filename);
    string str;
    while (!inf.eof()) {
        getline(inf, str);
        vector<string> result = split(str, '/');
        for (int i=0;i<result.size();i++){
            cout << result[i] << endl;
        }
    }
}


int searchName(Clothes *c, int count);
int searchPrice(Clothes *c, int count);
int searchSize(Clothes *c, int count);
int searchNum_stars(Clothes *c, int count);
