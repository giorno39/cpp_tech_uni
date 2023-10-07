#include <iostream>
#include <math.h>
#include <string>
#include <limits.h>

class triangle{
    private:
        double a{}, b{}, c{};
    public:
        triangle();
        double face();
        void show(char *);
        ~triangle(){
            std::cout << "\nDestructing object triangle!\n";
        }
};

triangle::triangle() {
    do{
        std::cout << "\n\nEnter three values for the sides of triangle:\n";
        std::cin >> a >> b >> c;
    }while((a < 0) || (b < 0) || (c < 0) || (a + b < c) || (b + c < a) || (c + a < b));
}

void triangle::show(char *name){
    std::cout << "Sides of the triangle " << name << ":\n";
    std::cout << "a=" << a << ",b=" << b << ",c=" << c;
}

double triangle::face() {
    double p, s;
    p = (a + b + c) / 2;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}

class time{
    public:
        int hour, minutes, seconds;
        time();
        void show();
        void show_am_pm();
        ~time(){
            std::cout << "\nDestructing object time!\n";
        }
};

time::time(){
    do{
        std::cout << "\nEnter hours minutes and seconds\n";
        std::cin >> hour >> minutes >> seconds;
    }while((hour < 0 || hour > 23) || (minutes < 0 || minutes > 59) || (seconds < 0 || seconds > 59));
}

void time::show() {
    std::cout << "\nThe time is " << hour << ":" << minutes << ":" << seconds << ":\n";
}

void time::show_am_pm() {
    std::string time_value = "";
    if(hour < 12){
        time_value = "AM";
    }else{
        time_value = "PM";
    }
    std::cout << "\nThe time is " << hour << ":" << minutes << ":" << seconds << time_value << "\n";
}

class employee{
    private:
        int social_number;
        std::string name;
        int employment_years;
        std::string current_status;
        int salaries[5] = {200, 300, 400, 500, 600};
    public:
        employee();
        employee(std::string status);
        double avg_salary();
        int lowest_salary();
        void set_social_number(int num);
        int get_social_number();
        void set_name(std::string e_name);
        std::string get_name();
        void set_employment_years(int years);
        int get_employment_years();
        void set_current_status(std::string status);
        std::string get_current_status();

        ~employee(){
            std::cout << "\nDestructing object employee!\n";
        }
};

void employee::set_social_number(int num){
    social_number = num;
}
int employee::get_social_number(){
    return social_number;
}

void employee::set_name(std::string e_name) {
    name = e_name;
}
std::string employee::get_name() {
    return name;
}

void employee::set_employment_years(int years) {
    employment_years = years;
}
int employee::get_employment_years() {
    return employment_years;
}

void employee::set_current_status(std::string status) {
    current_status = status;
}
std::string employee::get_current_status() {
    return current_status;
}


employee::employee() {
    social_number = 0;
    employment_years = 0;
}

employee::employee(std::string status) {
    current_status = status;
}

double employee::avg_salary() {
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += salaries[i];
    }
    return sum/5;
}

int employee::lowest_salary() {
    int lowest = INT_MAX;
    for (int i = 0; i < 5; ++i) {
        if(salaries[i] < lowest){
            lowest = salaries[i];
        }
    }
    return lowest;
}

class Line{
    private:
        int len;
    public:
        Line(int num_of_dots);
        void draw();
        ~Line(){
            std::cout << "\nDestructing object Line!\n";
        }
};

Line::Line(int num_of_dots) {
    len = num_of_dots;
}

void Line::draw() {
    for (int i = 0; i < len; ++i) {
        std::cout << "*";
    }
    std::cout << "\n";
}





int main() {
//---------------------- ex. 0 ---------------------------- //
//    triangle t1;
//    t1.show("vasko");
//    double face_s;
//    face_s = t1.face();
//    std::cout << "\n" << face_s << "\n";
//---------------------- ex. 1 ---------------------------- //
//    class time t1;
//    t1.show();
//    t1.show_am_pm();
//---------------------- ex. 2 ---------------------------- //
//    employee e1;
//    double e_avg_sal = 0;
//    e_avg_sal = e1.avg_salary();
//    std::cout << e_avg_sal << "\n";
//    int e_lowest_salary = e1.lowest_salary();
//    std::cout << e_lowest_salary << "\n";
//    employee e2("Senior");
//    std::string curr_status = e2.get_current_status();
//    std::cout << curr_status << "\n";
//    e2.set_employment_years(3);
//    int emp2_years = e2.get_employment_years();
//    std::cout << emp2_years << "\n";
//---------------------- ex. 4 ---------------------------- //
    Line l1(5);
    l1.draw();
    Line *l2;
    l2 = &l1;
    l2->draw();
    return 0;
}