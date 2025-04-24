#include <iostream>
using namespace std;

class student {
    string name;
    string email;
    int user_id;
    string student_id;
    float balance;
    bool is_active;

    public:

        void set_student_id (string);
        void set_user_id (int);
        void set_name (string);
        void set_email (string);
        void set_balance (float);
        void set_is_active (bool);

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

};
