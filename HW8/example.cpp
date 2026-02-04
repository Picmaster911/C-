#include <boost/lambda/lambda.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <algorithm>

namespace pt = boost::property_tree;

int main()
{
    using MySeting = boost::property_tree::ptree;
    MySeting setings;
    boost::property_tree::read_json("setings.json", setings);
    int port = setings.get<int>("port");
    std::string ip = setings.get<std::string>("ip");
    
}