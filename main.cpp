#include "crud.h"
#include "manager.h"
#define QUIT 0
#define READ 1
#define CREATE 2
#define UPDATE 3
#define DELETE 4
#define SEARCH 5
#define LOAD 6  //???? ???
#define SAVE 7  //???? ????

int main() {
    Product top, bot, dress;
    Clothes tmp;
    string CATEGORY[3] = {"����","����","�巹��"}, temp, remainder;
    int cmd, type, check=1, count=0;
    do {
        cmd = menu();
        switch (cmd) {
            case READ:
                switch (category()) {
                    case 0:
                        if (top.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.");
                            break;
                        }
                        else {
                            cout << "\n" << CATEGORY[0] << " �ǰ ����Դϴ�." << endl;
                            readClothes(top.head);
                        }
                        break;
                    case 1:
                        if (bot.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.\n");
                            break;
                        }
                        else {
                            cout << "\n" << CATEGORY[0] << " �ǰ ����Դϴ�." << endl;
                            readClothes(bot.head);
                        }
                        break;
                    case 2:
                        if (dress.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.\n");
                            break;
                        }
                        else {
                            cout << "\n" << CATEGORY[0] << " �ǰ ����Դϴ�." << endl;
                            readClothes(dress.head);
                        }
                        break;
                    case 3:
                        if (top.list_empty() || bot.list_empty() || dress.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.\n");
                            break;
                        }
                        else {
                            printf("\n����\n");
                            readClothes(top.head);
                            printf("\n\n����\n");
                            readClothes(bot.head);
                            printf("\n\n�巹��\n");
                            readClothes(dress.head);
                        }
                }
                break;
            case CREATE:
                tmp = createClothes();
                switch (category()) {
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
                if (check==1) printf("==> �߰���\n");
                break;
            case UPDATE:
                switch (category()) {
                    case 0:
                        if (top.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.\n");
                            break;
                        }
                        readClothes(top.head);
                        printf("����ϰ� ��� �ǰ �̸�? ");
                        getline(cin, remainder);
                        getline(cin, temp);
                        check = updateClothes(top.get_product(temp));
                        break;
                    case 1:
                        if (bot.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.\n");
                            break;
                        }
                        readClothes(bot.head);
                        printf("����ϰ� ��� �ǰ �̸�? ");
                        getline(cin, remainder);
                        getline(cin, temp);
                        check = updateClothes(bot.get_product(temp));
                        break;
                    case 2:
                        if (dress.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.\n");
                            break;
                        }
                        readClothes(dress.head);
                        printf("����ϰ� ��� �ǰ �̸�? ");
                        getline(cin, remainder);
                        getline(cin, temp);
                        check = updateClothes(dress.get_product(temp));
                        break;
                    default:
                        cout << "ERROR" << endl;
                        check=0;
                }
                if (check==1) printf("==> �����\n");
                break;
            case DELETE:
                switch (category()) {
                    case 0:
                        if (top.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.\n");
                            break;
                        }
                        deleteClothes(&top);
                        break;
                    case 1:
                        if (bot.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.\n");
                            break;
                        }
                        deleteClothes(&bot);
                        break;
                    case 2:
                        if (dress.list_empty()) {
                            printf("��ϵ� ��ǰ�� ���ϴ�.\n");
                            break;
                        }
                        deleteClothes(&dress);
                        break;
                    default:
                        cout << "ERROR" << endl;
                        check=0;
                }
                if (check==1) printf("==> �����\n");
                break;
            case SEARCH:
            int searchhow;
                std :: cout << "������� �˻��Ͻðڽ�ϱ�?" << endl;
                std :: cout << "�̸�(1) /  ����(2) / ������(3) / �����(4) / ���(0)" << endl;
                std :: cin >> searchhow;
                if(searchhow==0) break;
                else if(searchhow==1){
                    string target;
                    std :: cout << "\n� �̸�� ã�����? ";
                    std :: cin >> target;
                    std :: cout << "\ncategory 1. ���ǿ���" << endl;
                    searchName(top.head, count, target);
                    std :: cout << "\ncategory 2. ���ǿ���" << endl;
                    searchName(bot.head, count, target);
                    std :: cout << "\ncategory 3. �巹������" << endl;
                    searchName(dress.head, count, target);
                }
                else if(searchhow==2){
                    int target;
                    std :: cout << "\n� ����� ã�����? ";
                    std :: cin >> target;
                    std :: cout << "\ncategory 1. ���ǿ���" << endl;
                    searchPrice(top.head, count, target);
                    std :: cout << "\ncategory 2. ���ǿ���" << endl;
                    searchPrice(bot.head, count, target);
                    std :: cout << "\ncategory 3. �巹������" << endl;
                    searchPrice(dress.head, count, target);
                }
                else if(searchhow==3){
                    string target;
                    std :: cout << "\n� ����� ã�����? ";
                    std :: cin >> target;
                    std :: cout << "\ncategory 1. ���ǿ���" << endl;
                    searchSize(top.head, count, target);
                    std :: cout << "\ncategory 2. ���ǿ���" << endl;
                    searchSize(bot.head, count, target);
                    std :: cout << "\ncategory 3. �巹������" << endl;
                    searchSize(dress.head, count, target);
                }
                else if(searchhow==4){
                    int target;
                    std :: cout << "\n� ��� �� ã�����? ";
                    std :: cin >> target;
                    std :: cout << "\ncategory 1. ���ǿ���" << endl;
                    searchNum_stars(top.head, count, target);
                    std :: cout << "\ncategory 2. ���ǿ���" << endl;
                    searchNum_stars(bot.head, count, target);
                    std :: cout << "\ncategory 3. �巹������" << endl;
                    searchNum_stars(dress.head, count, target);
                }
                break;
            case LOAD:
                switch (category()) {
                    case 0:
                        //loadData();
                        check = loadData(&top, "topInfo.txt");
                        break;
                    case 1:
                        check = loadData(&bot, "botInfo.txt");
                        break;
                    case 2:
                        check = loadData(&dress, "dressInfo.txt");
                        break;
                    default:
                        cout << "ERROR" << endl;
                        check=0;
                }
                if (check==1) printf("==> �ε�Ϸ�\n");
                break;
            case SAVE:
                switch (category()) {
                    case 0:
                        saveData(&top, "topInfo.txt");
                        break;
                    case 1:
                        saveData(&bot, "botInfo.txt");
                        break;
                    case 2:
                        saveData(&dress, "dressInfo.txt");
                        break;
                    default:
                        cout << "ERROR" << endl;
                        check=0;
                }
                cout << "==> 저장완료" << endl;
                break;
            default:
                break;
        }
    } while(cmd != QUIT);
    printf("����.\n");
    return 0;
}
