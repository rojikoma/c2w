DEPEND_FILE=make_depend
CC = gcc

TOP := $(shell pwd)
INCS := ${TOP}/include

SRCS  = ${TOP}/cscope/parser.c
SRCS += ${TOP}/db/db_generator.c
SRCS += ${TOP}/web/web_generator.c
SRCS += ${TOP}/cscope2web_main.c
OBJS = $(SRCS:%.c=%.o)

TARGET = c2w
.SUFFIXES : .c .o

CFLAGS = -Wall -I${INCS}
#LDFLAGS = ${LIB}

all: clean $(TARGET)

$(TARGET): $(OBJS)
	${CC} -o $@ $(OBJS) ${CFLAGS}

depend:
	$(CC) -MM $(SRCS) > $(DEPEND_FILE)

clean:
	-rm -rf $(OBJS) $(TARGET) $(DEPEND_FILE)

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), depend)
ifneq ($(SRCS),)
-include $(DEPEND_FILE)
endif
endif
endif
