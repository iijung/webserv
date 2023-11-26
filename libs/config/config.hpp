#ifndef LIBS_CONFIG_CONFIG_HPP_
# define LIBS_CONFIG_CONFIG_HPP_
# include <fstream>
# include <stdexcept>
# include "directive_factory.hpp"

class Config
{
 public:
	static Config& GetInstance(void);
	void Load(const char* file);
	void Show(void) const;
 private:
	Config(void);
	Config(const Config &obj);
	Config& operator=(const Config &obj);
	~Config(void);

	Directive* main_;
};

#endif /* LIBS_CONFIG_CONFIG_HPP_ */
