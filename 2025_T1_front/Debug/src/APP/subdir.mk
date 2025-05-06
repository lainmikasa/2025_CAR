################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../src/APP/LQ_ADC_7Mic.c" \
"../src/APP/LQ_BD.c" \
"../src/APP/LQ_CAMERA.c" \
"../src/APP/LQ_CCU6_Timer.c" \
"../src/APP/LQ_EEPROM_TEST.c" \
"../src/APP/LQ_Encoder.c" \
"../src/APP/LQ_FFT_TEST.c" \
"../src/APP/LQ_GPIO_ExInt.c" \
"../src/APP/LQ_GPIO_KEY.c" \
"../src/APP/LQ_GPIO_LED.c" \
"../src/APP/LQ_MT9V034.c" \
"../src/APP/LQ_PWM_BLDC.c" \
"../src/APP/LQ_PWM_BLSmotor.c" \
"../src/APP/LQ_PWM_Moto.c" \
"../src/APP/LQ_PWM_Servo.c" \
"../src/APP/LQ_SBUS.c" \
"../src/APP/LQ_STM_Timer.c" \
"../src/APP/LQ_UART_Bluetooth.c" 

COMPILED_SRCS += \
"src/APP/LQ_ADC_7Mic.src" \
"src/APP/LQ_BD.src" \
"src/APP/LQ_CAMERA.src" \
"src/APP/LQ_CCU6_Timer.src" \
"src/APP/LQ_EEPROM_TEST.src" \
"src/APP/LQ_Encoder.src" \
"src/APP/LQ_FFT_TEST.src" \
"src/APP/LQ_GPIO_ExInt.src" \
"src/APP/LQ_GPIO_KEY.src" \
"src/APP/LQ_GPIO_LED.src" \
"src/APP/LQ_MT9V034.src" \
"src/APP/LQ_PWM_BLDC.src" \
"src/APP/LQ_PWM_BLSmotor.src" \
"src/APP/LQ_PWM_Moto.src" \
"src/APP/LQ_PWM_Servo.src" \
"src/APP/LQ_SBUS.src" \
"src/APP/LQ_STM_Timer.src" \
"src/APP/LQ_UART_Bluetooth.src" 

C_DEPS += \
"./src/APP/LQ_ADC_7Mic.d" \
"./src/APP/LQ_BD.d" \
"./src/APP/LQ_CAMERA.d" \
"./src/APP/LQ_CCU6_Timer.d" \
"./src/APP/LQ_EEPROM_TEST.d" \
"./src/APP/LQ_Encoder.d" \
"./src/APP/LQ_FFT_TEST.d" \
"./src/APP/LQ_GPIO_ExInt.d" \
"./src/APP/LQ_GPIO_KEY.d" \
"./src/APP/LQ_GPIO_LED.d" \
"./src/APP/LQ_MT9V034.d" \
"./src/APP/LQ_PWM_BLDC.d" \
"./src/APP/LQ_PWM_BLSmotor.d" \
"./src/APP/LQ_PWM_Moto.d" \
"./src/APP/LQ_PWM_Servo.d" \
"./src/APP/LQ_SBUS.d" \
"./src/APP/LQ_STM_Timer.d" \
"./src/APP/LQ_UART_Bluetooth.d" 

OBJS += \
"src/APP/LQ_ADC_7Mic.o" \
"src/APP/LQ_BD.o" \
"src/APP/LQ_CAMERA.o" \
"src/APP/LQ_CCU6_Timer.o" \
"src/APP/LQ_EEPROM_TEST.o" \
"src/APP/LQ_Encoder.o" \
"src/APP/LQ_FFT_TEST.o" \
"src/APP/LQ_GPIO_ExInt.o" \
"src/APP/LQ_GPIO_KEY.o" \
"src/APP/LQ_GPIO_LED.o" \
"src/APP/LQ_MT9V034.o" \
"src/APP/LQ_PWM_BLDC.o" \
"src/APP/LQ_PWM_BLSmotor.o" \
"src/APP/LQ_PWM_Moto.o" \
"src/APP/LQ_PWM_Servo.o" \
"src/APP/LQ_SBUS.o" \
"src/APP/LQ_STM_Timer.o" \
"src/APP/LQ_UART_Bluetooth.o" 


