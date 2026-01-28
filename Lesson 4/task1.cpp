#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int reading();
class Event{
public:
    string what_event;
    string when_event;
    string format_event;
    string where_event;
    string date_event;
};
int main(){
    Event new_event;
    
    ofstream file("event.txt");
    cout << "Sho za podiya: \n";
    cin >> new_event.what_event;
    cout << "Kolu  podiya: \n";
    cin >> new_event.when_event;
    cout << "Format podii: \n";
    cin >> new_event.format_event;
    cout << "De podiya: \n";
    cin >> new_event.where_event;
    cout << "Data podii: \n";
    cin >> new_event.date_event;
    if(!file.is_open()){
        return 1;
    }
    file << new_event.what_event + " \n";
    file << new_event.when_event + " \n";
    file << new_event.format_event + " \n";
    file << new_event.where_event + " \n";
    file << new_event.date_event + " \n";
    file.close();
    reading();
    return 0; 
}
int reading(){
    string event;
    ifstream file("event.txt");
      if(!file.is_open()){
        return 1;
    }

while (getline(file, event)){
        cout << event << endl;
}
    file.close();
    return 0;
}