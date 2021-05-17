#include "manager.h"
#include "crud.h"

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

void saveData(Clothes *c, string filename){ //데이터 저장
ofstream fout;
    Clothes *ahead;
    fout.open(filename);
    if(fout.is_open()){
        for (ahead = c->link; ahead!=NULL; ahead = ahead->link){
            fout << ahead->get_name() << "/" << ahead->get_price() << "/" << 
                ahead->get_size() << "/" << ahead->get_review() << "/" << ahead->get_numStars() << endl;
        }
    }
    fout.close();
}

int  loadData(Product *p, string filename) {
    ifstream inf(filename);
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
        return check;
}


void searchName(Clothes *c, int count, string target){
    Clothes* curr = c;
    char listname[80];
    char targetname[80];
    while(curr!=NULL){
        strcpy(listname,curr->get_name().c_str());
        strcpy(targetname,target.c_str());
        if(strstr(listname,targetname)) {
            cout << curr->get_name() << " / " << curr->get_size();
            printf(" / %5d\n", curr->get_price());
        }
        else curr = curr->link;
    }
    if(curr==NULL) cout << "target is not found" << endl;
}

void searchPrice(Clothes *c, int count, int target){
    Clothes* curr = c;
    while(curr!=NULL){
        if(curr->get_price() == target) {
            cout << curr->get_name() << " / " << curr->get_size();
            printf(" / %5d\n", curr->get_price());
        }
        else curr = curr->link;
    }
    if(curr==NULL) cout << "target is not found" << endl;
}

void searchSize(Clothes *c, int count, string target){
    Clothes* curr = c;
    while(curr!=NULL){
        if(curr->get_size() == target) {
            cout << curr->get_name() << " / " << curr->get_size();
            printf(" / %5d\n", curr->get_price());
        }
        else curr = curr->link;
    }
    if(curr==NULL) cout << "target is not found" << endl;
}

void searchNum_stars(Clothes *c, int count, int target){
    Clothes* curr = c;
    while(curr!=NULL){
        if(curr->get_numStars() == target) {
            cout << curr->get_name() << " / " << curr->get_size();
            printf(" / %5d\n", curr->get_price());
        }
        else curr = curr->link;
    }
    if(curr==NULL) cout << "target is not found" << endl;
}
