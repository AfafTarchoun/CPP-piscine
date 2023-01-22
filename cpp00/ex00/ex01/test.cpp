#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Contact {
    private:
        string first_name;
        string last_name;
        string nickname;
        string phone_number;
        string darkest_secret;
    public:
        void set_first_name(string fname) {first_name = fname;}
        void set_last_name(string lname) {last_name = lname;}
        void set_nickname(string nick) {nickname = nick;}
        void set_phone_number(string phone) {phone_number = phone;}
        void set_darkest_secret(string secret) {darkest_secret = secret;}

        string get_first_name() {return first_name;}
        string get_last_name() {return last_name;}
        string get_nickname() {return nickname;}
        string get_phone_number() {return phone_number;}
        string get_darkest_secret() {return darkest_secret;}
};

class PhoneBook {
    private:
        Contact contacts[8];
        int current_index = 0;
    public:
        void add_contact(Contact contact) {
            if (current_index < 8) {
                contacts[current_index] = contact;
                current_index++;
            } else {
                for (int i = 0; i < 7; i++) {
                    contacts[i] = contacts[i+1];
                }
                contacts[7] = contact;
            }
        }

        void search_contact(int index) {
            if (index >=1 && index <= current_index) {
                Contact contact = contacts[index-1];
                cout << "First Name: " << contact.get_first_name() << endl;
                cout << "Last Name: " << contact.get_last_name() << endl;
                cout << "Nickname: " << contact.get_nickname() << endl;
                cout << "Phone Number: " << contact.get_phone_number() << endl;
                cout << "Darkest Secret: " << contact.get_darkest_secret() << endl;
            } else {
                cout << "Invalid index" << endl;
            }
        }

        void display_contacts() {
            cout << "Index | First Name | Last Name | Nickname" << endl;
            for (int i = 0; i < current_index; i++) {
                cout << right << setw(10) << i+1 << " | ";
                cout << right << setw(10) << truncate(contacts[i].get_first_name(),10) << " | ";
                cout << right << setw(10) << truncate(contacts[i].get_last_name(),10) << " | ";
                cout << right << setw(10) << truncate(contacts[i].get_nickname(),10) << endl;
            }
        }
};

string truncate(string str, int width) {
    if (str.length() > width) {
        return str.substr(0, width-1) + ".";
    }
    return str;
}

int main() {
    PhoneBook phonebook;
    string command;
    while (true) {
        cout << "Enter command (ADD, SEARCH, EXIT): ";
        cin >> command;
        if (command == "ADD") {
            Contact new_contact;
            cout << "Enter contact's first name: ";
            cin >> new_contact.first_name;
            cout << "Enter contact's last name: ";
            cin >> new_contact.last_name;
            cout << "Enter contact's nickname: ";
            cin >> new_contact.nickname;
            cout << "Enter contact's phone number: ";
            cin >> new_contact.phone_number;
            cout << "Enter contact's darkest secret: ";
            cin >> new_contact.darkest_secret;
            phonebook.add_contact(new_contact);
        } else if (command == "SEARCH") {
            phonebook.display_contacts();
            int index;
            cout << "Enter index of contact to display: ";
            cin >> index;
            phonebook.search_contact(index);
        } else if (command == "EXIT") {
            break;
        } else {
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}