# Each subdirectory must supply rules for building sources it contributes
"src/APP/LQ_ADC_7Mic.src":"../src/APP/LQ_ADC_7Mic.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_ADC_7Mic.o":"src/APP/LQ_ADC_7Mic.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_BD.src":"../src/APP/LQ_BD.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_BD.o":"src/APP/LQ_BD.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_CAMERA.src":"../src/APP/LQ_CAMERA.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_CAMERA.o":"src/APP/LQ_CAMERA.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_CCU6_Timer.src":"../src/APP/LQ_CCU6_Timer.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_CCU6_Timer.o":"src/APP/LQ_CCU6_Timer.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_EEPROM_TEST.src":"../src/APP/LQ_EEPROM_TEST.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_EEPROM_TEST.o":"src/APP/LQ_EEPROM_TEST.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_Encoder.src":"../src/APP/LQ_Encoder.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_Encoder.o":"src/APP/LQ_Encoder.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_FFT_TEST.src":"../src/APP/LQ_FFT_TEST.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_FFT_TEST.o":"src/APP/LQ_FFT_TEST.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_GPIO_ExInt.src":"../src/APP/LQ_GPIO_ExInt.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_GPIO_ExInt.o":"src/APP/LQ_GPIO_ExInt.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_GPIO_KEY.src":"../src/APP/LQ_GPIO_KEY.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_GPIO_KEY.o":"src/APP/LQ_GPIO_KEY.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_GPIO_LED.src":"../src/APP/LQ_GPIO_LED.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_GPIO_LED.o":"src/APP/LQ_GPIO_LED.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_MT9V034.src":"../src/APP/LQ_MT9V034.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_MT9V034.o":"src/APP/LQ_MT9V034.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_PWM_BLDC.src":"../src/APP/LQ_PWM_BLDC.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_PWM_BLDC.o":"src/APP/LQ_PWM_BLDC.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_PWM_BLSmotor.src":"../src/APP/LQ_PWM_BLSmotor.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_PWM_BLSmotor.o":"src/APP/LQ_PWM_BLSmotor.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_PWM_Moto.src":"../src/APP/LQ_PWM_Moto.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_PWM_Moto.o":"src/APP/LQ_PWM_Moto.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_PWM_Servo.src":"../src/APP/LQ_PWM_Servo.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_PWM_Servo.o":"src/APP/LQ_PWM_Servo.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_SBUS.src":"../src/APP/LQ_SBUS.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_SBUS.o":"src/APP/LQ_SBUS.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_STM_Timer.src":"../src/APP/LQ_STM_Timer.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_STM_Timer.o":"src/APP/LQ_STM_Timer.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/LQ_UART_Bluetooth.src":"../src/APP/LQ_UART_Bluetooth.c" "src/APP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/APP/LQ_UART_Bluetooth.o":"src/APP/LQ_UART_Bluetooth.src" "src/APP/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-src-2f-APP

clean-src-2f-APP:
	-$(RM) ./src/APP/LQ_ADC_7Mic.d ./src/APP/LQ_ADC_7Mic.o ./src/APP/LQ_ADC_7Mic.src ./src/APP/LQ_BD.d ./src/APP/LQ_BD.o ./src/APP/LQ_BD.src ./src/APP/LQ_CAMERA.d ./src/APP/LQ_CAMERA.o ./src/APP/LQ_CAMERA.src ./src/APP/LQ_CCU6_Timer.d ./src/APP/LQ_CCU6_Timer.o ./src/APP/LQ_CCU6_Timer.src ./src/APP/LQ_EEPROM_TEST.d ./src/APP/LQ_EEPROM_TEST.o ./src/APP/LQ_EEPROM_TEST.src ./src/APP/LQ_Encoder.d ./src/APP/LQ_Encoder.o ./src/APP/LQ_Encoder.src ./src/APP/LQ_FFT_TEST.d ./src/APP/LQ_FFT_TEST.o ./src/APP/LQ_FFT_TEST.src ./src/APP/LQ_GPIO_ExInt.d ./src/APP/LQ_GPIO_ExInt.o ./src/APP/LQ_GPIO_ExInt.src ./src/APP/LQ_GPIO_KEY.d ./src/APP/LQ_GPIO_KEY.o ./src/APP/LQ_GPIO_KEY.src ./src/APP/LQ_GPIO_LED.d ./src/APP/LQ_GPIO_LED.o ./src/APP/LQ_GPIO_LED.src ./src/APP/LQ_MT9V034.d ./src/APP/LQ_MT9V034.o ./src/APP/LQ_MT9V034.src ./src/APP/LQ_PWM_BLDC.d ./src/APP/LQ_PWM_BLDC.o ./src/APP/LQ_PWM_BLDC.src ./src/APP/LQ_PWM_BLSmotor.d ./src/APP/LQ_PWM_BLSmotor.o ./src/APP/LQ_PWM_BLSmotor.src ./src/APP/LQ_PWM_Moto.d ./src/APP/LQ_PWM_Moto.o ./src/APP/LQ_PWM_Moto.src ./src/APP/LQ_PWM_Servo.d ./src/APP/LQ_PWM_Servo.o ./src/APP/LQ_PWM_Servo.src ./src/APP/LQ_SBUS.d ./src/APP/LQ_SBUS.o ./src/APP/LQ_SBUS.src ./src/APP/LQ_STM_Timer.d ./src/APP/LQ_STM_Timer.o ./src/APP/LQ_STM_Timer.src ./src/APP/LQ_UART_Bluetooth.d ./src/APP/LQ_UART_Bluetooth.o ./src/APP/LQ_UART_Bluetooth.src

.PHONY: clean-src-2f-APP

