//
// Created by chorm on 2020-05-03.
//

int write(int fd,const void* buf,unsigned long size);


#define pwrite(str) write(1,str,sizeof(str))

int main(int argc,char** argv,char** envp){
    pwrite("Hello World");
}