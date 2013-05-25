/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <contact@jeromequere.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return,
 * ----------------------------------------------------------------------------
 */

#define _ISOC11_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "unistd.h"

#define CTHIS_THIS_FLAG (void*)0x4242424242424242
#define CTHIS_METHOD_FLAG (void*)0x4242424242424243

static void* cthis_template0p()
{
  void* this = CTHIS_THIS_FLAG;
  void* (*f)(void*) = CTHIS_METHOD_FLAG;
  return f(this);
}

static void* cthis_template1p(void* p1)
{
  void* this = CTHIS_THIS_FLAG;
  void* (*f)(void*, void*) = CTHIS_METHOD_FLAG;
  return f(this, p1);
}

static void* cthis_template2p(void *p1, void* p2)
{
  void* this = CTHIS_THIS_FLAG;
  void* (*f)(void*, void*, void*) = CTHIS_METHOD_FLAG;
  return f(this, p1, p2);
}

void cthis_replaceFlags(char* ptr, size_t s, void* search, void* replace)
{
  size_t i;
  for (i = 0 ; i <  s - sizeof(ptr) ; i++)
    {
      if (*((void**)(ptr + i)) == search)
	{
	  *((void**)(ptr + i)) = replace;
	  break;
	}
    }
}

static void* cthis_bind__(void* this, void* method, void* tpl1, void* tpl2)
{
  int pagesize = getpagesize();
  size_t size = ((size_t)(tpl2) - (size_t)(tpl1));
  void* text;

  text = aligned_alloc(pagesize, (size / pagesize + 1) * pagesize);
  memcpy(text, tpl1, size);
  mprotect(text, size, PROT_READ | PROT_EXEC | PROT_WRITE);
  cthis_replaceFlags(text, size, CTHIS_THIS_FLAG, this);
  cthis_replaceFlags(text, size, CTHIS_METHOD_FLAG, method);
  return (text);
}

void* cthis_bind0p(void* this, void* method)
{
  return (cthis_bind__(this, method, &cthis_template0p, &cthis_template1p));
}

void* cthis_bind1p(void* this, void* method)
{
  return (cthis_bind__(this, method, &cthis_template1p, &cthis_template2p));
}
