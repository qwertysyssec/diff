#ifndef UUID_459333E3_EEDE_42AF_9FD9_52263135206A
#define UUID_459333E3_EEDE_42AF_9FD9_52263135206A

#include <iostream>
#include <iomanip>

namespace diff {

class formater
{
public:

    void operator()(bool is_same){
       if(is_same==is_same_) ++w;
       else{
           print();
            is_same_=!is_same_;
            ++w;
       }
    }
    void operator()(std::size_t n){
        if(is_same_) {print(); is_same_=!is_same_;}
        w+=n;
        print();
    }

    void print(){
        if(w==0) return;
        if(is_same_)  std::cout<<std::setw(w)<<std::setfill(' ')<<' ';
        if(!is_same_) {if(w==1) std::cout<<'*';
                        else    std::cout<<'<'<<std::setw(w-1)<<std::setfill('-')<<'>';
                        }
        w=0;
        }


private:
    std::size_t w=0;
    bool is_same_=false;
};


}

#endif
