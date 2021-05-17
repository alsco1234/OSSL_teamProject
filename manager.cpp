#include "manager.h"
#include "crud.h"

void saveData(Product *p, string filename) {
    Clothes *tmp;
    ofstream of;
    of.open(filename);
    for (tmp = p->head; tmp!=NULL; tmp = tmp->link) {
        of << tmp->get_name() << "/" << tmp->get_price() << "/" << tmp->get_size() 
        << "/" << tmp->get_review() << "/" << tmp->get_numStars() << endl;
    }
    of.close();
} //데이터 저장

int loadData(Product *p, string filename) {
    ifstream inf;
    inf.open(filename);
    string str;
    int i, check=1;
    while (!inf.eof()) {
        Clothes tmp;
        getline(inf, str);
        if(str=="\0")break;
        char cutstr[80];    //구분할 문자열
        strcpy(cutstr,str.c_str());
        char *ptr = strtok(cutstr, "/"); //첫번째 strtok 사용.
        tmp.set_name(ptr);
        ptr = strtok(NULL, "/");
        tmp.set_price(stoi(ptr));
        ptr = strtok(NULL, "/");
        tmp.set_size(ptr);
        ptr = strtok(NULL, "/");
        tmp.set_review(stoi(ptr));
        ptr = strtok(NULL, "/");
        tmp.set_numStars(stoi(ptr));
        ptr = strtok(NULL, "/");
        p->add_to_tail(tmp);
    }
    inf.close();
    return check;
}


void searchName(Clothes *c, int count, string target){
    Clothes* curr = c;
    int check(0);
    char listname[80];
    char targetname[80];
    printf("제품명 / 사이즈 / 가격 / 리뷰개수 / 별점개수\n");
    while(curr!=NULL){
        strcpy(listname,curr->get_name().c_str());
        strcpy(targetname,target.c_str());
        if(strstr(listname,targetname)) {
            cout << curr->get_name() << " / " << curr->get_size();
            printf(" / %5d / ", curr->get_price());
            cout << curr->get_review() << " / " << curr->get_numStars() << endl;
            check=1;
        }
        curr = curr->link;
    }
    if(check==0) cout << "찾는 제품이 없습니다." << endl;
}

void searchPrice(Clothes *c, int count, int target){
    Clothes* curr = c;
    int check(0);
    printf("제품명 / 사이즈 / 가격 / 리뷰개수 / 별점개수\n");
    while(curr!=NULL){
        if(curr->get_price() == target) {
            cout << curr->get_name() << " / " << curr->get_size();
            printf(" / %5d / ", curr->get_price());
            cout << curr->get_review() << " / " << curr->get_numStars() << endl;
            check=1;
        }
        curr = curr->link;
    }
    if(check==0) cout << "찾는 제품이 없습니다." << endl;
}

void searchSize(Clothes *c, int count, string target){
    Clothes* curr = c;
    int check(0);
    printf("제품명 / 사이즈 / 가격 / 리뷰개수 / 별점개수\n");
    while(curr!=NULL){
        if(curr->get_size() == target) {
            cout << curr->get_name() << " / " << curr->get_size();
            printf(" / %5d / ", curr->get_price());
            cout << curr->get_review() << " / " << curr->get_numStars() << endl;
            check=1;
        }
        curr = curr->link;
    }
    if(check==0) cout << "찾는 제품이 없습니다." << endl;
}

void searchNum_stars(Clothes *c, int count, int target){
    Clothes* curr = c;
    int check(0);
    printf("제품명 / 사이즈 / 가격 / 리뷰개수 / 별점개수\n");
    while(curr!=NULL){
        if(curr->get_numStars() == target) {
            cout << curr->get_name() << " / " << curr->get_size();
            printf(" / %5d / ", curr->get_price());
            cout << curr->get_review() << " / " << curr->get_numStars() << endl;
            check=1;
        }
        curr = curr->link;
    }
    if(check==0) cout << "찾는 제품이 없습니다." << endl;
}
