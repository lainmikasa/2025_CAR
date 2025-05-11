################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../src/Main/cpu_init.c" 

COMPILED_SRCS += \
"src/Main/cpu_init.src" 

C_DEPS += \
"./src/Main/cpu_init.d" 

OBJS += \
"src/Main/cpu_init.o" 


# Each subdirectory must supply rules for building sources it contributes
"src/Main/cpu_init.src":"../src/Main/cpu_init.c" "src/Main/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/Main/cpu_init.o":"src/Main/cpu_init.src" "src/Main/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-src-2f-Main

clean-src-2f-Main:
	-$(RM) ./src/Main/cpu_init.d ./src/Main/cpu_init.o ./src/Main/cpu_init.src

.PHONY: clean-src-2f-Main

