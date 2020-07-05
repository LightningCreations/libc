//
// Created by chorm on 2020-05-03.
//

#include <unistd.h>


int main(int argc,char** argv,char** envp){
    write(1,"Hello World\n",sizeof("Hello World\n"));
}