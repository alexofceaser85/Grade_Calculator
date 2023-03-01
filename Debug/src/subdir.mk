################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/gradeanalyzer.cpp 

CPP_DEPS += \
./src/gradeanalyzer.d 

OBJS += \
./src/gradeanalyzer.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/model" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/io" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/controller" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/settings" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/errormessages" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/gradeanalyzer.d ./src/gradeanalyzer.o

.PHONY: clean-src

