################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SignalExerciser.cpp 

OBJS += \
./SignalExerciser.o 

CPP_DEPS += \
./SignalExerciser.d 


# Each subdirectory must supply rules for building sources it contributes
SignalExerciser.o: ../SignalExerciser.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/kal-el/workspace/Linux-Signal-Handler/SignalHandler" -I"/home/kal-el/workspace/Linux-Signal-Handler/SignalHandlerBuilder" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"SignalExerciser.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


