#ifndef S_CLASS_H
#define S_CLASS_H

#include<stdio.h>
#include<stdlib.h>

#define nullclass (-1)

#define new(C) (ClassBuild_ ## C())
#define delete(C,c) (ClassFree_ ## C(c))
#define class *



#endif