#include <stdio.h>

typedef struct Point
{
    double x;
    double y;
} Point;

typedef struct Triangle
{
    Point a;
    Point b;
    Point c;
} Triangle;

int Scan_Point(Point* a);
int Scan_Triangle(Triangle* abc);
int Is_point_inside_triangle (Triangle abc,Point o);



int main()
{
    Triangle abc;
    Point o;
    Scan_Triangle(&abc);
    Scan_Point(&o);

    if (Is_point_inside_triangle (abc, o))
        printf ("yes");
    else
        printf ("no");
}


int Scan_Point(Point* a)
{
    scanf ("%lf %lf", &(a->x), &(a->y));
    return 0;
}

int Scan_Triangle(Triangle* abc)
{
    Scan_Point(&(abc->a));
    Scan_Point(&(abc->b));
    Scan_Point(&(abc->c));
    return 0;
}

//вычисляет некоторые выражения, и если знаки выражений одинаковые, то значит точка внутри треугольника
int Is_point_inside_triangle (Triangle abc,Point o)
{
    int expr_1 = 0, expr_2 = 0, expr_3 = 0;
    expr_1 = (abc.a.x-o.x)*(abc.b.y-abc.a.y)-(abc.b.x-abc.a.x)*(abc.a.y-o.y);
    expr_2 = (abc.b.x-o.x)*(abc.c.y-abc.b.y)-(abc.c.x-abc.b.x)*(abc.b.y-o.y);
    expr_3 = (abc.c.x-o.x)*(abc.a.y-abc.c.y)-(abc.a.x-abc.c.x)*(abc.c.y-o.y);
    if (((expr_3 > 0) && (expr_2 > 0) && (expr_1 > 0)) || ((expr_3 < 0) && (expr_2 < 0) && (expr_1 < 0)))
        return 1;
    return 0;
}


