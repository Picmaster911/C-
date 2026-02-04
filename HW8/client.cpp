#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

int main()
{
    try
    {
        boost::asio::io_context io;

        tcp::socket socket(io);
        tcp::resolver resolver(io);

        boost::asio::connect(
            socket,
            resolver.resolve("127.0.0.1", "5555")
        );

        std::string name = "Nataliia";
        std::string message = "Hello, Server, I'm " + name + "\n";

        boost::asio::write(
            socket,
            boost::asio::buffer(message)
        );

        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, '\n');

        std::istream input(&buffer);
        std::string response;
        std::getline(input, response);

        std::cout << "Server response: " << response << std::endl;

        int a = 0;
        std::cin >> a;
    }
    catch (std::exception& e)
    {
        std::cerr << "Client error: " << e.what() << std::endl;
    }
}
