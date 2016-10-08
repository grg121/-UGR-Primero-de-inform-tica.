#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415927;

bool SonIguales(double uno, double otro){
    return abs(uno-otro) <= 1e-6;
}

bool Positive(double value){
    if (value > 0 ) return true ;
    else return false ;
}

/////////////////////////////////////////////////////////////////////////


class Point2D{

private:

    double x ;
    double y ;

public:

    Point2D()
        : x(0), y(0){
    }

    Point2D(double formal_x, double formal_y)
        : x(formal_x), y(formal_y){
    }

    double Getx(){
        return x ;
    }

    double Gety(){
        return y ;
    }

    void SetCoordinates(double formal_x, double formal_y){
        x = formal_x ;
        y = formal_y ;
    }

    bool similar_to(Point2D another_point){
        return (SonIguales(x, another_point.Getx()) && SonIguales(y, another_point.Gety())) ;
    }

    void Show(){
        cout << " (" << x << "," << y << ") " ;
    }

    };


/////////////////////////////////////////////////////////////////////////////////

class Segment2D{

private:

    Point2D starting_point ;

    Point2D end_point      ;

public:

    Segment2D()
        :starting_point(0,0),
         end_point(2,2){
    }

    Segment2D(Point2D f_start, Point2D f_end)
        /*:starting_point(f_start),
         end_point(f_end)*/{
         starting_point = f_start;
         end_point = f_end ;
    }

    void Show(){
        starting_point.Show() ;
        cout << " to " ;
        end_point.Show() ;
    }

    double Length(){
        double length = sqrt(
            pow(starting_point.Getx() * end_point.Getx(),2)
            +
            pow(starting_point.Gety() * end_point.Gety(),2)
            ) ;
            return length ;
    }


};


/////////////////////////////////

class Circumference{

    private:

        Point2D center ;

        double radius ;

    public:

        Circumference()
            :center(0,0),
             radius(1){
        }

        Circumference(double _radius)
            :center(0,0){
            SetRadius(_radius) ;
        }

        Circumference(Point2D _center, double _radius)
            :center(_center){
            SetRadius(_radius);
        }

        Point2D GetCenter(){
            return center ;
        }

        double GetRadius(){
            return radius ;
        }

        void ShowCenter(){
            center.Show() ;
        }

        void SetRadius(double _radius){
        if(Positive(_radius))
        radius = _radius ;
        else
        radius = 5 ;
        }

};

////////////////////////////////////////777

class Square{

    private:

        Point2D lbcorner ; //left_below_corner

        double side ;

    public:

        Square(Point2D left_below_corner, double _side)
            :lbcorner(left_below_corner){
            SetSide(_side) ;
        }

        Square()
           :lbcorner(-1,-1),side(1){
        }

        void SetSide(double _side){
        if(Positive(_side))
            side = _side ;
        }

        double GetSide(){
            return side;
        }

        Point2D ShowCorner(){
            lbcorner.Show();
        }

        double GetArea(){
            double area = side*side ;
            return area ;
        }

        Point2D GetlbCorner(){
            return lbcorner ;
        }

        double GetPerimeter(){
            double perimeter = 4*side ;
            return perimeter;
        }

        double GetSideHalf(){
            return side/2 ;
        }

        Point2D GetCentralPoint(){
            Point2D center(lbcorner.Getx() + GetSideHalf(), lbcorner.Gety() + GetSideHalf()) ;
            return center ;
        }

        Circumference InscribedCircunference(){
            Circumference inscribed(GetCentralPoint(), GetSideHalf()) ;
            return inscribed ;
        }

        Circumference CircumscribedCircunference(){
            Segment2D center_lbcorner(GetCentralPoint(), GetlbCorner());
            Circumference circumscribed(GetCentralPoint(), center_lbcorner.Length());
            return circumscribed;
            }

        bool BiggerAreaThan(Square anothersquare){
            return GetArea() > anothersquare.GetArea() ;
        }

        double Getlbc_x(){
            return lbcorner.Getx() ;
        }

        double Getlbc_y(){
            return lbcorner.Gety() ;
        }

        bool Contain(Square another){
            return Getlbc_x() <= another.Getlbc_x() && another.Getlbc_x() + another.GetSide() <= Getlbc_x() + side
                   && Getlbc_y() <= another.Getlbc_y() && another.Getlbc_y() + another.GetSide() <= Getlbc_y() + side ;
        }



    };

int main(){



//creamos un punto de prueba.

Point2D home(2,2) ;
Point2D work      ;

cout << "Home is in: " ;

home.Show() ;

cout << "\nI work in: " ;
work.Show() ;

// Y segmentos de prueba.

cout << "\nEl camino de casa al trabajo es: \n" ;

Segment2D road(home, work) ;

road.Show() ;


//Pruebas circunferencias.

cout << "\nA continuación, circunferencias. \n" ;

Circumference circulico ;

cout << "El centro del circulico standar es: " ;

circulico.ShowCenter() ;

Circumference circulo(home, 10) ;

Circumference circular(9) ;

cout << "\n Radio de circular: " << circular.GetRadius() ;


// catando squares.


Point2D origin(0,0) ;

Point2D lbc2(1,2) ;

Square big(origin, 5) ;

Square small(lbc2,3) ;

cout << "\nComparamos las áreas de big y smalll: ";

if (big.BiggerAreaThan(small))
    cout << "Todo correcto." ;
else
    cout << "Nahhh" ;

cout << "\nComprobamos si big contiene a small: ";
if (big.Contain(small))
    cout << "efectiviwonder" ;
else
    cout << "niet. " ;








}

