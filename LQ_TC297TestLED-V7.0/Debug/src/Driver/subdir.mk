################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../src/Driver/LQ_ADC.c" \
"../src/Driver/LQ_CCU6.c" \
"../src/Driver/LQ_DMA.c" \
"../src/Driver/LQ_EEPROM.c" \
"../src/Driver/LQ_GPIO.c" \
"../src/Driver/LQ_GPIO_IRQ.c" \
"../src/Driver/LQ_GPSR.c" \
"../src/Driver/LQ_GPT12_ENC.c" \
"../src/Driver/LQ_GTM_PWM.c" \
"../src/Driver/LQ_Hard_SPI.c" \
"../src/Driver/LQ_QSPI.c" \
"../src/Driver/LQ_SOFTI2C.c" \
"../src/Driver/LQ_SOFTSPI.c" \
"../src/Driver/LQ_SPI.c" \
"../src/Driver/LQ_STM.c" \
"../src/Driver/LQ_UART.c" 

COMPILED_SRCS += \
"src/Driver/LQ_ADC.src" \
"src/Driver/LQ_CCU6.src" \
"src/Driver/LQ_DMA.src" \
"src/Driver/LQ_EEPROM.src" \
"src/Driver/LQ_GPIO.src" \
"src/Driver/LQ_GPIO_IRQ.src" \
"src/Driver/LQ_GPSR.src" \
"src/Driver/LQ_GPT12_ENC.src" \
"src/Driver/LQ_GTM_PWM.src" \
"src/Driver/LQ_Hard_SPI.src" \
"src/Driver/LQ_QSPI.src" \
"src/Driver/LQ_SOFTI2C.src" \
"src/Driver/LQ_SOFTSPI.src" \
"src/Driver/LQ_SPI.src" \
"src/Driver/LQ_STM.src" \
"src/Driver/LQ_UART.src" 

C_DEPS += \
"./src/Driver/LQ_ADC.d" \
"./src/Driver/LQ_CCU6.d" \
"./src/Driver/LQ_DMA.d" \
"./src/Driver/LQ_EEPROM.d" \
"./src/Driver/LQ_GPIO.d" \
"./src/Driver/LQ_GPIO_IRQ.d" \
"./src/Driver/LQ_GPSR.d" \
"./src/Driver/LQ_GPT12_ENC.d" \
"./src/Driver/LQ_GTM_PWM.d" \
"./src/Driver/LQ_Hard_SPI.d" \
"./src/Driver/LQ_QSPI.d" \
"./src/Driver/LQ_SOFTI2C.d" \
"./src/Driver/LQ_SOFTSPI.d" \
"./src/Driver/LQ_SPI.d" \
"./src/Driver/LQ_STM.d" \
"./src/Driver/LQ_UART.d" 

OBJS += \
"src/Driver/LQ_ADC.o" \
"src/Driver/LQ_CCU6.o" \
"src/Driver/LQ_DMA.o" \
"src/Driver/LQ_EEPROM.o" \
"src/Driver/LQ_GPIO.o" \
"src/Driver/LQ_GPIO_IRQ.o" \
"src/Driver/LQ_GPSR.o" \
"src/Driver/LQ_GPT12_ENC.o" \
"src/Driver/LQ_GTM_PWM.o" \
"src/Driver/LQ_Hard_SPI.o" \
"src/Driver/LQ_QSPI.o" \
"src/Driver/LQ_SOFTI2C.o" \
"src/Driver/LQ_SOFTSPI.o" \
"src/Driver/LQ_SPI.o" \
"src/Driver/LQ_STM.o" \
"src/Driver/LQ_UART.o" 


