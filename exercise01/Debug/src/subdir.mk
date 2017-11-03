################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C++_SRCS += \
../src/displays_exercise01.c++ 

C++_DEPS += \
./src/displays_exercise01.d 

OBJS += \
./src/displays_exercise01.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c++
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/opencv-3.3.1/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


