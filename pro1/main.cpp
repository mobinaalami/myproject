#include<iostream>
#include<vector>
#include<ctime>
#include<string>
using namespace std ;



enum ReservationStatus { SUCCESS, CANCELLED, FAILED };


class Reservation {
private:
    int reservation_id;

    int student_id;
    int meal_id;
    int hall_id;
    time_t created_at;
    ReservationStatus status;

public:

Reservation(int res_id, int s_id, int m_id, int h_id)
        : reservation_id(res_id), student_id(s_id), meal_id(m_id), hall_id(h_id), status(SUCCESS) {
        created_at = time(0);
    }


    int get_reservation_id() const { return reservation_id; }
    int get_student_id() const { return student_id; }
    int get_meal_id() const { return meal_id; }
    int get_hall_id() const { return hall_id; }
    time_t get_created_at() const { return created_at; }
    ReservationStatus get_status() const { return status; }


    void set_student_id(int s_id) { student_id = s_id; }
    void set_meal_id(int m_id) { meal_id = m_id; }
    void set_hall_id(int h_id) { hall_id = h_id; }
    void set_status(ReservationStatus new_status) { status = new_status; }


    void cancel() {
        if (status == CANCELLED) {
            cout << "This reservation has already been cancelled!" << endl;
        } else {
            status = CANCELLED;
            cout << "Reservation cancelled successfully." << endl;
        }
    }


    void print() const {
        cout << "Reservation ID: " << reservation_id
             << "\nStudent ID: " << student_id
             << "\nMeal ID: " << meal_id
             << "\nDining Hall ID: " << hall_id
             << "\nCreated At: " << ctime(&created_at)
             << "\nStatus: " << (status == SUCCESS ? "SUCCESS" : status == CANCELLED ? "CANCELLED" : "FAILED") << endl;
    }};




    class student {
        private:
        int user_id;
        string student_id;
        string name;
        string email;
        float balance ;
        bool is_active;



        public:
        Student(int id, const string& student_name, const string& student_email, float student_balance)
            : user_id(id), name(student_name), email(student_email), balance(student_balance) { }

        int get_id() const { return user_id; }
        string get_name() const { return name; }
        string get_email() const { return email; }
        float get_balance() const { return balance; }

        void set_student_id(int id) { student_id = id; }
        void set_name(const string& student_name) { name = student_name; }
        void set_email(const string& student_email) { email = student_email; }
        void set_balance(float student_balance) {
           if (student_balance >= 0)
          balance = student_balance;
            else
            cout << "Invalid balance amount!" << endl ; }
         void print() const {
            cout << "ID: " << student_id << "\n Name: " << name << "\n Balance: " << balance  << endl;}

        bool reserve_meal(const Reservation& reservation);

        bool cancel_reservation(int reservation_id);



         };



    enum MealType { BREAKFAST, LUNCH, DINNER, SNACK };


class Meal {
    private:
        int meal_id;
        string name;
        float price;
        MealType meal_type;
        vector<string> side_items;


    public:

        Meal(int id, const string& meal_name, float meal_price, MealType type)
            : meal_id(id), name(meal_name), price(meal_price), meal_type(type) {

        }


        int get_meal_id() const { return meal_id;}
        string get_name() const { return name; }
        float get_price() const { return price; }
        MealType get_meal_type() const { return meal_type; }
        vector<string> get_side_items() const { return side_items; }

        void set_price(float new_price) {
            if (new_price > 0 )
                price = new_price;
            else
                cout << "Invalid price!" << endl;
        }

        void set_meal_type(MealType new_type) { meal_type = new_type; }

        void add_side_item(const string& item) { side_items.push_back(item); }

        void print() const {
            cout << "Meal ID: " << meal_id
                 << "\nName: " << name
                 << "\nPrice: " << price
                 << "\nType: " << (meal_type == BREAKFAST ? "Breakfast" :
                                  meal_type == LUNCH ? "Lunch" :
                                  meal_type == DINNER ? "Dinner" : "Snack")
                 << "\nSide Items: ";
            for (const auto& item : side_items) {
                cout << item << ", ";
            }
            cout << endl;
        }
};







class DiningHall {
private:
    int hall_id;
    string name;
    string address;
    int capacity;

    vector<Meal> meals;

public:

    DiningHall(int id, const string& hall_name, const string& hall_address, int hall_capacity )
        : hall_id(id), name(hall_name), address(hall_address), capacity(hall_capacity) {}


    int get_hall_id() const { return hall_id; }
    string get_name() const { return name; }
    string get_address() const { return address; }
    int get_capacity() const { return capacity; }



    void set_address(const string& new_address) { address = new_address; }
    void set_capacity(int new_capacity) { capacity = new_capacity; }

    void print() const {
        cout << "Dining Hall ID: " << hall_id << "\nName: " << name
             << "\nAddress: " << address << "\nCapacity: " << capacity
             << endl;
    }
};
