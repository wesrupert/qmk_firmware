SRC += ora.c

VPATH += keyboards/gboards

BOOTMAGIC_ENABLE     = yes
OS_DETECTION_ENABLE  = yes
DYNAMIC_MACRO_ENABLE = yes
KEY_LOCK_ENABLE      = yes
TAP_DANCE_ENABLE     = yes
LEADER_ENABLE        = yes
COMBO_ENABLE         = yes
CAPS_WORD_ENABLE     = yes

MAGIC_ENABLE         = no
COMMAND_ENABLE       = no
CONSOLE_ENABLE       = no
KEY_LOCK_ENABLE      = no
MOUSEKEY_ENABLE      = no
GRAVE_ESC_ENABLE     = no
SPACE_CADET_ENABLE   = no

ifeq ($(strip $(AUTO_TRANSPORT_LAYER)), yes)
	OPT_DEFS += -DAUTO_TRANSPORT_LAYER
endif
