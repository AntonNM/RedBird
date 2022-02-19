################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MovementVector.cpp \
../src/Piece.cpp \
../src/PositionVector.cpp \
../src/board.cpp \
../src/main.cpp \
../src/node.cpp \
../src/pathVector.cpp 

OBJS += \
./src/MovementVector.o \
./src/Piece.o \
./src/PositionVector.o \
./src/board.o \
./src/main.o \
./src/node.o \
./src/pathVector.o 

CPP_DEPS += \
./src/MovementVector.d \
./src/Piece.d \
./src/PositionVector.d \
./src/board.d \
./src/main.d \
./src/node.d \
./src/pathVector.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


