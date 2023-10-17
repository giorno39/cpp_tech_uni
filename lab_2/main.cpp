#include <iostream>


// ----------------------------ex1. ------------------------//

class rectangle{
    private:
        double width;
        double height;
    public:
        rectangle();
        double face();
        double face(double *p);
};

rectangle::rectangle(){
    std::cin >> width >> height;
}

double rectangle::face(){
    return width * height;
}

double rectangle::face(double *p){
    double pp = width + height;
    *p = pp;
    return width * height;
}
// ----------------------------ex2. ------------------------//
class truck;

class car {
int passengers;
int speed;
public:
car(int p, int s) { passengers = p; speed = s;}
double distance(int time, truck t, double *d);
};

class truck {
    int weight;
    int speed;
    public:
    truck(int w, int s) { weight = w; speed = s;}
    friend double car::distance(int time, truck t, double *d);
};

double car::distance(int time, truck t, double *d){
    double distance = 0;
    *d = time * t.speed;
    distance =  this->speed * time;
    return distance;

}

// ----------------------------ex3. ------------------------//

class stack{
    char alphabet[26];
public:
    void loadstack(int upper);
};

void stack::loadstack(int upper) {
    int count = 0;
    if (upper == 1) {
        for (int i = 'a'; i <= 'z'; ++i) {
            alphabet[count] = (char) i;
            count++;
        }
    } else {
        for (int i = 'A'; i <= 'Z'; ++i) {
            alphabet[count] = (char) i;
            count++;
        }
    }
    for (int i = 25; i >= 0; --i) {
        std::cout << alphabet[i] << " ";
    }
    std::cout << "\n";
}

// ----------------------------ex4. ------------------------//
class pr2;

class pr1 {
int printing;
public:
pr1() {printing = 0;}
 void set_print(int status) {printing = status;}
 friend bool inuse(pr1 printer1, pr2 printer2);
};

class pr2 {
int printing;
public:
pr2() {printing = 0;}
void set_print(int status) {printing = status;}
friend bool inuse(pr1 printer1, pr2 printer2);
};

bool inuse(pr1 printer1, pr2 printer2){
    if(printer1.printing or printer2.printing){
        std::cout << "The printer is accupied at the moment";
        return true;
    }
     std::cout << "The printer can be used";
     return false;
}

    int main() {
// ----------------------------ex1. ------------------------//
//    rectangle r1;
//    double s = 0;
//    s = r1.face();
//    std::cout << s << "\n";
//    double rp = 0;
//    s = r1.face(&rp);
//    std::cout << s << "\n" << rp;
//    return 0;
// ----------------------------ex2. ------------------------//
//    car c1(2, 20);
//    truck t1(10, 10);
//    double truck_distance;
//    double car_distance;
//    car_distance = c1.distance(10, t1, &truck_distance);
//    std::cout << truck_distance << "\n" << car_distance;
// ----------------------------ex3. ------------------------//
//stack s1;
//s1.loadstack(0);
//s1.loadstack(1);
//        return 0;
// ----------------------------ex4. ------------------------//
pr1 p1;
p1.set_print(1);
pr2 p2;
inuse(p1, p2);

}