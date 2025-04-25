#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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


enum MealType { BREAKFAST, LUNCH, DINNER, SNACK };

class Meal {
    int meal_id;
    string name;
    float price;
    MealType meal_type;
    vector <string> side_items;

public:
    Meal (int id, const string &meal_name, float meal_price, MealType type) {
        meal_id = id;
        name = meal_name;
        price = meal_price;
        meal_type = type;
    }

    void set_price (float new_price) {
        if (new_price > 0)
            price = new_price;
        else
            cout << " Invalid price! " << endl;
    }
    void set_meal_type (MealType new_type) { meal_type = new_tupe; }

    int get_meal_id () const { return meal_id; }
    string gat_name () const { return name; }
    float gat_price () const { return price; }
    MealType get_meal_type () const { return meal_type; }
    vector <string> get_side_items () const { return side_items; }

    void add_side_item (const string &item) { side_items.push_back(item); }

    void print () const {
        cout << " Meal ID: " << meal_id
             << "\n Name: " << name
             << "\n Price: " << price
             << "\n Type: " << (meal_type == BREAKFAST ? "Breakfast" :
                                meal_type == LUNCH ? "Lunch" :
                                meal_type == DINNER ? "Dinner" : "snack")
             << "\n Side Item: ";
        for (const auto& item : side_items) {
            cout << item << ", ";
        }
        cout << endl;
    }
};


enum ReservationStatus { SUCCESS, CANCELLED, FAILD };

class Reservation {
    int reservation_id;
    int student_id;
    int meal_id;
    int hall_id;
    time_t created_at;
    ReservationStatus status;

public:
    Reservation (int res_id, int s_id, int m_id, int h_id) : reservation_id(res_id), student_id(s_id), meal_id(m_id), hall_id(h_id), status(SUCCESS) {
        created_at = time(0);
    }

    void set_student_id (int s_id) { student_id = s_id; }
    void set_meal_id (int m_id) { meal_id = m_id; }
    void set_hall_id (int h_id) { hall_id = h_id; }
    void set_status (ReservationStatus new_statuse) { status = new_status; }

    int get_student_id () const { return student_id; }
    int get_meal_id () const { return meal_id; }
    int get_hall_id () const { return hall_id; }
    time_t get_created_at () const { return created_at; }
    ReservationStatus get_status () const { return status; }

    void cancel() {
        if (status = CANCELLED) {
            cout << " This reservation has already been cancelled! " << endl;
        } else {
            status = CANCELLED;
            cout << " Reservation cancelled sucessfully. " << endl;
        }
    }
    void print () const {
        cout << " Reservation ID: " << reservation_id
             << "\n Student ID: " << student_id
             << "\n Meal ID: " << meal_id
             << "\n Dining Hall ID: " << hall_id
             << "\n Created At: " << ctime(&created_at)
             << "\n Status: " << (status == SUCCESS ? "SUCCESS" : status == CANCELLED ? "CANCELLD" : "FAILD" ) << endl;
    }
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
        cout << " ( Invalid balance amout! ) " << endl; }

void Student :: set_email (string StudentEmail) {
    cout << " Please enter your Gmail (like: reza.abbasi92@gmail.com) " << endl;
    cin >> StudentEmail;

    while (1) {
        int n = StudentEmail.length();
        for (int i = 0; i < n; i++) {
            if ( (StudentEmail[i] >= 'a') || (StudentEmail[i] =< 'z') ||
                 (StudentEmail[i] >= 'A') || (StudentEmail[i] =< 'Z') ||
                 ((StudentEmail[i] >= 0) && (StudentEmail[i] =< 9)) ||
                 (StudentEmail[i]== '@') || (StudentEmail[i] == '.' ) ) {
               set_email(StudentEmail); }
            else
               cout <<  " (Email is not true!) Please enter a true Email: ";
               cin >> StudentEmail; }
    }
}
void :: Student :: set_is_active (bool isactive) {
    is_active = isactive; }

void Student :: print () const {
    cout << "- ID: " << student_id << "\n - Name: " << name << "\n - Balance: " << balance << endl;
}


