#include <iostream>
#include <string>
#include <list>
using namespace std;
int buy(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user);
int report(list<string>& items);
int returned(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user);
int main(){
    list<string> items ={"Молоко - 50грн", "Хліб - 20 грн","Масло - 90 грн"};
    int bal;
    string first_ext;
    int milk,bread,butter; 
    int milk_user,bread_user,butter_user = 0;
    milk = 10;
    bread = 15; 
    butter = 3;
    bal = 1000;
    cout << "Виберіть дію: \n";
    cout << "1. Купити товар \n";
    cout << "2. Поскаржитись \n";
    cout << "3. Повернення товару \n";
    cout << "Введіть номер дії: \n";
    cin >> first_ext;
    if (first_ext == "1"){
        buy(items, bal, milk, bread, butter, milk_user, bread_user, butter_user);
        
    }
    else if (first_ext == "2"){
        report(items);
    }
    else if(first_ext == "3"){
        returned(items, bal, milk, bread, butter, milk_user, bread_user, butter_user);
    }
    
    return 0;
}
int buy(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user){
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
    if(choose_item == 1){
        bal-=(90*count);
        milk_user+=count;
        milk-=count;
        cout << "Карта чи готівка? \n";
        cout << "Пакет потрібний? \n";
        cout << "Дякую за покупку! \n Ваш баланс: " + bal;
    } else if(choose_item == 2){
        bal-=(20*count);
        bread_user+=count;
        bread-=count;
        cout << "Карта чи готівка? \n";
        cout << "Пакет потрібний? \n";
        cout << "Дякую за покупку! \n Ваш баланс: " + bal;
    } else if(choose_item == 3){
        bal-=(90*count);
        butter_user+=1;
        butter-=count;
        cout << "Карта чи готівка? \n";
        cout << "Пакет потрібний? \n";
        cout << "Дякую за покупку! \n Ваш баланс: " + bal;
    }else{
        cout << "Невірний товар";
    }
    cout << "Хочете повернути товар?";
    cin >> answer;
    if(answer == "так"){ //хотів зробити щоб ігнорувало регістер букв але не зміг зрозуміти як
        returned(items, bal, milk, bread, butter, milk_user, bread_user, butter_user);
    } 
    else if(answer == "Так"){ //хотів зробити щоб ігнорувало регістер букв але не зміг зрозуміти як
        returned(items, bal, milk, bread, butter, milk_user, bread_user, butter_user);
    } 
    return 0;
}
int report(list<string>& items){
    int choose_item;
    int i = 0;
    int ii = 0;
    string ii = "33";
    cout << "Виберіть товар для скарги: \n";
    for (string item : items) {
        i++;
        cout << i << ". " << item << "\n";
    }
    cin >> choose_item;
    if(choose_item == 1){
        items.remove("Молоко - 50грн");
        cout << "Товар виддалено! \n";
        cout << "Оновлений список товарів! \n";
        for (string item : items) {
        ii++;
        cout << ii << ". " << item << "\n";
    }
    }else if(choose_item == 2){
        items.remove("Хліб - 20 грн");
        cout << "Товар виддалено! \n";
        cout << "Оновлений список товарів! \n";
    for (string item : items) {
        ii++;
        cout << ii << ". " << item << "\n";
    }
    }else if(choose_item == 3){
       items.remove("Масло - 90 грн");
        cout << "Товар виддалено! \n";
        cout << "Оновлений список товарів! \n";
        for (string item : items) {
        ii++;
        cout << ii << ". " << item << "\n";
    }
    }else{
        cout << "Невірний товар";
    }
return 0;
}
int returned(list<string>& items, int& bal, int& milk, int& bread, int& butter, int& milk_user, int& bread_user, int& butter_user){
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
    if(choose_item == 1){
    if(count<=milk_user){
        bal+=(90*count);
        milk_user-=count;
        milk+=count;
        cout << "Успішне повернення! \n Ваш баланс: " + bal;
    }else{
        cout << "Недостатньо товару! \n Ваш баланс: " + bal;
    }
    } else if(choose_item == 2){
        if(count<=bread){
        bal-=(20*count);
        bread_user+=count;
        bread-=count;
        cout << "Карта чи готівка? \n";
        cout << "Пакет потрібний? \n";
        cout << "Дякую за покупку! \n Ваш баланс: " + bal;
        }else{
        cout << "Недостатньо товару! \n Ваш баланс: " + bal;
    }
    } else if(choose_item == 3){
        if(count<=bread){
        bal-=(90*count);
        butter_user+=1;
        butter-=count;
        cout << "Карта чи готівка? \n";
        cout << "Пакет потрібний? \n";
        cout << "Дякую за покупку! \n Ваш баланс: " + bal;
        }else{
        cout << "Недостатньо товару! \n Ваш баланс: " + bal;
    }
    }else{
        cout << "Невірний товар";
    }
    return 0;
}