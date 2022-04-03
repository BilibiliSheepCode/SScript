#ifndef S_String_H
#define S_String_H

#include"SClass.h"
#include"SCommand.h"

typedef struct _String{
    struct _String class ahead,class next;
    char chr;
} String;

String class ClassBuild_String(void){
    String class string = (String class) malloc(sizeof(String));
    string->ahead = nullclass;
    string->next = nullclass;
    string->chr = (char) 0;
    return string;
}

String class ClassBuild_String_Full(char chr,String class ahead,String class next){
    String class string = (String class) malloc(sizeof(String));
    string->ahead = ahead;
    string->next = next;
    string->chr = chr;
    return string;
}

String class ClassBuild_String_ValueLess(String class ahead,String class next){
    String class string = (String class) malloc(sizeof(String));
    string->ahead = ahead;
    string->next = next;
    string->chr = (char) 0;
    return string;
}

void ClassFree_String(String class string){
    String class temp;
    while(string->ahead != nullclass){
        string = string->ahead;
    }
    temp = string;
    while(string->next != nullclass){
        string = string->next;
        free(temp);
        temp = string;
    }
    free(temp);
    return;
}

unsigned long long String_getSize(String class string){
    unsigned long long size = 0;
    while(string->ahead != nullclass){
        size++;
        string = string->ahead;
    }
    while(string->next != nullclass){
        size++;
        string = string->next;
    }
    return ++size;
}

String class String_getFirstElement(String class string){
    while(string->ahead != nullclass){
        string = string->ahead;
    }
    return string;
}

String class String_getLastElement(String class string){
    while(string->next != nullclass){
        string = string->next;
    }
    return string;
}

char String_indexOf(String class string,unsigned long long index){
    if(index > String_getSize(string) - 1){
        return (char) 0;
    }
    string = String_getFirstElement(string);
    loop(index,string = string->next)
    return string->chr;
}

void String_addElement(String class string,char chr){
    string = String_getLastElement(string);
    string->next = ClassBuild_String_Full(chr,string,nullclass);
    return;
}

void String_removeElement(String class string){
    string = String_getLastElement(string);
    if(string->ahead != nullclass){
        string->ahead->next = nullclass;
    }
    free(string);
    return;
}

void String_insertElement(String class string,char chr,unsigned long long index){
    if(index > String_getSize(string)){
        return;
    }
    if(index == String_getSize(string)){
        String_addElement(string,chr);
        return;
    }
    string = String_getFirstElement(string);
    loop(index,string = string->next)
    if(string->ahead == nullclass){
        string->ahead = ClassBuild_String_Full(chr,nullclass,string);
        return;
    }
    string->ahead->next = ClassBuild_String_Full(chr,string->ahead,string);
    string->ahead = string->ahead->next;
    return;
}

void String_deleteElement(String class string,unsigned long long index){
    if(index > String_getSize(string) - 1){
        return;
    }
    string = String_getFirstElement(string);
    loop(index,string = string->next)
    if(string->ahead != nullclass){
        string->ahead->next = string->next;
    }
    if(string->next != nullclass){
        string->next->ahead = string->ahead;
    }
    free(string);
}

void String_out(String class string){
    String class temp = String_getFirstElement(string);
    if(temp == nullclass){
        return;
    }else{
        while(temp->next != nullclass){
            putchar((int) temp->chr);
            temp = temp->next;
        }
        putchar((int) temp->chr);
    }
    return;
}

void String_concat(String class string1,String class string2){
    string2 = String_getFirstElement(string1);
    string1 = String_getLastElement(string2);
    string1->next = string2;
    string2->ahead = string1;
}


#endif