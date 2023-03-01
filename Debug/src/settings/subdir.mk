################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/settings/ApplicationSettings.cpp 

CPP_DEPS += \
./src/settings/ApplicationSettings.d 

OBJS += \
./src/settings/ApplicationSettings.o 


# Each subdirectory must supply rules for building sources it contributes
src/settings/%.o: ../src/settings/%.cpp src/settings/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/model" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/io" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/controller" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/settings" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/errormessages" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-settings

clean-src-2f-settings:
	-$(RM) ./src/settings/ApplicationSettings.d ./src/settings/ApplicationSettings.o

.PHONY: clean-src-2f-settings

