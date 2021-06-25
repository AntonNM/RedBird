################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/board.cpp \
../src/main.cpp \
../src/moveVector.cpp \
../src/node.cpp \
../src/pathVector.cpp \
../src/piece.cpp 

OBJS += \
./src/board.o \
./src/main.o \
./src/moveVector.o \
./src/node.o \
./src/pathVector.o \
./src/piece.o 

CPP_DEPS += \
./src/board.d \
./src/main.d \
./src/moveVector.d \
./src/node.d \
./src/pathVector.d \
./src/piece.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


