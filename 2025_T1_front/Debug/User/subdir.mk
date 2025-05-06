################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../User/Cpu0_Main.c" \
"../User/Cpu1_Main.c" \
"../User/Cpu2_Main.c" \
"../User/irq.c" 

COMPILED_SRCS += \
"User/Cpu0_Main.src" \
"User/Cpu1_Main.src" \
"User/Cpu2_Main.src" \
"User/irq.src" 

C_DEPS += \
"./User/Cpu0_Main.d" \
"./User/Cpu1_Main.d" \
"./User/Cpu2_Main.d" \
"./User/irq.d" 

OBJS += \
"User/Cpu0_Main.o" \
"User/Cpu1_Main.o" \
"User/Cpu2_Main.o" \
"User/irq.o" 


# Each subdirectory must supply rules for building sources it contributes
"User/Cpu0_Main.src":"../User/Cpu0_Main.c" "User/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"User/Cpu0_Main.o":"User/Cpu0_Main.src" "User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"User/Cpu1_Main.src":"../User/Cpu1_Main.c" "User/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"User/Cpu1_Main.o":"User/Cpu1_Main.src" "User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"User/Cpu2_Main.src":"../User/Cpu2_Main.c" "User/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"User/Cpu2_Main.o":"User/Cpu2_Main.src" "User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"User/irq.src":"../User/irq.c" "User/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/2025_T1_front/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
"User/irq.o":"User/irq.src" "User/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\2025_T1_front\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-User

clean-User:
	-$(RM) ./User/Cpu0_Main.d ./User/Cpu0_Main.o ./User/Cpu0_Main.src ./User/Cpu1_Main.d ./User/Cpu1_Main.o ./User/Cpu1_Main.src ./User/Cpu2_Main.d ./User/Cpu2_Main.o ./User/Cpu2_Main.src ./User/irq.d ./User/irq.o ./User/irq.src

.PHONY: clean-User

