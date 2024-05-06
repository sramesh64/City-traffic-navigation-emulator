#include <iostream>
#include <fstream>

#include <cfloat>
#include <cmath>
#include "GraphClass.hpp"
#include "IllegalException.hpp"


//if A=0 dont do dijkstra, skip. test this case
//cross out gpt
//TEST LOAD, UPDATE functions



int main(){

    graph* city = new graph;


    while(1){
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "LOAD") { //ANDREW
            std::string file;
            std::cin >> file;
            std::fstream fin(file.c_str());

            city -> load(fin);

            std::cout << "success" << std::endl;
        }

        else if (cmd == "INSERT"){
            int a, b;
            double d, s;

            std:: cin >> a >> b >> d >> s;
            try {
                if (!city->insert(a, b, d, s)) {

                    throw illegal_exception();

                } else {
                    std::cout << "success\n";
                }
            } catch (illegal_exception ie) {
                std::cout << ie.what();
            }
        }

        else if(cmd == "PRINT"){
            int a;
            std:: cin >> a;

            try {
                if (a <= 0 || a > 500000) {

                    throw illegal_exception();

                } else {
                    if(city -> print(a)){
                        std:: cout << "\n";
                    }
                    else{
                        std:: cout << "failure\n";
                    }
                }
            } catch (illegal_exception ie) {
                std::cout << ie.what();
            }
            
        }

        else if(cmd == "DELETE"){
            int a;
            std:: cin >> a;

            try {
                if (a <= 0 || a > 500000) {

                    throw illegal_exception();

                } else {
                    if(city -> delete_vertex(a)) std::cout << "success\n";

                    else std::cout << "failure\n";
                }
            } catch (illegal_exception ie) {
                std::cout << ie.what();
            }

        }

        else if(cmd == "PATH"){
            int a, b;
            std::cin >> a >> b;
            
            try {
                if (a <= 0 || a > 500000 || b <= 0 || b > 500000) {

                    throw illegal_exception();

                } else {
                    if(city -> path(a, b)) std::cout << "\n";
                    else std::cout << "failure\n";
                }
            } catch (illegal_exception ie) {
                std::cout << ie.what();
            }

        }

        else if(cmd == "TRAFFIC"){
            int a, b;
            double adj_factor;

            std:: cin >> a >> b >> adj_factor;
            try {
                if (a <= 0 || a > 500000 || b <= 0 || b > 500000) {

                    throw illegal_exception();

                } else {
                    if(city -> traffic(a, b, adj_factor)) std::cout << "success\n";
                    else std::cout << "failure\n";
                }
            } catch (illegal_exception ie) {
                std::cout << ie.what();
            }
        }

        else if(cmd == "UPDATE"){
            std::string file;
            std::cin >> file;
            std::fstream fin(file.c_str());

            if(city -> update(fin)) std:: cout << "success\n";
            else std::cout << "failure\n";

        }

        else if(cmd == "LOWEST"){

            int a, b;
            std:: cin >> a >> b;
            try {
                if (a <= 0 || a > 500000 || b <= 0 || b > 500000) {

                    throw illegal_exception();

                } else {

                    city -> lowest(a, b);

                }
            } catch (illegal_exception ie) {
                std::cout << ie.what();
            }
            

        }

        else{
            delete city;
            break;
        }



    }
    
}