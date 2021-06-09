#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/poll.h>
#include <fcntl.h>

#include "Connection.hpp"
#include "Server.hpp"

class Webserv
{
	friend class					Server;
	std::vector<Server>				_servers;
	std::vector<int>				_indexTable;
	size_t							_conSize;

public:
	Webserv();
	~Webserv();

	Server		&serverAt(int);
	void		addServer(int);
	Connection	&operator[](int);
	void		updateIndexs(int, int);
};

#define log std::cout <<
#define line << std::endl
