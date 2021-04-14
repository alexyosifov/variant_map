#include <iomanip>
#include <unordered_map>
#include <variant>
#include <iostream>
#include <list>
#include <optional>
#include "enums.h"
#include "container.h"

int main(){
    variant_container container;

    std::cout << "== Before init ==\n";
    container.printall();

    container.init<t_e_parameters>(t_e_parameters::max_params);
    container.init<t_e_another_parameters>(t_e_another_parameters::max_params_);

    std::cout << "== After init ==\n";
    container.printall();
    std::cout << std::endl;

    container.setValue(param1, "Parameter 1");
    container.setValue(param2, 4);
    container.setValue(param4, 4.5);

    std::cout << "== After setValue ==\n";
    container.printall();
    std::cout << std::endl;

    std::cout << "== Lookup test ==\n";

    if(container.lookup(param1)){
        std::cout << e2str(param1) << ": " << container.getValue<std::string>(param1) << std::endl;
    } else {
        std::cout << e2str(param1) << ": has no value\n";
    }

    if(container.lookup(param2)){
        std::cout << e2str(param2) << ": " << container.getValue<int>(param2) << std::endl;
       // auto var = container.getval(param2);
     //   std::cout << var << std::endl;
    } else {
        std::cout << e2str(param2) << ": has no value\n";
    }

    if(container.lookup(param3)){
        std::cout << e2str(param3) << ": " << container.getValue<int>(param3) << std::endl;
    } else {
        std::cout << e2str(param3) << ": has no value\n";
    }

    if(container.lookup(param4)){
        std::cout << e2str(param4) << ": " << container.getValue<double>(param4) << std::endl;
    } else {
        std::cout << e2str(param4) << ": has no value\n";
    }

    if(container.lookup(param3_)){
        std::cout << e2str(param3_) << ": " << container.getValue<double>(param3_) << std::endl;
    } else {
        std::cout << e2str(param3_) << ": has no value\n";
    }

    return 0;
}