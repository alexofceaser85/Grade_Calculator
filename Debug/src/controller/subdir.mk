################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/controller/ConsoleInputController.cpp 

CPP_DEPS += \
./src/controller/ConsoleInputController.d 

OBJS += \
./src/controller/ConsoleInputController.o 


# Each subdirectory must supply rules for building sources it contributes
src/controller/%.o: ../src/controller/%.cpp src/controller/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/model -I/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/controller -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-controller

clean-src-2f-controller:
	-$(RM) ./src/controller/ConsoleInputController.d ./src/controller/ConsoleInputController.o

.PHONY: clean-src-2f-controller

