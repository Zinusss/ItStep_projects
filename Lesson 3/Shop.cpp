#include <iostream>
#include <string>
#include <list>
using namespace std;
int buy(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user, int& shop_bal);
int report(list<string>& items);
int login(int& password, list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user, int& shop_bal);
int returned(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user, int& shop_bal);
int admins(int& password);
int seller(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_userint& bre, ad_user, int& butter_user, int& shop_bal);
int cleaner();
int guardian();
string random_action();
string random_action_guardian();


int main() {
    list<string> items = { "Молоко - 50грн", "Хліб - 20 грн","Масло - 90 грн" };
    int bal, shop_bal;
    string first_ext;
    int milk, bread, butter;
    int milk_user, bread_user, butter_user = 0;
    int password = 6754;
    milk = 10;
    bread = 15;
    shop_bal = 1000;
    butter = 3;
    bal = 1000;
    cout << "Виберіть дію: \n";
    cout << "1. Купити товар \n";
    cout << "2. Поскаржитись \n";
    cout << "3. Повернення товару \n";
    cout << "4. Вхід в акаунт\n";
    cout << "Введіть номер дії: \n";
    cin >> first_ext;
    if (first_ext == "1") {
        buy(items, bal, milk, bread, butter, milk_user, bread_user, butter_user, shop_bal);


    }
    else if (first_ext == "2") {
        report(items);

    }
    else if (first_ext == "3") {
        returned(items, bal, milk, bread, butter, milk_user, bread_user, butter_user, shop_bal);
    }
    else if (first_ext == "4") {
        login(password, items, bal, milk, bread, butter, milk_user, bread_user, butter_user, shop_bal);
    }
    return 0;
}
int buy(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user, int& shop_bal) {
    int count;
    int choose_item;
    string answer;
    int i = 0;
    cout << "Виберіть товар: \n";
    for (string item : items) {
        i++;
        cout << i << ". " << item << "\n";
    }
    cin >> choose_item;
    cout << "Введіть кількість товару: \n";
    cin >> count;
    if (choose_item == 1) {
        bal -= (50 * count);
        shop_bal += (50 * count);
        milk_user += count;
        milk -= count;
        cout << "Карта чи готівка? \n";
        cout << "Пакет потрібний? \n";
        cout << "Дякую за покупку! \n Ваш баланс: " + bal;
    }
    else if (choose_item == 2) {
        bal -= (20 * count);
        shop_bal += (20 * count);
        bread_user += count;
        bread -= count;
        cout << "Карта чи готівка? \n";
        cout << "Пакет потрібний? \n";
        cout << "Дякую за покупку! \n Ваш баланс: " + bal;
    }
    else if (choose_item == 3) {
        bal -= (90 * count);
        shop_bal += (90 * count);
        butter_user += count;
        butter -= count;
        cout << "Карта чи готівка? \n";
        cout << "Пакет потрібний? \n";
        cout << "Дякую за покупку! \n Ваш баланс: " + bal;
    }
    else {
        cout << "Невірний товар";
    }
    cout << "Хочете повернути товар?";
    cin >> answer;
    if (answer == "так") { //хотів зробити щоб ігнорувало регістер букв але не зміг зрозуміти як
        returned(items, bal, milk, bread, butter, milk_user, bread_user, butter_user, shop_bal);
    }
    else if (answer == "Так") { //хотів зробити щоб ігнорувало регістер букв але не зміг зрозуміти як
        returned(items, bal, milk, bread, butter, milk_user, bread_user, butter_user, shop_bal);
    }
    main();
    return 0;
}
int report(list<string>& items) {
    int choose_item;
    int i = 0;
    int ii = 0;
    cout << "Виберіть товар для скарги: \n";
    for (string item : items) {
        i++;
        cout << i << ". " << item << "\n";
    }
    cin >> choose_item;
    if (choose_item == 1) {
        items.remove("Молоко - 50грн");
        cout << "Товар виддалено! \n";
        cout << "Оновлений список товарів! \n";
        for (string item : items) {
            ii++;
            cout << ii << ". " << item << "\n";
        }
    }
    else if (choose_item == 2) {
        items.remove("Хліб - 20 грн");
        cout << "Товар виддалено! \n";
        cout << "Оновлений список товарів! \n";
        for (string item : items) {
            ii++;
            cout << ii << ". " << item << "\n";
        }
    }
    else if (choose_item == 3) {
        items.remove("Масло - 90 грн");
        cout << "Товар виддалено! \n";
        cout << "Оновлений список товарів! \n";
        for (string item : items) {
            ii++;
            cout << ii << ". " << item << "\n";
        }
    }
    else {
        cout << "Невірний товар";
    }
    main();
    return 0;
}
int returned(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user, int& shop_bal) {
    int count;
    int choose_item;
    int i = 0;
    cout << "Виберіть товар для повернення: \n";
    for (string item : items) {
        i++;
        cout << i << ". " << item << "\n";
    }
    cin >> choose_item;
    cout << "Введіть кількість товару : \n";
    cin >> count;
    if (choose_item == 1) {
        if (count <= milk_user) {
            bal += (50 * count);
            shop_bal -= (50 * count);
            milk_user -= count;
            milk += count;
            cout << "Успішне повернення! \n Ваш баланс: " + bal;
        }
        else {
            cout << "Недостатньо товару! \n Ваш баланс: " + bal;
        }
    }
    else if (choose_item == 2) {
        if (count <= bread) {
            bal += (20 * count);
            shop_bal -= (20 * count);
            bread_user -= count;
            bread += count;
            cout << "Успішне повернення! \n Ваш баланс: " + bal;

        }
        else {
            cout << "Недостатньо товару! \n Ваш баланс: " + bal;
        }
    }
    else if (choose_item == 3) {
        if (count <= bread) {
            bal += (90 * count);
            shop_bal -= (90 * count);
            butter_user -= count;
            butter += count;
            cout << "Успішне повернення! \n Ваш баланс: " + bal;

        }
        else {
            cout << "Недостатньо товару! \n Ваш баланс: " + bal;
        }
    }
    else {
        cout << "Невірний товар";
    }
    main();
    return 0;

}
string random_action() {
    int random = rand() % 3;
    string action;
    if (random == 0) {
        action = "Поставка товарів";
    }
    else if (random == 1) {
        action = "Оплата оренди";
    }
    else if (random == 2) {
        action = "Виплата зарплати";
    }
    else if (random == 3) {
        action = "Планові перевірки";
    }
    return action;
}
class Settings {
public:


