################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/BlinkenFilm.cpp \
../lib/Fader.cpp \
../lib/Rain.cpp \
../lib/RandomLight.cpp 

OBJS += \
./lib/BlinkenFilm.o \
./lib/Fader.o \
./lib/Rain.o \
./lib/RandomLight.o 

CPP_DEPS += \
./lib/BlinkenFilm.d \
./lib/Fader.d \
./lib/Rain.d \
./lib/RandomLight.d 


# Each subdirectory must supply rules for building sources it contributes
lib/%.o: ../lib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/ArduinoCore/src" -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/BlinkenPu/arduinolib" -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/BlinkenPu/shiftpwmlib" -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/BlinkenPu/lib" -DARDUINO=22 -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


