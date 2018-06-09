//
// Created by Water on 2018/6/9.
//

#include <iostream>
#include <vector>
#include <string>
#include <boost/program_options.hpp>
namespace bpo = boost::program_options;

int main(int argc, char const *argv[])
{
    std::vector<std::string> v_para;
    std::string port;
    int baud = 0;
    int timeout = 0;
    bpo::options_description opt("all options");

    opt.add_options()
            ("v_para,v", bpo::value<std::vector<std::string> >()->multitoken(), "Serial v_para")
            ("port,p", bpo::value<std::string>(&port)->default_value("COM1"), "Serial Port")
            ("baud,b", bpo::value<int>(&baud)->default_value(115200), "Serial Baud")
            ("timeout,t", bpo::value<int>(&timeout)->default_value(5000), "Timeout")
            ("help", "a demo ( default value )");

    bpo::variables_map vm;

    try{
        bpo::store(parse_command_line(argc, argv, opt), vm);
    }
    catch(...){
        std::cout << "undefined option！\n";
        return 0;
    }

    bpo::notify(vm);

    if(vm.count("help") ){
        std::cout << opt << std::endl;
        return 0;
    }
    if(vm.count("v_para") ){
        std::cout << "v_para：";
        for(auto& str : vm["v_para"].as<std::vector<std::string> >() )
            std::cout << str << " ";
        std::cout << std::endl;
    }
    std::cout << "port:" << port << std::endl;
    std::cout << "baud:" << baud << std::endl;
    std::cout << "timeout:" << timeout << std::endl;
    return 0;
}
