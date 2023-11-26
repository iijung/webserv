TOPDIR = $(abspath ../..)

NAME	= libconfig.a

LIBS	= \

SRCS	= \
	config.cpp \
	directive.cpp \
	directive_factory.cpp \

# **************************************************************************** #
include $(TOPDIR)/build/Rules.mk

CPPFLAGS	+=
CXXFLAGS	+=
LDFLAGS		+=
LDLIBS		+=

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
