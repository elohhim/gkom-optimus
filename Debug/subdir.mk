################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Axle.cpp \
../CarBody.cpp \
../Chassis.cpp \
../Combination.cpp \
../SemiTrailer.cpp \
../TractorUnit.cpp \
../Wheel.cpp \
../main.cpp 

OBJS += \
./Axle.o \
./CarBody.o \
./Chassis.o \
./Combination.o \
./SemiTrailer.o \
./TractorUnit.o \
./Wheel.o \
./main.o 

CPP_DEPS += \
./Axle.d \
./CarBody.d \
./Chassis.d \
./Combination.d \
./SemiTrailer.d \
./TractorUnit.d \
./Wheel.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


