################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/User/subdir.mk
-include src/Main/subdir.mk
-include src/Driver/subdir.mk
-include src/APP/IMU/subdir.mk
-include src/APP/Display/subdir.mk
-include src/APP/subdir.mk
-include User/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/_Lib/DataHandling/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Vadc/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Vadc/Adc/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Stm/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Qspi/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Qspi/SpiMaster/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Mtu/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Gtm/Tom/Pwm/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Gtm/Tim/In/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Gtm/Atom/Pwm/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Gpt12/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Flash/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Dma/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Dma/Dma/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Cpu/Irq/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Cpu/CStart/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Ccu6/Timer/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Ccu6/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Asclin/Std/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Asclin/Spi/subdir.mk
-include Libraries/iLLD/TC29B/Tricore/Asclin/Asc/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Math/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
-include Libraries/Service/CpuGeneric/StdIf/subdir.mk
-include Libraries/Service/CpuGeneric/If/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Configurations/Debug/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := LQ_TC297TestLED-V7.0
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
LQ_TC297TestLED-V7.0.siz \


# All Target
all: main-build

# Main-build Target
main-build: LQ_TC297TestLED-V7.0.elf secondary-outputs

# Tool invocations
LQ_TC297TestLED-V7.0.elf: $(OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc --lsl-file="../Lcf_Tasking_Tricore_Tc.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy "D:\Users\24387\AURIX-v1.10.6-workspace\LQ_TC297TestLED-V7.0\src\APP\IMU\LQ_MPU6050_DMP.o" -Wl--map-file="LQ_TC297TestLED-V7.0.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --fp-model=2 -lrt -lc_fpu --lsl-core=vtc --io-streams=cpp11 --exceptions --strict --anachronisms --force-c++ -Ctc29xb -o"LQ_TC297TestLED-V7.0.elf" -Wl-o"LQ_TC297TestLED-V7.0.hex:IHEX" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

LQ_TC297TestLED-V7.0.siz: LQ_TC297TestLED-V7.0.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "LQ_TC297TestLED-V7.0.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) LQ_TC297TestLED-V7.0.siz LQ_TC297TestLED-V7.0.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