# Each subdirectory must supply rules for building sources it contributes
"src/Driver/LQ_ADC.src":"../src/Driver/LQ_ADC.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_ADC.o":"src/Driver/LQ_ADC.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_CCU6.src":"../src/Driver/LQ_CCU6.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_CCU6.o":"src/Driver/LQ_CCU6.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_DMA.src":"../src/Driver/LQ_DMA.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_DMA.o":"src/Driver/LQ_DMA.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_EEPROM.src":"../src/Driver/LQ_EEPROM.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_EEPROM.o":"src/Driver/LQ_EEPROM.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_GPIO.src":"../src/Driver/LQ_GPIO.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_GPIO.o":"src/Driver/LQ_GPIO.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_GPIO_IRQ.src":"../src/Driver/LQ_GPIO_IRQ.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_GPIO_IRQ.o":"src/Driver/LQ_GPIO_IRQ.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_GPSR.src":"../src/Driver/LQ_GPSR.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_GPSR.o":"src/Driver/LQ_GPSR.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_GPT12_ENC.src":"../src/Driver/LQ_GPT12_ENC.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_GPT12_ENC.o":"src/Driver/LQ_GPT12_ENC.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_GTM_PWM.src":"../src/Driver/LQ_GTM_PWM.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_GTM_PWM.o":"src/Driver/LQ_GTM_PWM.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_Hard_SPI.src":"../src/Driver/LQ_Hard_SPI.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_Hard_SPI.o":"src/Driver/LQ_Hard_SPI.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_QSPI.src":"../src/Driver/LQ_QSPI.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_QSPI.o":"src/Driver/LQ_QSPI.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_SOFTI2C.src":"../src/Driver/LQ_SOFTI2C.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_SOFTI2C.o":"src/Driver/LQ_SOFTI2C.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_SOFTSPI.src":"../src/Driver/LQ_SOFTSPI.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_SOFTSPI.o":"src/Driver/LQ_SOFTSPI.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_SPI.src":"../src/Driver/LQ_SPI.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_SPI.o":"src/Driver/LQ_SPI.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_STM.src":"../src/Driver/LQ_STM.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_STM.o":"src/Driver/LQ_STM.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/Driver/LQ_UART.src":"../src/Driver/LQ_UART.c" "src/Driver/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Driver/LQ_UART.o":"src/Driver/LQ_UART.src" "src/Driver/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-src-2f-Driver

clean-src-2f-Driver:
	-$(RM) ./src/Driver/LQ_ADC.d ./src/Driver/LQ_ADC.o ./src/Driver/LQ_ADC.src ./src/Driver/LQ_CCU6.d ./src/Driver/LQ_CCU6.o ./src/Driver/LQ_CCU6.src ./src/Driver/LQ_DMA.d ./src/Driver/LQ_DMA.o ./src/Driver/LQ_DMA.src ./src/Driver/LQ_EEPROM.d ./src/Driver/LQ_EEPROM.o ./src/Driver/LQ_EEPROM.src ./src/Driver/LQ_GPIO.d ./src/Driver/LQ_GPIO.o ./src/Driver/LQ_GPIO.src ./src/Driver/LQ_GPIO_IRQ.d ./src/Driver/LQ_GPIO_IRQ.o ./src/Driver/LQ_GPIO_IRQ.src ./src/Driver/LQ_GPSR.d ./src/Driver/LQ_GPSR.o ./src/Driver/LQ_GPSR.src ./src/Driver/LQ_GPT12_ENC.d ./src/Driver/LQ_GPT12_ENC.o ./src/Driver/LQ_GPT12_ENC.src ./src/Driver/LQ_GTM_PWM.d ./src/Driver/LQ_GTM_PWM.o ./src/Driver/LQ_GTM_PWM.src ./src/Driver/LQ_Hard_SPI.d ./src/Driver/LQ_Hard_SPI.o ./src/Driver/LQ_Hard_SPI.src ./src/Driver/LQ_QSPI.d ./src/Driver/LQ_QSPI.o ./src/Driver/LQ_QSPI.src ./src/Driver/LQ_SOFTI2C.d ./src/Driver/LQ_SOFTI2C.o ./src/Driver/LQ_SOFTI2C.src ./src/Driver/LQ_SOFTSPI.d ./src/Driver/LQ_SOFTSPI.o ./src/Driver/LQ_SOFTSPI.src ./src/Driver/LQ_SPI.d ./src/Driver/LQ_SPI.o ./src/Driver/LQ_SPI.src ./src/Driver/LQ_STM.d ./src/Driver/LQ_STM.o ./src/Driver/LQ_STM.src ./src/Driver/LQ_UART.d ./src/Driver/LQ_UART.o ./src/Driver/LQ_UART.src

.PHONY: clean-src-2f-Driver

