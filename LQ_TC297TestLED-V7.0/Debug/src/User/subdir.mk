################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
"../src/User/1.cpp" \
"../src/User/cpp_transform.cpp" 

C_SRCS += \
"../src/User/LQ_PID.c" 

COMPILED_SRCS += \
"src/User/1.src" \
"src/User/LQ_PID.src" \
"src/User/cpp_transform.src" 

CPP_DEPS += \
"./src/User/1.d" \
"./src/User/cpp_transform.d" 

C_DEPS += \
"./src/User/LQ_PID.d" 

OBJS += \
"src/User/1.o" \
"src/User/LQ_PID.o" \
"src/User/cpp_transform.o" 


# Each subdirectory must supply rules for building sources it contributes
"src/User/1.src":"../src/User/1.cpp" "src/User/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/User/1.o":"src/User/1.src" "src/User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/User/LQ_PID.src":"../src/User/LQ_PID.c" "src/User/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/User/LQ_PID.o":"src/User/LQ_PID.src" "src/User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/User/cpp_transform.src":"../src/User/cpp_transform.cpp" "src/User/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"src/User/cpp_transform.o":"src/User/cpp_transform.src" "src/User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-src-2f-User

clean-src-2f-User:
	-$(RM) ./src/User/1.d ./src/User/1.o ./src/User/1.src ./src/User/LQ_PID.d ./src/User/LQ_PID.o ./src/User/LQ_PID.src ./src/User/cpp_transform.d ./src/User/cpp_transform.o ./src/User/cpp_transform.src

.PHONY: clean-src-2f-User

