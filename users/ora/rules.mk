SRC += ora.c
VPATH += keyboards/gboards

ifeq ($(strip $(AUTO_TRANSPORT_LAYER)), yes)
	OPT_DEFS += -DAUTO_TRANSPORT_LAYER
endif
