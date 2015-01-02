################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Axle.cpp \
../CarBody.cpp \
../Chassis.cpp \
../ChassisPlate.cpp \
../Combination.cpp \
../Drawable.cpp \
../FuelTank.cpp \
../Part.cpp \
../RearImpactGuard.cpp \
../SemiTrailer.cpp \
../TractorUnit.cpp \
../TrailerBox.cpp \
../Wheel.cpp \
../main.cpp 

OBJS += \
./Axle.o \
./CarBody.o \
./Chassis.o \
./ChassisPlate.o \
./Combination.o \
./Drawable.o \
./FuelTank.o \
./Part.o \
./RearImpactGuard.o \
./SemiTrailer.o \
./TractorUnit.o \
./TrailerBox.o \
./Wheel.o \
./main.o 

CPP_DEPS += \
./Axle.d \
./CarBody.d \
./Chassis.d \
./ChassisPlate.d \
./Combination.d \
./Drawable.d \
./FuelTank.d \
./Part.d \
./RearImpactGuard.d \
./SemiTrailer.d \
./TractorUnit.d \
./TrailerBox.d \
./Wheel.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


