#include <iostream>

using namespace std;

int menu();

class Clothes {
private:
    string name;        //제품명
    int price;          //가격
    char size;          //사이즈(S,M,L,F(free))
    int review;         //리뷰 개수
    int numStars;       //별점 개수
public:
    Clothes* link;      //다음 node를 가리키는 포인터
    //setter
    void set_data(string n, int p, char s, int r, int ns);
    void set_name(string n);
    void set_price(int p);
    void set_size(char s);
    void set_review(int r);
    void set_numStars(int ns);
    //getter
    string get_name();
    int get_price();
    char get_size();
    int get_review();
    int get_numStars();
    Clothes* get_link();
};

class Product {
public:
    Clothes *head, *tail;
    Product();
    void add_to_tail(Clothes c);
    Clothes delete_from_head();
    int num_nodes();
    bool list_empty();
    Clothes get_product(string p_name);
    int remove_product(string p_name);
};



Clothes clist[100]; //포인터 배열 변수 선언

Clothes createClothes();

void readClothes(Clothes *c);

void listClothes(Clothes *c, int count);

int updateClothes(Clothes *c);

int deleteClothes(Clothes *c);

int category();