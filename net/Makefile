TOPDIR=		../..

include $(TOPDIR)/misc/mk/config.mk
include $(TOPDIR)/misc/mk/common-$(ARCH).mk

LO_TARGET=	net.lo
LO_TARGET+=     crc.lo

LO_OBJS= 

# common driver for all system
DIRS=

DIRS+= someip
DIRS+= crc

all: $(LO_TARGET)

include $(TOPDIR)/misc/mk/rules-common.mk
include $(TOPDIR)/misc/mk/rules-partition.mk

