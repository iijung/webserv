TOPDIR = $(abspath ..)

NAME	= webserv

LIBS	= \
	$(TOPDIR)/libs/multiplex/libmultiplex.a \
	$(TOPDIR)/libs/config/libconfig.a \
	$(TOPDIR)/libs/http/libhttp.a \

SRCS	= \
	server.cpp \
	client.cpp \
	main.cpp

# **************************************************************************** #
include $(TOPDIR)/build/Rules.mk

CPPFLAGS	+=
CXXFLAGS	+=
LDFLAGS		+=
LDLIBS		+=

$(NAME): $(OBJS) $(LIBS)
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@
