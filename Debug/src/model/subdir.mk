################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/Grade.cpp \
../src/model/GradesManager.cpp 

CPP_DEPS += \
./src/model/Grade.d \
./src/model/GradesManager.d 

OBJS += \
./src/model/Grade.o \
./src/model/GradesManager.o 


# Each subdirectory must supply rules for building sources it contributes
src/model/%.o: ../src/model/%.cpp src/model/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/controller -I/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/model -I/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/io -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-model

clean-src-2f-model:
	-$(RM) ./src/model/Grade.d ./src/model/Grade.o ./src/model/GradesManager.d ./src/model/GradesManager.o

.PHONY: clean-src-2f-model

