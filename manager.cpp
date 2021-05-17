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
    Clothes tmp;
    ifstream inf(filename);
    string str;
    int i;
    while (!inf.eof()) {
        getline(inf, str);
        vector<string> result = split(str, '/');
        for (int i=0;i<result.size();i++) try {
            if (stoi(result[i])) {
                tmp.set_price(stoi(result[i]));
            }
        } catch (invalid_argument& e){
            cerr << e.what() << std::endl;
        }
            tmp.set_name(result[i]);
            cout << result[i] << endl;
        }
    }
}


int searchName(Clothes *c, int count);
int searchPrice(Clothes *c, int count);
int searchSize(Clothes *c, int count);
int searchNum_stars(Clothes *c, int count);
