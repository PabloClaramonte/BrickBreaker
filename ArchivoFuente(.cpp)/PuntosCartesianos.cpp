#include "PuntosCartesianos.h"
#include <math.h>


PUNTOSCARTESIANOS::~PUNTOSCARTESIANOS()
{

}
PUNTOSCARTESIANOS::PUNTOSCARTESIANOS(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}
float PUNTOSCARTESIANOS::Modulo()
{
    return (float)sqrt(X * X + Z * Z);
}
PUNTOSCARTESIANOS PUNTOSCARTESIANOS::Unitario()
{
    PUNTOSCARTESIANOS retorno(X, Z);
    float mod = Modulo();
    if (mod > 0.00001)
    {
        retorno.X /= mod;
        retorno.Z /= mod;
    }
    return retorno;
}
PUNTOSCARTESIANOS PUNTOSCARTESIANOS::operator - (PUNTOSCARTESIANOS& v)
{
    PUNTOSCARTESIANOS res;
    res.X = X - v.X;
    res.Z = Z - v.Z;
    return res;
}
PUNTOSCARTESIANOS PUNTOSCARTESIANOS::operator + (PUNTOSCARTESIANOS& v)
{
    PUNTOSCARTESIANOS res;
    res.X = X + v.X;
    res.Z = Z + v.Z;
    return res;
}
float PUNTOSCARTESIANOS::operator *(PUNTOSCARTESIANOS& v)
{
    PUNTOSCARTESIANOS res;
    float escalar;

    res.X = X * v.X;
    res.Z = Z * v.Z;

    escalar = res.X + res.Z;
    return escalar;
}

PUNTOSCARTESIANOS PUNTOSCARTESIANOS::operator *(float v)
{
    PUNTOSCARTESIANOS res;
    res.X = v * X;
    res.Z = v * Z;
    return res;
}
