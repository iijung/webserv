#ifndef LIBS_CONFIG_DIRECTIVE_FACTORY_HPP_
# define LIBS_CONFIG_DIRECTIVE_FACTORY_HPP_
# include "directive.hpp"
# include <cstdio>

class Directive;

class DirectiveFactory
{
 public:
	static Directive* Create(std::vector<std::string> &args);
	static bool Parse(Directive& parent, std::istream& ctx, bool is_sub);
 private:
	DirectiveFactory(void);
	DirectiveFactory(const DirectiveFactory &obj);
	DirectiveFactory& operator=(const DirectiveFactory &obj);
	virtual ~DirectiveFactory(void);
};

#endif /* LIBS_CONFIG_DIRECTIVE_FACTORY_HPP_ */
