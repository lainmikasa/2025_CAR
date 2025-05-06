################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../src/User/LQ_PID.c" \
"../src/User/T1_front.c" \
"../src/User/T1_front_camera.c" 

COMPILED_SRCS += \
"src/User/LQ_PID.src" \
"src/User/T1_front.src" \
"src/User/T1_front_camera.src" 

C_DEPS += \
"./src/User/LQ_PID.d" \
"./src/User/T1_front.d" \
"./src/User/T1_front_camera.d" 

OBJS += \
"src/User/LQ_PID.o" \
"src/User/T1_front.o" \
"src/User/T1_front_camera.o" 


# Each subdirectory must supply rules for building sources it contributes
"src/User/LQ_PID.src":"../src/User/LQ_PID.c" "src/User/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/User/LQ_PID.o":"src/User/LQ_PID.src" "src/User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/User/T1_front.src":"../src/User/T1_front.c" "src/User/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/User/T1_front.o":"src/User/T1_front.src" "src/User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"src/User/T1_front_camera.src":"../src/User/T1_front_camera.c" "src/User/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"src/User/T1_front_camera.o":"src/User/T1_front_camera.src" "src/User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-src-2f-User

clean-src-2f-User:
	-$(RM) ./src/User/LQ_PID.d ./src/User/LQ_PID.o ./src/User/LQ_PID.src ./src/User/T1_front.d ./src/User/T1_front.o ./src/User/T1_front.src ./src/User/T1_front_camera.d ./src/User/T1_front_camera.o ./src/User/T1_front_camera.src

.PHONY: clean-src-2f-User

