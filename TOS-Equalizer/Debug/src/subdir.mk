################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Block.cpp \
../src/Coefficient.cpp \
../src/CommandHandler.cpp \
../src/Equalizer.cpp \
../src/FileParser.cpp \
../src/Queue.cpp 

OBJS += \
./src/Block.o \
./src/Coefficient.o \
./src/CommandHandler.o \
./src/Equalizer.o \
./src/FileParser.o \
./src/Queue.o 

CPP_DEPS += \
./src/Block.d \
./src/Coefficient.d \
./src/CommandHandler.d \
./src/Equalizer.d \
./src/FileParser.d \
./src/Queue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