    int documents() {
        cout << "Документи на товар в нормі! \n";
        cout << "Документи на приміщення в нормі! \n";
        return 0;
    };
    int workers_count;

};
int login(int& password, list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user, int& shop_bal) {
    int answer;

    int pass_answer;
    cout << "Виберіть акаунт: \n";
    cout << "1. Адміністратор \n";
    cout << "2. Продавець \n";
    cout << "3. Охоронець \n";
    cout << "Введіть номер дії: \n";
    cin >> answer;
    if (answer == 1) {
        cout << "Введіть пароль: \n";
        cin >> pass_answer;
        if (pass_answer == password) {
            admins(password);
        }
        else {
            cout << "Неправильний пароль \n";
            main();
        };
    }
    else if (answer == 2) {
        seller(items, bal, milk, bread, butter, milk_user, bread_user, butter_user, shop_bal);

    }
    else if (answer == 3) {
        guardian();
    }
    return 0;
};
int admins(int& password) {
    Settings admins;
    int answer, admins_count, password_answer;

    admins.workers_count = 2;
    cout << "Виберіть дію: \n";
    cout << "1. Змінити к-сть адмінів \n";
    cout << "2. Змінити пароль \n";
    cout << "3. Поточні події \n";
    cout << "4. Минулі події \n";
    cout << "5. Майбутні події \n";
    cout << "Введіть номер дії: \n";
    cin >> answer;
    if (answer == 1) {
        cout << "Введіть нову кількість адмінів \n";
        cin >> admins_count;
        admins.workers_count = admins_count;
    }
    else if (answer == 2) {
        cout << "Введіть новий пароль: \n";
        cin >> password_answer;
        password = password_answer;
        cout << "Новий пароль: " + password;
    }
    else if (answer == 3) {
        cout << random_action() + "\n";
    }
    else if (answer == 4) {
        cout << random_action() + "\n";
    }
    else if (answer == 5) {
        cout << random_action() + "\n";
    }
    main();
    return 0;
};
int seller(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user, int& shop_bal) {
    Settings sellers;
    sellers.workers_count = 5;
    int count, choose_item, answer;
    int i = 0;
    cout << "Виберіть дію: \n";
    cout << "1. Змінити к-сть адмінів \n";
    cout << "2. Змінити пароль \n";
    cout << "Введіть номер дії: \n";
    cin >> answer;
    if (answer == 1) {
        cout << "Виберіть товар для продажі: \n";
        for (string item : items) {
            i++;
            cout << i << ". " << item << "\n";
        }
        cin >> choose_item;
        cout << "Введіть кількість товару : \n";
        cin >> count;
        if (choose_item == 1) {
            if (count <= milk_user) {
                shop_bal += (90 * count);
                milk -= count;
                cout << "Успішний продаж! \n  Баланс магазину: " + shop_bal;
            }
            else {
                cout << "Недостатньо товару! \n Баланс магазину: " + shop_bal;
            }
        }
        else if (choose_item == 2) {
            if (count <= bread) {
                shop_bal += (20 * count);
                bread -= count;
                cout << "Успішний продаж! \n  Баланс магазину: " + shop_bal;
            }
            else {
                cout << "Недостатньо товару! \n Баланс магазину: " + shop_bal;
            }
        }
        else if (choose_item == 3) {
            if (count <= bread) {
                shop_bal += (90 * count);
                butter -= count;
                cout << "Успішний продаж! \n Баланс магазину: " + shop_bal;
            }
            else {
                cout << "Недостатньо товару! \n Баланс магазину: " + shop_bal;
            }
        }
        else {
            cout << "Невірний товар";
        }
    }
    else if (answer == 2) {
        int item_choose, item_choose2;
        cout << "Виберіть перший товар для обміну: \n";
        for (string item : items) {
            i++;
            cout << i << ". " << item << "\n";
        }
        cin >> item_choose;
        cout << "Виберіть другий товар для обміну: \n";
        cin >> item_choose2;
        if (item_choose == 1 && item_choose == 2) {
            if (milk > 1) {
                milk -= 1;
                bread += 1;
                cout << "Успішний обмін!";
            }
        }
        else if (item_choose == 1 && item_choose == 3) {
            if (milk > 1) {
                milk -= 1;
                butter += 1;
                cout << "Успішний обмін!";
            }

        }
        else if (item_choose == 2 && item_choose == 1) {
            if (bread > 1) {
                bread -= 1;
                milk += 1;
                cout << "Успішний обмін!";
            }
        }
        else if (item_choose == 2 && item_choose == 3) {
            if (bread > 1) {
                bread -= 1;
                butter += 1;
                cout << "Успішний обмін!";
            }
        }
        else if (item_choose == 3 && item_choose == 1) {
            if (butter > 1) {
                butter -= 1;
                milk += 1;
                cout << "Успішний обмін!";
            }
        }
        else if (item_choose == 3 && item_choose == 2) {
            if (butter > 1) {
                butter -= 1;
                bread += 1;
                cout << "Успішний обмін!";
            }
        }
        else {
            cout << "Невірний один з товарів!";
        }
    }


    main();
    return 0;
};
string random_action_guardian() {
    int random = rand() % 3;
    string action;
    if (random == 0) {
        action = "Крадіжка";
    }
    else if (random == 1) {
        action = "Пошкодження товару";
    }
    else if (random == 2) {
        action = "Напад";
    }
    else if (random == 3) {
        action = "Нічого не відбувається";
    }
    return action;
}
int cleaner() {
    Settings cleaners;
    int answer;

    cleaners.workers_count = 3;

    main();
    return 0;
};
int guardian() {
    Settings guardians;
    int answer;

    guardians.workers_count = 3;
    cout << "Виберіть дію: \n";
    cout << "1. Слідкувати за подіями \n";
    cout << "2. Переглядати ситуації \n";

    cout << "Введіть номер дії: \n";
    cin >> answer;
    if (answer == 1) {
        cout << "Ви слідкуєте за подіями! \n";
    }
    else if (answer == 2) {
        cout << random_action_guardian() + "\n";
    }

    main();
    return 0;
}


