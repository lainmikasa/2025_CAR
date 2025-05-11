################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../src/APP/Display/LQ_Display.c" \
"../src/APP/Display/LQ_Font.c" \
"../src/APP/Display/LQ_IPSLCD.c" \
"../src/APP/Display/LQ_OLED096.c" \
"../src/APP/Display/LQ_TFT18.c" \
"../src/APP/Display/LQ_TFT2.c" 

COMPILED_SRCS += \
"src/APP/Display/LQ_Display.src" \
"src/APP/Display/LQ_Font.src" \
"src/APP/Display/LQ_IPSLCD.src" \
"src/APP/Display/LQ_OLED096.src" \
"src/APP/Display/LQ_TFT18.src" \
"src/APP/Display/LQ_TFT2.src" 

C_DEPS += \
"./src/APP/Display/LQ_Display.d" \
"./src/APP/Display/LQ_Font.d" \
"./src/APP/Display/LQ_IPSLCD.d" \
"./src/APP/Display/LQ_OLED096.d" \
"./src/APP/Display/LQ_TFT18.d" \
"./src/APP/Display/LQ_TFT2.d" 

OBJS += \
"src/APP/Display/LQ_Display.o" \
"src/APP/Display/LQ_Font.o" \
"src/APP/Display/LQ_IPSLCD.o" \
"src/APP/Display/LQ_OLED096.o" \
"src/APP/Display/LQ_TFT18.o" \
"src/APP/Display/LQ_TFT2.o" 


# Each subdirectory must supply rules for building sources it contributes
"src/APP/Display/LQ_Display.src":"../src/APP/Display/LQ_Display.c" "src/APP/Display/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/APP/Display/LQ_Display.o":"src/APP/Display/LQ_Display.src" "src/APP/Display/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/Display/LQ_Font.src":"../src/APP/Display/LQ_Font.c" "src/APP/Display/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/APP/Display/LQ_Font.o":"src/APP/Display/LQ_Font.src" "src/APP/Display/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/Display/LQ_IPSLCD.src":"../src/APP/Display/LQ_IPSLCD.c" "src/APP/Display/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/APP/Display/LQ_IPSLCD.o":"src/APP/Display/LQ_IPSLCD.src" "src/APP/Display/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/Display/LQ_OLED096.src":"../src/APP/Display/LQ_OLED096.c" "src/APP/Display/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/APP/Display/LQ_OLED096.o":"src/APP/Display/LQ_OLED096.src" "src/APP/Display/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/Display/LQ_TFT18.src":"../src/APP/Display/LQ_TFT18.c" "src/APP/Display/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/APP/Display/LQ_TFT18.o":"src/APP/Display/LQ_TFT18.src" "src/APP/Display/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/APP/Display/LQ_TFT2.src":"../src/APP/Display/LQ_TFT2.c" "src/APP/Display/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/APP/Display/LQ_TFT2.o":"src/APP/Display/LQ_TFT2.src" "src/APP/Display/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-src-2f-APP-2f-Display

clean-src-2f-APP-2f-Display:
	-$(RM) ./src/APP/Display/LQ_Display.d ./src/APP/Display/LQ_Display.o ./src/APP/Display/LQ_Display.src ./src/APP/Display/LQ_Font.d ./src/APP/Display/LQ_Font.o ./src/APP/Display/LQ_Font.src ./src/APP/Display/LQ_IPSLCD.d ./src/APP/Display/LQ_IPSLCD.o ./src/APP/Display/LQ_IPSLCD.src ./src/APP/Display/LQ_OLED096.d ./src/APP/Display/LQ_OLED096.o ./src/APP/Display/LQ_OLED096.src ./src/APP/Display/LQ_TFT18.d ./src/APP/Display/LQ_TFT18.o ./src/APP/Display/LQ_TFT18.src ./src/APP/Display/LQ_TFT2.d ./src/APP/Display/LQ_TFT2.o ./src/APP/Display/LQ_TFT2.src

.PHONY: clean-src-2f-APP-2f-Display

