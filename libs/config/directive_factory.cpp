# include "directive_factory.hpp"
#include <iostream>


/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

/* ************************************************************************** */
// Utility
/* ************************************************************************** */

static std::string GetToken(std::istream& ctx)
{
	int ch;
	std::string token;
	std::string comment;

	ctx.clear();
	while (ctx.good())
	{
		ch = ctx.peek();
		if (ch == EOF)
			break;
		else if (ch == '#')
		{
			std::getline(ctx, comment);
			if (!token.empty()) return token;
		}
		else if (std::isspace(ch))
		{
			ctx.get();
			if (!token.empty()) return token;
		}
		else if (ch == ';' || ch == '{' || ch == '}')
		{
			if (!token.empty()) return token;
			token += static_cast<char>(ctx.get());
			return token;
		}
		else
			token += ctx.get();
	}
	return token;
}

/* ************************************************************************** */
// Main
/* ************************************************************************** */

bool DirectiveFactory::Parse(Directive& parent, std::istream& ctx, bool is_sub)
{
	std::string token;

	ctx.clear();
	while (ctx.good())
	{
		token = GetToken(ctx);
		if (ctx.eof() || token.empty())
			return is_sub == false;
		if (is_sub && token.compare("}") == 0)
			return is_sub == true;
		std::vector<std::string> args;
		while (ctx.good() && !token.empty())
		{
			if (token.compare(";") == 0 || token.compare("{") == 0)
				break;
			if (token.compare("}") == 0)
				return false;
			args.push_back(token);
			token = GetToken(ctx);
		}
		if (args.size() == 0)
			return true;
		Directive* node = Create(args);
		if (node == NULL)
			break;
		parent.AddChild(node);
		if (token.compare("{") == 0)
		{
			if (DirectiveFactory::Parse(*node, ctx, true) == false)
				break;
		}
	}
	return false;
}

Directive* DirectiveFactory::Create(std::vector<std::string> &args)
{
	Directive *node = NULL;

	node = new Directive;
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it)
		node->AddArg(*it);
	return node;
}
