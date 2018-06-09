//
// Created by Water on 2018/6/9.
//

#include <iostream>
#include <string>
#include <boost/program_options.hpp>
namespace  bpo = boost::program_options;

int main(int argc, char const *argv[])
{
    bpo::options_description opts("all options");
    bpo::variables_map vm;

    opts.add_options()
            ("filename", bpo::value<std::string>(), "the file name which want to be found")
            ("help", "this is a program to find a specified file");

    try{
        bpo::store(bpo::parse_command_line(argc, argv, opts), vm);
    }
    catch(...){
        std::cout << "undefined option！\n";
        return 0;
    }

    if(vm.count("help") ){
        std::cout << opts << std::endl;
    }
    if(vm.count("filename") ){
        std::cout << "find " << vm["filename"].as<std::string>() << std::endl;
    }
    if(vm.empty() ){
        std::cout << "no options found \n";
    }
    return 0;
}
