LTO_ENABLE = yes            # Link Time Optimization enabled
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE = yes           # OLED display
VIA_ENABLE = no			    # Disabler VIA support
TAP_DANCE_ENABLE = yes	    # Enable tap dance (multi-tap feature)
WPM_ENABLE = yes            # Enable words per minute feature
MOUSEKEY_ENABLE = yes		# Enable mouse emulation
OS_DETECTION_ENABLE = yes   # Enable OS detection for different keymaps

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/mode_icon_reader.c \
		./keylogger.c \
		./layer_state_reader.c


