serial=/dev/ttyUSB0
BOARDS_TXT = /usr/local/arduino-1.8.9/hardware/arduino/avr/boards.txt
BOARD_TAG	= nano 
BOARD_SUB 	= atmega328
# BOARD_TAG	= uno

ARDMK_DIR=/usr/local/Arduino-Makefile

MONITOR_PORT = ${serial}
SERIAL_PORT = ${serial}

### PROJECT_DIR
### This is the path to where you have created/cloned your project
PROJECT_DIR       = /home/rusty/Arduino/ControlStation/pantilt
ARDUINO_DIR       = /usr/local/arduino-1.8.9

### Path to where the your project's libraries are stored.
USER_LIB_PATH	:=  /home/rusty/Arduino/libraries
ARDUINO_LIBS	= Servo

### Do not touch - the path to Arduino.mk, inside the ARDMK_DIR
include $(ARDMK_DIR)/Arduino.mk
