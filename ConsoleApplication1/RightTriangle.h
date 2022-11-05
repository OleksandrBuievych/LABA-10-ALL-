#pragma once
#include "Triangle.h"
class RightTriangle : public Triangle {
public: 
    double kyt_a, kyt_b, kyt_c;

    RightTriangle() : Triangle(){
    storona_a = 0;
    storona_b = 0;
    storona_c = 0;
        a1 = 0;
        a2 = 0;
        b1 = 0;
        b2 = 0;
        c1 = 0;
        c2 = 0;
        med_AB = 0;
        med_BC = 0;
        med_AC = 0;
    }
    RightTriangle(double a, double b, double c, double a1, double a2, double b1, double b2, double c1, double c2, double med_AB, double med_BC, double med_AC) : Triangle(storona_a, storona_b, storona_c, a1, a2, b1, b2, c1, c2, med_AB, med_BC, med_AC) {}
    
    bool is_possibleRight() {
        
        kyt_a = 180/pi * (acos((storona_a * storona_a - storona_b * storona_b - storona_c * storona_c) / (-2 * storona_b * storona_c)));
        kyt_b = 180 / pi * ( asin((storona_b * sin((acos((storona_a * storona_a - storona_b * storona_b - storona_c * storona_c) / (-2 * storona_b * storona_c))))) / storona_a));
        kyt_c = 180 - (kyt_a+ kyt_b);
        if (kyt_a == 90 or kyt_b == 90 or kyt_c == 90) {
            cout << "Так, це прямокутний трикутник" << endl;
            return true;
        }
        return false;

    }

    void inscribed_circle() {
       
        float radius;
        if (kyt_a == 0) {
            radius = (storona_a + storona_c - storona_b) / 2;
            cout << "Радіус вписаного кола: " << radius << endl;
        }
        else if (kyt_b == 0) {
            radius = (storona_a + storona_b - storona_c) / 2;
            cout << "Радіус вписаного кола: " << radius << endl;
        }
        else if (kyt_c == 0) {
            radius = (storona_b + storona_c - storona_a) / 2;
            cout << "Радіус вписаного кола: " << radius << endl;
        }

    }
    void circumscribed_circle() {
        kyt_a = cos((pow(storona_b, 2) + pow(storona_c, 2) - pow(storona_a, 2)) / (2 * storona_b * storona_c));
        kyt_b = cos((pow(storona_a, 2) + pow(storona_c, 2) - pow(storona_b, 2)) / (2 * storona_a * storona_c));
        kyt_c = -1 - (kyt_b + kyt_a);
        float radius;
        if (kyt_a == 0) {
            radius = med_BC;
            cout << "Радіус описаного кола: " << radius << endl;
        }
        else if (kyt_b == 0) {
            radius = med_AC;
            cout << "Радіус описаного кола: " << radius << endl;
        }
        else if (kyt_c == 0) {
            radius = med_AB;
            cout << "Радіус описаного кола: " << radius << endl;
        }
    }
};
