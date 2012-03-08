################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arduinolib/SPI.cpp 

OBJS += \
./arduinolib/SPI.o 

CPP_DEPS += \
./arduinolib/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
arduinolib/%.o: ../arduinolib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/ArduinoCore/src" -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/BlinkenPu/arduinolib" -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/BlinkenPu/shiftpwmlib" -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/BlinkenPu/lib" -DARDUINO=22 -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


