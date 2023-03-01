################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/io/FileIO.cpp 

CPP_DEPS += \
./src/io/FileIO.d 

OBJS += \
./src/io/FileIO.o 


# Each subdirectory must supply rules for building sources it contributes
src/io/%.o: ../src/io/%.cpp src/io/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/model" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/io" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/controller" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/settings" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-io

clean-src-2f-io:
	-$(RM) ./src/io/FileIO.d ./src/io/FileIO.o

.PHONY: clean-src-2f-io

