#include "Socket.hpp"

#include <iostream>
#include <stdexcept>
#include <typeinfo>

#include <boost/lexical_cast.hpp>

int main(int argc, char* argv[])
{
	int port = 5050;
	string ip = "127.0.0.1";

	if (argc == 2) {
		try {
			port = lexical_cast<int>(argv[1]);
		} catch (const std::bad_cast& e) {
			std::cout << "Invalid port \'" << argv[1] << "\' server will run on port 5050" << std::endl;
		}
	}

	if (argc == 3) {
		try {
			port = lexical_cast<int>(argv[1]);
		} catch (const std::bad_cast& e) {
			std::cout << "Invalid port \'" << argv[1] << "\' server will run on port 5050" << std::endl;
		}

		ip = argv[2];
	}

	try {
		Socket s;
		s.Connect(ip, port);

		while (1) {
			string msgTo, msgFrom;
			std::cout << "Type message structure (exit to quit)" << std::endl;
			std::cin >> msgTo;
			if (msgTo == "exit") break;
			s.Write(msgTo);
			s.Read(msgFrom);
			std::cout << "Received: \"" << msgFrom << "\"" << std::endl;
		}
	} catch (const std::runtime_error& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	return 0;
}

