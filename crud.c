#include "crud.h"

int createClothes(Clothes *c){
    printf("\n");
    printf("제품명? ");
    scanf("%[^\n]s",c->name);

    printf("사이즈 (S, M, L, F(Free)? ");
    scanf("%c",&c->size);

    printf("==> 추가됨\n"); 
    return 1;
}

void readClothes(Clothes *c){

}

void listClothes(Clothes *c, int count){

}

int updateClothes(Clothes *c){

}

int deleteClothes(Clothes *c){

}