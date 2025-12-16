#ifndef _COMMON_STRING_H
#define _COMMON_STRING_H


#include <string.h>


class CommonString {
  private:
    char *str;
    int size;

  public:
    CommonString() {
        size = 0;
    }

    CommonString (const char* str_in) {

        if (str_in == nullptr)
            return;

        size = strlen(str_in);

        //if (size == 0)
        //    return;

        str = new char [size+1];

        strcpy(str, str_in);
    }

    ~CommonString(){
        if (size)
            delete[] str;
        size = 0;
    }

    bool operator== (const CommonString &str) {
        return ( str.size == this->size && strcmp(str.str, this->str) == 0 );
    }

    CommonString (const CommonString &obj) {
        if (obj.size == 0)
        {
            this->size = 0;
            this->str = nullptr;
            return;
        }

        this->size = obj.size;
        this->str = new char [this->size + 1];
        strcpy(str, obj.str);
    }


    CommonString& operator= (const CommonString &obj) {
        if (this == &obj)
            return (*this);

        this->size = obj.size;
        this->str = new char [this->size + 1];
        strcpy(str, obj.str);

        return (*this);
    }

};


#endif


