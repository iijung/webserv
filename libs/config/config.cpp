#include "config.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

Config::~Config(void)
{
}

Config::Config(void): main_(NULL)
{
}

/* ************************************************************************** */
// Main
/* ************************************************************************** */

Config& Config::GetInstance(void)
{
	static Config instance;
	return instance;
}

void Config::Show(void) const
{
	main_->Show();
}

#include <iostream>
void Config::Load(const char *file)
{
	std::string filename(file? file: "default.conf");

	if (main_)
	{
		delete main_;
		main_ = NULL;
	}
	else
	{
		std::vector<std::string> args;
		args.push_back("main");
		main_ = DirectiveFactory::Create(args);
	}
	std::ifstream ctx(filename.c_str(), std::ios_base::in);
	if (!ctx.is_open())
		throw std::runtime_error("Failed to open file " + filename);
	if (DirectiveFactory::Parse(*main_, ctx, false) == false)
		throw std::runtime_error("Failed to parse file " + filename);
	ctx.close();
}
