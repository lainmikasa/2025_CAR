################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.c" \
"../Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.c" \
"../Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.c" 

COMPILED_SRCS += \
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.src" \
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.src" \
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.src" 

C_DEPS += \
"./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.d" \
"./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.d" \
"./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.d" 

OBJS += \
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.o" \
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.o" \
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.o" 


# Each subdirectory must supply rules for building sources it contributes
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.src":"../Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.c" "Libraries/iLLD/TC29B/Tricore/Scu/Std/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.o":"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.src" "Libraries/iLLD/TC29B/Tricore/Scu/Std/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.src":"../Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.c" "Libraries/iLLD/TC29B/Tricore/Scu/Std/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.o":"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.src" "Libraries/iLLD/TC29B/Tricore/Scu/Std/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.src":"../Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.c" "Libraries/iLLD/TC29B/Tricore/Scu/Std/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.o":"Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.src" "Libraries/iLLD/TC29B/Tricore/Scu/Std/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-iLLD-2f-TC29B-2f-Tricore-2f-Scu-2f-Std

clean-Libraries-2f-iLLD-2f-TC29B-2f-Tricore-2f-Scu-2f-Std:
	-$(RM) ./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.d ./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.o ./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuCcu.src ./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.d ./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.o ./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuEru.src ./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.d ./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.o ./Libraries/iLLD/TC29B/Tricore/Scu/Std/IfxScuWdt.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC29B-2f-Tricore-2f-Scu-2f-Std

