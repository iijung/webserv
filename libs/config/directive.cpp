#include "directive.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

Directive::~Directive(void)
{
}

Directive::Directive(void)
{
}

/* ************************************************************************** */
// Main
/* ************************************************************************** */

void Directive::AddArg(std::string arg)
{
	args_.push_back(arg);
}

void Directive::AddChild(Directive* child)
{
	child_.push_back(child);
}

#if 1
#include <iostream>
void Directive::Show(void) const
{
	std::cout << args_[0];
	for (size_t i = 1; i < args_.size(); ++i)
		std::cout << " " << args_[i];
	if (child_.size() == 0)
	{
		std::cout << ";" << std::endl;
		return;
	}
	std::cout << "{" << std::endl;
	for (size_t i = 0; i < child_.size(); ++i)
		child_[i]->Show();
	std::cout << "} # " << args_[0] <<std::endl;
}
#endif
