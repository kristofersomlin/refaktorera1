#include <math.h>
double multi(double x, double y){
    return x*y;
}
double res_tot(double r1, double r2, double r3){
    return 1/((1/r1) + (1/r2) + (1/r3));
}
double aktiv_eff(double u, double i, double cos){
    return u * i * cos;
}
double sken_3fas(double u, double i){
    return u * i * sqrt(3);
}
double aktiv_3fas(double u, double i, double cos){
    return u * i * sqrt(3) * cos;
}
