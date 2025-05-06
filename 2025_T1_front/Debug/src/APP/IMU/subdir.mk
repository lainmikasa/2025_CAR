################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../src/APP/IMU/LQ_IIC_Gyro.c" \
"../src/APP/IMU/LQ_MPU6050_DMP_test.c" \
"../src/APP/IMU/LQ_SPI_Gryo.c" 

O_SRCS += \
"../src/APP/IMU/LQ_MPU6050_DMP.o" 

COMPILED_SRCS += \
"src/APP/IMU/LQ_IIC_Gyro.src" \
"src/APP/IMU/LQ_MPU6050_DMP_test.src" \
"src/APP/IMU/LQ_SPI_Gryo.src" 

C_DEPS += \
"./src/APP/IMU/LQ_IIC_Gyro.d" \
"./src/APP/IMU/LQ_MPU6050_DMP_test.d" \
"./src/APP/IMU/LQ_SPI_Gryo.d" 

OBJS += \
"src/APP/IMU/LQ_IIC_Gyro.o" \
"src/APP/IMU/LQ_MPU6050_DMP_test.o" \
"src/APP/IMU/LQ_SPI_Gryo.o" 


# Each subdirectory must supply rules for building sources it contributes
"src/APP/IMU/LQ_IIC_Gyro.src":"../src/APP/IMU/LQ_IIC_Gyro.c" "src/APP/IMU/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/IMU/LQ_IIC_Gyro.o":"src/APP/IMU/LQ_IIC_Gyro.src" "src/APP/IMU/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/IMU/LQ_MPU6050_DMP_test.src":"../src/APP/IMU/LQ_MPU6050_DMP_test.c" "src/APP/IMU/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/IMU/LQ_MPU6050_DMP_test.o":"src/APP/IMU/LQ_MPU6050_DMP_test.src" "src/APP/IMU/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/IMU/LQ_SPI_Gryo.src":"../src/APP/IMU/LQ_SPI_Gryo.c" "src/APP/IMU/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/IMU/LQ_SPI_Gryo.o":"src/APP/IMU/LQ_SPI_Gryo.src" "src/APP/IMU/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-src-2f-APP-2f-IMU

clean-src-2f-APP-2f-IMU:
	-$(RM) ./src/APP/IMU/LQ_IIC_Gyro.d ./src/APP/IMU/LQ_IIC_Gyro.o ./src/APP/IMU/LQ_IIC_Gyro.src ./src/APP/IMU/LQ_MPU6050_DMP_test.d ./src/APP/IMU/LQ_MPU6050_DMP_test.o ./src/APP/IMU/LQ_MPU6050_DMP_test.src ./src/APP/IMU/LQ_SPI_Gryo.d ./src/APP/IMU/LQ_SPI_Gryo.o ./src/APP/IMU/LQ_SPI_Gryo.src

.PHONY: clean-src-2f-APP-2f-IMU

