#include <iostream>
#include <vector>
#include <string>

// Abstract base class
class Contact {
public:
    std::string name;
    virtual ~Contact() {}
    virtual void displayContact() const = 0;
};

// Derived classes
class Friend : public Contact {
public:
    std::string dateOfBirth;
    std::string phoneNumber;
    std::string address;

    void displayContact() const override {
        std::cout << "Friend: " << name << ", DOB: " << dateOfBirth << ", Phone: " << phoneNumber << ", Address: " << address << std::endl;
    }
};

class Acquaintance : public Contact {
public:
    std::string phoneNumber;

    void displayContact() const override {
        std::cout << "Acquaintance: " << name << ", Phone: " << phoneNumber << std::endl;
    }
};

class Colleague : public Contact {
public:
    std::string phoneNumber;
    std::string company;
    std::string address;

    void displayContact() const override {
        std::cout << "Colleague: " << name << ", Phone: " << phoneNumber << ", Company: " << company << ", Address: " << address << std::endl;
    }
};

// AddressBook class
class AddressBook {
private:
    std::vector<Contact*> contacts;

public:
    void addContact(Contact* c) {
        contacts.push_back(c);
    }

    Contact* searchContact(const std::string& name) {
        for (auto& c : contacts) {
            if (c->name == name)
                return c;
        }
        return nullptr;
    }

    bool deleteContact(const std::string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if ((*it)->name == name) {
                delete* it;
                contacts.erase(it);
                return true;
            }
        }
        return false;
    }

    void listFriends() {
        for (auto& c : contacts) {
            Friend* fr = dynamic_cast<Friend*>(c);
            if (fr) {
                fr->displayContact();
            }
        }
    }
};

int main() {
    AddressBook ab;
    Friend* f = new Friend{ "Alice", "1990-01-01", "1234567890", "123 Wonderland" };
    ab.addContact(f);
    ab.listFriends();

    return 0;
}
