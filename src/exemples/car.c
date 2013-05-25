/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <contact@jeromequere.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return,
 * ----------------------------------------------------------------------------
 */

#include "cthis.h"
#include "car.h"

static void car_delete(Car* this)
{
  printf("Delete Car: %p\n", this);
  free(this->delete);
  free(this);
}

static int	car_getSpeed(Car* this)
{
  return this->speed;
}

static void	car_speedUp(Car* this, int speed)
{
  this->speed += speed;
}

static void	car_slowDown(Car* this, int speed)
{
  this->speed -= speed;
}

Car* car_alloc()
{
  return (malloc(1 * sizeof(Car)));
}

void car_init(Car* this)
{
  printf("Create new Car a %p\n", this);

  this->speed = 0;
  this->delete = cthis_bind0p(this, &car_delete);
  this->getSpeed = cthis_bind0p(this, &car_getSpeed);
  this->speedUp = cthis_bind1p(this, &car_speedUp);
  this->slowDown = cthis_bind1p(this, &car_slowDown);
}

Car*	car_new()
{
  Car*	car;

  car = car_alloc();
  car_init(car);
  return (car);
}
