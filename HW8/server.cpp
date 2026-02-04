#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <boost/signals2.hpp>

using boost::asio::ip::tcp;

boost::signals2::signal<void(std::string)> sig;

void Slot1(std::string message)
{
	std::cout << "Recive message vrom client : " << message;
}

void write_asio(std::shared_ptr<std::string> response, tcp::socket& socket)
{
	boost::asio::async_write(
		socket,
		boost::asio::buffer(*response),
		[response](const boost::system::error_code& ec, std::size_t)
		{
			if (ec) {
				std::cout << "Write error: " << ec.message() << "\n";
				return;
			}
			std::cout << "message sent\n";
		}
	);
}

int main()
{
	sig.connect(&Slot1);
	boost::asio::io_context io;
	tcp::acceptor acseptor(io, tcp::endpoint(tcp::v4(), 5555));
	tcp::socket socket(io);

	acseptor.async_accept(socket, [&](const boost::system::error_code& error)
		{
			if (error) {
				std::cout << "Accept error: " << error.message() << "\n";
				return;
			}

			std::cout << "Client connected \n";
			static char	buffer[1024];


			socket.async_read_some(boost::asio::buffer(buffer),
				[&](const boost::system::error_code& ec, std::size_t lenght)
				{
					if (!ec)
					{
						std::string message(buffer, lenght);
						auto response = std::make_shared<std::string>("Hello from server: " + message);
						if (response->empty() || response->back() != '\n') response->push_back('\n');
						sig(message);
						write_asio(response, socket);
					}
				});

		});

	io.run();

}
