#include "point.h"
#include "auxiliary_functions.h"


Point::Point()
{
  for (int i = 0; i < n_coord; ++i)
    _coord[i] = 0.;
}



Point::Point(const double coordinates[])
{
  for (int i = 0; i < n_coord; ++i)
    _coord[i] = coordinates[i];
}



Point::Point(const double x_coord,
             const double y_coord,
             const double z_coord)
{
  _coord[0] = x_coord;
  if (n_coord > 1) _coord[1] = y_coord;
  if (n_coord > 2) _coord[2] = z_coord;
}



Point::Point(const Point &p)
{
  for (int i = 0; i < n_coord; ++i)
    _coord[i] = p._coord[i];
}



Point& Point::operator =(const Point &p)
{
  for (int i = 0; i < n_coord; ++i)
    _coord[i] = p._coord[i];
  return *this;
}



double Point::coord(unsigned int number) const
{
  expect(number < n_coord,
         "The number of coordinate is incorrect: " +
         d2s(number) + ". It should be in the range: [0, " +
         d2s(n_coord) + ")");

  return _coord[number];
}



void Point::coord(unsigned int number, double value)
{
  expect(number < n_coord,
         "The number of coordinate is incorrect: " +
         d2s(number) + ". It should be in the range: [0, " +
         d2s(n_coord) + ")");

  _coord[number] = value;
}