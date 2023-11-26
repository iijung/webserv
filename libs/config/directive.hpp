#ifndef LIBS_CONFIG_DIRECTIVE_HPP_
# define LIBS_CONFIG_DIRECTIVE_HPP_
# include <vector>
# include <sstream>
# include <stdexcept>

class Directive
{
 public:
	typedef std::vector<Directive*> Child;
	typedef std::vector<std::string> Args;

	Directive(void);
	virtual ~Directive(void);
	
	void AddChild(Directive* child);
	void AddArg(std::string arg);

	void Show(void) const;
 protected:
	std::vector<Directive*> child_;
	std::vector<std::string> args_;
 private:
	Directive(const Directive &obj);
	Directive& operator=(const Directive &obj);
};

#endif /* LIBS_CONFIG_DIRECTIVE_HPP_ */
