################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_sci_uart/r_sci_uart.c 

C_DEPS += \
./ra/fsp/src/r_sci_uart/r_sci_uart.d 

OBJS += \
./ra/fsp/src/r_sci_uart/r_sci_uart.o 

SREC += \
Day4_Temperature_Basic.srec 

MAP += \
Day4_Temperature_Basic.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_sci_uart/%.o: ../ra/fsp/src/r_sci_uart/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CM33 -D_RA_ORDINAL=1 -I"/home/xenwithu/e2_studio/workspace/Day4_Temperature_Basic/src" -I"." -I"/home/xenwithu/e2_studio/workspace/Day4_Temperature_Basic/ra/fsp/inc" -I"/home/xenwithu/e2_studio/workspace/Day4_Temperature_Basic/ra/fsp/inc/api" -I"/home/xenwithu/e2_studio/workspace/Day4_Temperature_Basic/ra/fsp/inc/instances" -I"/home/xenwithu/e2_studio/workspace/Day4_Temperature_Basic/ra/arm/CMSIS_6/CMSIS/Core/Include" -I"/home/xenwithu/e2_studio/workspace/Day4_Temperature_Basic/ra_gen" -I"/home/xenwithu/e2_studio/workspace/Day4_Temperature_Basic/ra_cfg/fsp_cfg/bsp" -I"/home/xenwithu/e2_studio/workspace/Day4_Temperature_Basic/ra_cfg/fsp_cfg" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

