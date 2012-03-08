################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../shiftpwmlib/CShiftPWM.cpp \
../shiftpwmlib/ShiftPWM.cpp 

OBJS += \
./shiftpwmlib/CShiftPWM.o \
./shiftpwmlib/ShiftPWM.o 

CPP_DEPS += \
./shiftpwmlib/CShiftPWM.d \
./shiftpwmlib/ShiftPWM.d 


# Each subdirectory must supply rules for building sources it contributes
shiftpwmlib/%.o: ../shiftpwmlib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/ArduinoCore/src" -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/BlinkenPu/arduinolib" -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/BlinkenPu/shiftpwmlib" -I"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/BlinkenPu/lib" -DARDUINO=22 -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


