################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Axle.cpp \
../Basis.cpp \
../ChassisPlate.cpp \
../Drawable.cpp \
../Environment.cpp \
../Part.cpp \
../TextureLoader.cpp \
../Walls.cpp \
../Wheel.cpp \
../main.cpp 

OBJS += \
./Axle.o \
./Basis.o \
./ChassisPlate.o \
./Drawable.o \
./Environment.o \
./Part.o \
./TextureLoader.o \
./Walls.o \
./Wheel.o \
./main.o 

CPP_DEPS += \
./Axle.d \
./Basis.d \
./ChassisPlate.d \
./Drawable.d \
./Environment.d \
./Part.d \
./TextureLoader.d \
./Walls.d \
./Wheel.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


