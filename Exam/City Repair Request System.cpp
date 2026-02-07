#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;
int read();
int write();
list<string> reports;
int id = 0;
int critical_count = 0;
int reports_count = 0;
class request {
public:
    int request_id;
    string area;
    string type;
    int days;
    bool critical;
};
int main() {
    string first_ext;
    cout << "Vuberit diyu: \n";
    cout << "1. Dodatu scargu \n";
    cout << "2. Vuvestu scargu \n";
    cout << "3. Insha informacia \n";
    cout << "Vedit nomer dii: \n";
    cin >> first_ext;
    if (first_ext == "1") {
        write();
    }
    else if (first_ext == "2") {
        read();
    }
    else if (first_ext == "3") {
        cout << reports_count + " - загальна к-сть скарг ";
        cout << critical_count + " - загальна к-сть критичних скарг ";
    }
}
int read() {
    string report;
    ifstream file("report.txt");
    if (!file.is_open()) {
        return 1;
    }
    try {
        while (getline(file, report)) {
            reports.push_front(report);
            cout << report << endl;
        }
    }
    catch (int code) {
        cout << "Error code: " + code;
        main();
    }
    file.close();
    main();
    return 0;
}
int write() {
    request new_request;
    string report;
    ofstream file("report.txt", ios::app);
    if (!file.is_open()) {
        return 1;
    }
    new_request.request_id = id+=1;
    reports_count+=1;
    cout << "Vedit rayon: ";
    cin >> new_request.area;
    cout << "Vedit tup priblemu (road / light / bench): ";
    cin >> new_request.type;
    cout << "Vedit skilki dniv verishuyt problemu: ";
    cin >> new_request.days;
    if (new_request.days >= 3) {
        new_request.critical = true;
        critical_count++;
    }
    else {
        new_request.critical = false;
    }
    file << to_string(new_request.request_id) + "; ";
    file << new_request.area + "; ";
    file << new_request.type + "; ";
    file << to_string(new_request.days) + "; ";
    if (new_request.critical) {
        file << "critical; \n";
    }
    else {
        file << "non_critical; \n";
    }
    
    
    file.close();
    main();
    return 0;
}

