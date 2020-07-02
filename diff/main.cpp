#include <stdexcept>
#include <iostream>
#include <fstream>
#include "diff.hpp"


int main(int argc, char* argv[]) try{

    if(argc !=3){
        std::cerr << "invalid command line arguments";
        return 1;
    }

    std::ifstream i_f1(argv[1]);
    if (!i_f1) throw std::invalid_argument("ERROR! File not found!");

    std::ifstream i_f2(argv[2]);
    if(!i_f2) throw std::invalid_argument("ERROR! File not found!");

    std::string str1,
                str2;
    diff::formater formater;
    while(i_f1||i_f2){
        std::getline(i_f1,str1);
        std::getline(i_f2,str2);
        if(str1!=str2){
            std::cout<<str1<<'\n';
            std::cout<<str2<<'\n';

            const std::size_t min = std::min(str1.size(), str2.size());
            for(std::size_t i=0; i<min; ++i){
                        formater(str1[i]==str2[i]);
            }

            formater(std::max(str1.size(),str2.size())-min);
            formater.print();
        }
        std::cout<<'\n';
    str1.clear();
    str2.clear();
    }


    return 0;
}
catch(const std::invalid_argument & e){

    std::cerr<<e.what()<<std::endl;
    return 1;
}
catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
    return 1;
}
