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

void saveData(Product *p, string filename) {
    ofstream of;
    of.open(filename);
    


} //데이터 저장

int loadData(Product *p, string filename) {
    ifstream inf;
    inf.open(filename);
    string str;
    int i, check=1;
    while (!inf.eof()) {
        Clothes tmp;
        getline(inf, str);
        vector<string> result = split(str, '/');
        for (int i=0;i<result.size();i++) {
            try {
                if (stoi(result[i])) {
                    tmp.set_price(stoi(result[i]));
                }
            } catch (invalid_argument& e){
                if (result[i].length()==1) {
                    tmp.set_size(result[i]);
                }
                else if (result[i].length() > 1)
                {
                    tmp.set_name(result[i]);
                }
                else {
                    cerr << e.what() << std::endl;
                    check = 0;
                    throw;
                }
            }
        }
        p->add_to_tail(tmp);
    }
    inf.close();
    return check;
}


int searchName(Clothes *c, int count);
int searchPrice(Clothes *c, int count);
int searchSize(Clothes *c, int count);
int searchNum_stars(Clothes *c, int count);
