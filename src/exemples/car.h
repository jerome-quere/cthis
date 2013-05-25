/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <contact@jeromequere.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return,
 * ----------------------------------------------------------------------------
 */

#ifndef __CAR_H_
#define __CAR_H_

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdio.h>

typedef struct
{
  void (*delete)();
  int (*getSpeed)();
  void (*speedUp)(int speed);
  void (*slowDown)(int speed);

  int	speed;
}	Car;

Car* car_new();
void car_init(Car*);
Car* car_alloc();

#endif
