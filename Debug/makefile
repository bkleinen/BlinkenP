################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
BlinkenPu.lss \

FLASH_IMAGE += \
BlinkenPu.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: BlinkenPu.elf secondary-outputs

# Tool invocations
BlinkenPu.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-gcc -Wl,-Map,BlinkenPu.map,--cref -Wl,--gc-sections -L"/Users/kleinen/Dropbox/Arduino/eclipse-workspace-3/ArduinoCore/328P_16MHz" -mmcu=atmega328p -o "BlinkenPu.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

BlinkenPu.lss: BlinkenPu.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S BlinkenPu.elf  >"BlinkenPu.lss"
	@echo 'Finished building: $@'
	@echo ' '

BlinkenPu.hex: BlinkenPu.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex BlinkenPu.elf  "BlinkenPu.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: BlinkenPu.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p BlinkenPu.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: BlinkenPu.elf
	@echo 'Invoking: AVRDude'
	/usr/local/CrossPack-AVR-20120217/bin/avrdude -pm328p -carduino -P/dev/tty.usbmodemfd121 -b115200 -Uflash:w:BlinkenPu.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ELFS)$(FLASH_IMAGE)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(AVRDUDEDUMMY)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) BlinkenPu.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
