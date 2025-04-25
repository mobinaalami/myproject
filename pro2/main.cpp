#include <iostream>
#include <string.h>
using namespace std;

class DiningHall {
    int hall_id;
    string name;
    string address;
    int capacity; //zarfiyat

public:
    DiningHall(int id, const string &hall_name, const string &hall_address, int hall_capacity){
        hall_id = id;
        name = hall_name;
        address = hall_address;
        capacity = hall_capacity;
    }

    void setHall (int i) { hall_id = i; }
    void setName (string n) { name = n; }
    void setAddress (const string &new_address) { address = new_address; }
    void setCapacity (int c) { capacity = (c >= 0) ? c : 0; }

    int getHall () const { return hall_id; }
    string getName () const { return name; }
    string getAddress () const { return address; }
    int getCapacity () const { return capacity; }

    void print() const {
        cout << endl << " ( Dining Hall ) \n" << "- Hall ID: " << hall_id << "\n- name: " << name << "\n- address: " << address << "\n- capacity: " << capacity << endl; }
};


class Student {
    string name;
    string email;
    int user_id;
    string student_id;
    float balance;
    bool is_active;

    public:
        Student (string = " ", string = " ", int = 0, string = " ", float = 0.0, bool = true);

        void set_student_id (string);
        void set_user_id (int);
        void set_name (string);
        void set_email (string);
        void set_balance (float);
        void set_is_active (bool);

        Student (string n, string e, int uid, string sid, float b, bool act) {
        set_name (n);
        set_email (e);
        set_user_id (uid);
        set_student_id (sid);
        set_balance (b);
        set_is_active (act);
        }

        string get_student_id () const {
            return student_id; }
        int get_user_id () const {
            return user_id; }
        string get_name () const {
            return name; }
        string get_email () const {
            return email; }
        float get_balance () const {
            return balance; }
        bool get_is_active () const {
            return is_active; }

        void print () const;
};
void Student :: set_student_id (string id) {
    student_id = id; }

void Student :: set_user_id (int UserId){
    cout << " Please enter your User ID " << endl << " (it can be 14 numbers): ";
    cin >> UserId;
    while (1) {
    int n = UserId.length();//
       if (n >= 9 || n <= 14)
         user_id = UserId;
       else
         cout << " (User ID is not true!) Please enter a true User ID: ";
         cin >> UserId;
    }
}

void Student :: set_name (const string &StudentName) {
    name = StudentName; }

void Student :: set_balance (float StudentBalance) {
    if (SudentBalance >= 0.0)
        balance = SudentBalance;
    else
        cout << " ( Invalid balance amout ! ) " << endl; }

void Student :: set_email (string StudentEmail) {
    cout << " Please enter your gmaile (like: local-part@domain) " << endl;
    cin >> StudentEmail;

    if
        for (int i=0; i < )
}
void :: Student :: set_is_active (bool isactive) {
    is_active = isactive; }

void Student :: print () const {
    cout << "- ID: " << student_id << "\n - Name: " << name << "\n - Balance: " << balance << endl;
}


