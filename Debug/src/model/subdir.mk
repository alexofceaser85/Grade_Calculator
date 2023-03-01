################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/GradesManager.cpp \
../src/model/StudentGrade.cpp 

CPP_DEPS += \
./src/model/GradesManager.d \
./src/model/StudentGrade.d 

OBJS += \
./src/model/GradesManager.o \
./src/model/StudentGrade.o 


# Each subdirectory must supply rules for building sources it contributes
src/model/%.o: ../src/model/%.cpp src/model/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/model" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/io" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/controller" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/settings" -I"/home/adecesa1/eclipse-workspace/gradeanalyzerDeCesare/src/errormessages" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-model

clean-src-2f-model:
	-$(RM) ./src/model/GradesManager.d ./src/model/GradesManager.o ./src/model/StudentGrade.d ./src/model/StudentGrade.o

.PHONY: clean-src-2f-model

