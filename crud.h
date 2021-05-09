#include <stdio.h>
#include <string.h>

typedef struct {
char name[30]; // 제품명
int price; // 가격
char size; // 사이즈(S, M, L, F(Free))
int review; // 리뷰개수
int num_stars; // 별점개수
Clothes *link; // 다음 node를 가리키는 포인터 변수 n
}Clothes;

Clothes clist[100]; //포인터 배열 변수 선언

int createClothes(Clothes *c);

void readClothes(Clothes *c);

void listClothes(Clothes *c, int count);

int updateClothes(Clothes *c);

int deleteClothes(Clothes *c);
