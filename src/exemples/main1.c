/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <contact@jeromequere.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return,
 * ----------------------------------------------------------------------------
 */

#include "car.h"

int main()
{
  Car* car;

  car = car_new();
  printf("Car Speed: %d\n", car->getSpeed());
  car->speedUp(50);
  printf("Car Speed: %d\n", car->getSpeed());
  car->slowDown(20);
  printf("Car Speed: %d\n", car->getSpeed());
  car->delete();
  return (0);
}
