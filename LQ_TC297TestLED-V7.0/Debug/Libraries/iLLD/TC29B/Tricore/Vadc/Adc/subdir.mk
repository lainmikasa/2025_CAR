################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.c" 

COMPILED_SRCS += \
"Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.src" 

C_DEPS += \
"./Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.d" 

OBJS += \
"Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.o" 


# Each subdirectory must supply rules for building sources it contributes
"Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.src":"../Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.c" "Libraries/iLLD/TC29B/Tricore/Vadc/Adc/subdir.mk"
	cctc "$<" -lcpsx_fpu -cs --dep-file="$*.d" --misrac-version=2004 "-fD:/Users/24387/AURIX-v1.10.6-workspace/LQ_TC297TestLED-V7.0/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --io-streams=cpp11 --exceptions --anachronisms --fp-model=2 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@"
"Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.o":"Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.src" "Libraries/iLLD/TC29B/Tricore/Vadc/Adc/subdir.mk"
	astc -I"D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\User" -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-iLLD-2f-TC29B-2f-Tricore-2f-Vadc-2f-Adc

clean-Libraries-2f-iLLD-2f-TC29B-2f-Tricore-2f-Vadc-2f-Adc:
	-$(RM) ./Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.d ./Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.o ./Libraries/iLLD/TC29B/Tricore/Vadc/Adc/IfxVadc_Adc.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC29B-2f-Tricore-2f-Vadc-2f-Adc

