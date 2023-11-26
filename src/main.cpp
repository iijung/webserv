#include <cstdlib>
#include <iostream>
#include "config.hpp"
#include "server.hpp"

int main(int argc, char **argv)
{
    if (argc != 1 && argc != 2)
	{
        std::cerr << "Usage: " << argv[0] << " [configuration file]" << std::endl;
        return (EXIT_FAILURE);
    }
	try
	{
		Config::GetInstance().Load(argv[1]);
		Config::GetInstance().Show();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	// 2. service
//	Multiplex::GetInstance().AddItem(new Server(&config));
//	Multiplex::GetInstance().Loop();
    return (EXIT_SUCCESS);
}
