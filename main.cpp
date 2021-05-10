#include <iostream>
#include "crud_cpp.h"
#define QUIT 0
#define READ 1
#define CREATE 2
#define UPDATE 3
#define DELETE 4
#define SEARCH 5
#define SAVE 6

int main() {
    Product top, bot, dress;
    Clothes tmp;
    string CATEGORY[3] = {"상의","하의","드레스"};
    int cmd, type, check=1, count=0, edited_count=0;
    do {
        cmd = menu();
        switch (cmd) {
            case READ:
                switch (category()) {
                    case 0:
                        if (top.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        else {
                            printf("제품 정보입니다.\n");
                            readClothes(top.head);
                        }
                    case 1:
                        if (bot.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        else {
                            printf("제품 정보입니다.\n");
                            readClothes(bot.head);
                        }
                    case 2:
                        if (dress.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        else {
                            printf("제품 정보입니다.\n");
                            readClothes(dress.head);
                        }
                    case 3:
                        if (top.list_empty() || bot.list_empty() || dress.list_empty()) {
                            printf("등록된 상품이 없습니다.\n");
                            break;
                        }
                        else {
                            printf("상의>\n");
                            readClothes(top.head);
                            printf("\n하의\n");
                            readClothes(bot.head);
                            printf("\n드레스\n");
                            readClothes(dress.head);
                        }
                }
                break;
            case CREATE:
                printf("카테고리 (0:상의, 1:하의, 2:드레스)? ");
                scanf("%d", &type);
                tmp = createClothes();
                switch (type) {
                    case 0:
                        top.add_to_tail(tmp);
                        break;
                    case 1:
                        bot.add_to_tail(tmp);
                        break;
                    case 2:
                        dress.add_to_tail(tmp);
                        break;
                    default:
                        cout << "ERROR" << endl;
                        check=0;
                }
                if (check==1) {
                    printf("==> 추가됨\n");
                }
                break;
            case UPDATE:
                if (edited_count==0) {
                    printf("등록된 정보가 없습니다.\n");
                    break;
                }
                check = updateProduct(p, count);
                if (check == 1) {
                    printf("수정되었습니다.\n");
                }
                break;
            case DELETE:
                if (edited_count==0) {
                    printf("등록된 정보가 없습니다.\n");
                    break;
                }
                check = deleteProduct(p, count);
                if (check == 1) {
                    printf("삭제되었습니다.\n");
                    edited_count--;
                }
                else if (check == 0) {
                    printf("취소되었습니다.\n");
                }
                break;
            default:
                break;
        }
    } while(cmd != QUIT);
    printf("종료되었습니다.\n");
    return 0;
}