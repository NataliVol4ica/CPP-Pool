#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "UserInfoM.hpp"
#include "OSInfoM.hpp"
#include "TimeInfoM.hpp"
#include "CPUInfoM.hpp"
#include "RAMInfoM.hpp"
#include "NETInfoM.hpp"
#include "UnicornM.hpp"

#include <iostream>

int		sh_main(void)
{
	{
		UserInfoM					test;
		//Point2						p = test.getSize();
		std::vector<std::string>	info = test.getInfo();

		std::cout << "\033[0;32m\t" << test.getName() << "\033[0m" << std::endl;
		//<< "x = " << p.x << "----- y = " << p.y << std::endl;
		for (std::vector<std::string>::const_iterator i = info.begin();
			 i < info.end(); ++i)
			std::cout << *i << std::endl;
	}
	{
		OSInfoM						test;
		//Point2						p = test.getSize();
		std::vector<std::string>	info = test.getInfo();

		std::cout << "\033[0;32m\t" << test.getName() << "\033[0m" << std::endl;
		// << "x = " << p.x << "----- y = " << p.y << std::endl;
		for (std::vector<std::string>::const_iterator i = info.begin();
			 i < info.end(); ++i)
			std::cout << *i << std::endl;
	}
	{
		TimeInfoM					test;
		//Point2						p = test.getSize();
		std::vector<std::string>	info = test.getInfo();

		std::cout << "\033[0;32m\t" << test.getName() << "\033[0m" << std::endl;
		//<< "x = " << p.x << "----- y = " << p.y << std::endl;
		for (std::vector<std::string>::const_iterator i = info.begin();
			 i < info.end(); ++i)
			std::cout << *i << std::endl;
	}
	{
		CPUInfoM					test;
		//Point2						p = test.getSize();
		std::vector<std::string>	info = test.getInfo();

		std::cout << "\033[0;32m\t" << test.getName() << "\033[0m" << std::endl;
		//<< "x = " << p.x << "----- y = " << p.y << std::endl;
		for (std::vector<std::string>::const_iterator i = info.begin();
			 i < info.end(); ++i)
			std::cout << *i << std::endl;
	}
	{
		RAMInfoM					test;
		//Point2						p = test.getSize();
		std::vector<std::string>	info = test.getInfo();

		std::cout << "\033[0;32m\t" << test.getName() << "\033[0m" << std::endl;
		//<< "x = " << p.x << "----- y = " << p.y << std::endl;
		for (std::vector<std::string>::const_iterator i = info.begin();
			 i < info.end(); ++i)
			std::cout << *i << std::endl;
	}
	{
		NETInfoM					test;
		//Point2						p = test.getSize();
		std::vector<std::string>	info = test.getInfo();

		std::cout << "\033[0;32m\t" << test.getName() << "\033[0m" << std::endl;
		//<< "x = " << p.x << "----- y = " << p.y << std::endl;
		for (std::vector<std::string>::const_iterator i = info.begin();
			 i < info.end(); ++i)
			std::cout << *i << std::endl;
	}
	{
		UnicornM					test;
		//Point2						p = test.getSize();
		std::vector<std::string>	info = test.getInfo();

		std::cout << "\033[0;32m\t" << test.getName() << "\033[0m" << std::endl;
		//<< "x = " << p.x << "----- y = " << p.y << std::endl;
		for (std::vector<std::string>::const_iterator i = info.begin();
			 i < info.end(); ++i)
			std::cout << *i << std::endl;
	}

	return 0;
}
