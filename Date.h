#ifndef DATE_CPP
#define DATE_CPP

class Date {
private:
    // member variables:
    int year;
    int month;
    int day;

public:
    // constructors:
    Date();
    Date(int y, int m, int d);

    // operator overloading:
    bool operator < (Date const &obj);
    bool operator > (Date const &obj);
    bool operator == (Date const &obj);
};

#endif
