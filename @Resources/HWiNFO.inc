;//////////////////////////////////////////////////////////////////////////////////////////////////
;                                          HWiNFO Settings
;//////////////////////////////////////////////////////////////////////////////////////////////////
;
; Instructions:
;
; 1. Install and configure HWiNFO.
;
;    On the HWiNFO Settings screen, ensure the "Shared Memory Support" option is checked. If your
;    system has multiple GPUs, you can check the "Wake disabled GPUs" and "Poll sleeping GPUs"
;    options if needed.
;
;    On the main HWiNFO screen, click the Sensors button on the toolbar. Alternatively, you can
;    right-click the HWiNFO tray icon and select the Sensors option. At the bottom of the Sensors
;    screen, click the Configure Sensors button. Change the Scan Interval to 1000 milliseconds and
;    click the Set button. If desired, change the Temperature Units setting to Fahrenheit.
;    Click OK to save your changes and then minimize the Sensors window.
;
;    NOTE:  For best results when using AMD GPUs, use HWiNFO version 5.80 or later.
;
; 2. Ensure the HWiNFO application is running and the Sensors window is enabled!
;
; 3. For the Gadget you are configuring, click the wrench icon in the upper right corner to open
;    the Settings, then click the "Show Shared Memory Viewer" option.
;
;    NOTE:  By default, three pre-configured GPU Meter skins are provided for you; each skin
;           (in the folders "GPU #0", "GPU #1", "GPU #2") monitors a specific GPU as shown by
;           HWiNFO. Typically, on most Intel-based systems, "GPU #0" will correspond to the
;           integrated GPU (e.g., "Intel HD Graphics"), while "GPU #1" will correspond to your
;           dedicated GPU (e.g., nVidia or AMD).  AMD CPUs also offer integrated GPUs, and will act
;           similarly. Select the GPU Meter(s) that correspond to the GPU(s) you are trying to
;           monitor. If you have more than 3 GPUs (like a quad-SLI setup), then you can follow the
;           instructions at:
;           https://github.com/SilverAzide/Gadgets/wiki/HOW-TO-Configure-the-GPU-Meter-to-monitor-multiple-GPUs#for-systems-with-more-than-3-gpus-4-way-sli-systems-do-the-following
;           to create additional GPU Meters for GPU #3, GPU#4, etc.
;
;    NOTE:  By default, All CPU Meter monitors CPU #0 as shown by HWiNFO.  If your system has
;           multiple PHYSICAL CPUs (do not confuse with LOGICAL CPUs, or physical cores) you will
;           need to adapt the instructions for the case of multiple GPUs to create or configure the
;           Gadgets for your other CPUs.
;
; 3. From the "Sensor Details" section of the Shared Memory Viewer, for each sensor (CPU,
;    motherboard, GPU, etc.) locate the Sensor ID and Sensor Instance variables below and change
;    the hexadecimal values to match the values shown in the Viewer.
;
;    Example:  The CPU thermal sensor ID and instance variables shown below are:
;              HWiNFO-CPU0-DTS-SensorId=0xf0000400
;              HWiNFO-CPU0-DTS-SensorInstance=0x0
;
;              In the Viewer app, click the "CPU [#0]: <your CPU name>: DTS" branch of the sensor
;              tree.  In the Sensor Details section, highlight the hexadecimal ID value
;              (0xf0000400) and paste it as the value of the "HWiNFO-CPU0-DTS-SensorId" variable in
;              this file.  Highlight the hexadecimal Instance value (0x0) and paste it as the value
;              of the "HWiNFO-CPU0-DTS-SensorInstance" variable.
;
;    NOTE: If you don't have a particular sensor (i.e., you don't have "GPU #1"), then you can
;          use ID and Instance values of "0x0" or you can leave the values as shown as long as they
;          don't conflict with another sensor.
;
;          If you don't have a particular entry for a sensor (i.e., you don't have cores 5/6/7/8),
;          then for that sensor you can use Entry IDs of "0x0" or you can leave the values as shown
;          as long as they don't conflict with another sensor.
;
;    NOTE: If HWiNFO reports that your system has a GPU #1 but does NOT show a GPU #0, or shows
;          limited data for GPU #0, then record the values shown in the Shared Memory Viewer for
;          GPU #1 against the GPU 0 variables below.  This situation can occur when you have
;          multiple GPUs and the first GPU (#0) is disabled and/or HWiNFO cannot wake it up (e.g.,
;          nVidia Optimus).
;
;    TIP:  An excellent detailed guide to working with the HWiNFO plugin can be found on the
;          Rainmeter forum here:  https://forum.rainmeter.net/viewtopic.php?f=118&t=21939
;
; 4. From the "Entry Details" section of the Shared Memory Viewer, locate the entry ID that
;    corresponds to the Entry ID variables below and change the hexadecimal values to match the
;    values shown in the Viewer.
;
;    Example:  The CPU core #0 temperature sensor variable shown below is:
;              HWiNFO-CPU0-DTS-Core0Temp=0x1000000
;
;              In the Viewer app, expand the "CPU [#0]: <your CPU name>: DTS" branch of the sensor
;              tree and look for a entry named "Core #0" and select it.  In the bottom left corner
;              of the Entry Details, highlight the hexadecimal ID value (0x1000000) and paste it as
;              the value of the "HWiNFO-CPU0-DTS-Core0Temp" variable in this file.
;
;    NOTE: If you can't find an Entry ID for a variable listed below in the Viewer, that may simply
;          mean that sensor is not available on your hardware, OR that the name of the sensor is
;          slightly different than shown.  (For example, I have a machine where the GPU fan is
;          shown as "GPU", another where it is shown as "System/GPU", and another where there is no
;          GPU fan sensor at all.)  Use a value of "0x0" if you don't have a particular sensor.
;
;    NOTE: Some systems may not have a sensor that reports fan usage as a percentage.  If your
;          system reports a fan's RPM but not percent usage, then you can have GPU Meter calculate
;          the percent usage for you.  In the GPU Meter Settings, check the "Calculate % Fan Usage"
;          option and enter your maximum fan speeds.
;
;    SPECIAL NOTE Regarding AMD GPUs:
;          As of this writing, certain newer AMD GPUs and drivers now support reporting the amount
;          of video RAM in use. HWiNFO v5.80 and later is required to monitor this value. AMD cards
;          do not report the amount of RAM as a percentage, nor do they report the total amount of
;          dedicated RAM that is installed. As a result, you must manually configure the settings
;          below to tell the GPU Meter how much dedicated RAM your card has available.
;
;          For older AMD and ATI video cards, and older versions of HWiNFO, you will not be able to
;          monitor the amount of RAM in use nor the total amount of RAM available. This is a known
;          limitation of ATI/AMD video cards, not an issue with HWiNFO, Rainmeter, or the GPU Meter.
;          The original addgadgets.com Sidebar Gadget did not report these values for AMD cards
;          either. You will need to set the Entry ID values for the "HWiNFO-GPUn-MemoryUsage" and
;          "HWiNFO-GPUn-MemoryAlloc" variables to "0x0" to disable them.
;
;    SPECIAL NOTE Regarding AMD CPUs:
;          As of this writing, some AMD CPUs do not report temperatures on a per-core basis; there
;          is only a single temperature sensor for the die and/or overall processor.  In this case,
;          your only option is to record the entry ID of the CPU temperature sensor against all the
;          cores.  This will result in the All CPU Meter gadget displaying the same temperature for
;          every core.
;
; 5. After you have gone through the annoying and painful process of mapping all the values, please
;    make a backup copy of this file and keep it in a safe location.  If you upgrade or reinstall
;    your Gadgets, this file will be replaced by the installer and your work will be lost (sorry).
;
;
; FINAL NOTE: Every CPU, motherboard, GPU, etc. WILL HAVE DIFFERENT SENSOR and ENTRY IDs.  Your PC
;             may not have one or more sensors available, or the names of the sensors may be
;             completely different.  Do not change the variable names, only the values. The values
;             below are examples only and are very likely different for your machine.  If your
;             Gadgets are not displaying any data, then double-check your settings below and make
;             sure the HWiNFO application is running AND the Sensors window is ALSO running.  Please
;             don't contact me if you don't see anything happening, because most likely it is your
;             configuration that is the issue.
;
; FINAL FINAL NOTE: If you have not read the above paragraph, now would be a good time. :^)
;

[Variables]

;------------------------------------------------------------------------------
; CPU #0
;

;
; Sensor ID and Instance
;
HWiNFO-CPU0-SensorId=0xf0000300
HWiNFO-CPU0-SensorInstance=0x0

;
; Entry IDs
;
HWiNFO-CPU0-Usage=0x7000019
HWiNFO-CPU0-Core0Thread0Usage=0x7000000
HWiNFO-CPU0-Core0Thread1Usage=0x7000001
HWiNFO-CPU1-Core0Thread0Usage=0x7000002
HWiNFO-CPU1-Core0Thread1Usage=0x7000003
HWiNFO-CPU2-Core0Thread0Usage=0x7000004
HWiNFO-CPU3-Core0Thread1Usage=0x7000005
HWiNFO-CPU3-Core0Thread0Usage=0x7000006
HWiNFO-CPU4-Core0Thread1Usage=0x7000007
HWiNFO-CPU4-Core0Thread0Usage=0x7000008
HWiNFO-CPU5-Core0Thread1Usage=0x7000009
HWiNFO-CPU5-Core0Thread0Usage=0x700000a
HWiNFO-CPU6-Core0Thread1Usage=0x700000b
HWiNFO-CPU6-Core0Thread0Usage=0x700000c
HWiNFO-CPU7-Core0Thread1Usage=0x700000d
HWiNFO-CPU7-Core0Thread0Usage=0x700000e
HWiNFO-CPU8-Core0Thread1Usage=0x700000f
HWiNFO-CPU8-Core0Thread0Usage=0x7000010
HWiNFO-CPU8-Core0Thread1Usage=0x7000011
HWiNFO-CPU9-Core0Thread0Usage=0x7000012
HWiNFO-CPU9-Core0Thread1Usage=0x7000013
HWiNFO-CPU10-Core0Thread0Usage=0x7000014
HWiNFO-CPU10-Core0Thread1Usage=0x7000015
HWiNFO-CPU11-Core0Thread0Usage=0x7000016
HWiNFO-CPU11-Core0Thread1Usage=0x7000017

HWiNFO-CPU0-Core0Clock=0x6000000
HWiNFO-CPU0-Core1Clock=0x6000001
HWiNFO-CPU0-Core2Clock=0x6000002
HWiNFO-CPU0-Core3Clock=0x6000003
HWiNFO-CPU0-Core4Clock=0x6000004
HWiNFO-CPU0-Core5Clock=0x6000005
HWiNFO-CPU0-Core6Clock=0x6000006
HWiNFO-CPU0-Core7Clock=0x6000007
HWiNFO-CPU0-Core8Clock=0x0
HWiNFO-CPU0-Core9Clock=0x0
HWiNFO-CPU0-Core10Clock=0x0
HWiNFO-CPU0-Core11Clock=0x0
HWiNFO-CPU0-Core12Clock=0x0
HWiNFO-CPU0-Core13Clock=0x0
HWiNFO-CPU0-Core14Clock=0x0
HWiNFO-CPU0-Core15Clock=0x0
HWiNFO-CPU0-Core16Clock=0x0
HWiNFO-CPU0-Core17Clock=0x0
HWiNFO-CPU0-Core18Clock=0x0
HWiNFO-CPU0-Core19Clock=0x0
HWiNFO-CPU0-Core20Clock=0x0
HWiNFO-CPU0-Core21Clock=0x0
HWiNFO-CPU0-Core22Clock=0x0
HWiNFO-CPU0-Core23Clock=0x0
HWiNFO-CPU0-Core24Clock=0x0
HWiNFO-CPU0-Core25Clock=0x0
HWiNFO-CPU0-Core26Clock=0x0
HWiNFO-CPU0-Core27Clock=0x0
HWiNFO-CPU0-Core28Clock=0x0
HWiNFO-CPU0-Core29Clock=0x0
HWiNFO-CPU0-Core30Clock=0x0
HWiNFO-CPU0-Core31Clock=0x0

;------------------------------------------------------------------------------
; CPU #0 DTS
; Some systems provide a separate sensor for addl. info, e.g. temperature
;

;
; Sensor ID and Instance
;
HWiNFO-CPU0-DTS-SensorId=0xf0000501
HWiNFO-CPU0-DTS-SensorInstance=0x0

;
; Entry IDs
;
HWiNFO-CPU0-DTS-CPUTemp=0x1000000
HWiNFO-CPU0-DTS-Core0Temp=0x1000000
HWiNFO-CPU0-DTS-Core1Temp=0x1000001
HWiNFO-CPU0-DTS-Core2Temp=0x1000002
HWiNFO-CPU0-DTS-Core3Temp=0x1000003
HWiNFO-CPU0-DTS-Core4Temp=0x1000004
HWiNFO-CPU0-DTS-Core5Temp=0x1000005
HWiNFO-CPU0-DTS-Core6Temp=0x1000006
HWiNFO-CPU0-DTS-Core7Temp=0x1000007
HWiNFO-CPU0-DTS-Core8Temp=0x0
HWiNFO-CPU0-DTS-Core9Temp=0x0
HWiNFO-CPU0-DTS-Core10Temp=0x0
HWiNFO-CPU0-DTS-Core11Temp=0x0
HWiNFO-CPU0-DTS-Core12Temp=0x0
HWiNFO-CPU0-DTS-Core13Temp=0x0
HWiNFO-CPU0-DTS-Core14Temp=0x0
HWiNFO-CPU0-DTS-Core15Temp=0x0
HWiNFO-CPU0-DTS-Core16Temp=0x0
HWiNFO-CPU0-DTS-Core17Temp=0x0
HWiNFO-CPU0-DTS-Core18Temp=0x0
HWiNFO-CPU0-DTS-Core19Temp=0x0
HWiNFO-CPU0-DTS-Core20Temp=0x0
HWiNFO-CPU0-DTS-Core21Temp=0x0
HWiNFO-CPU0-DTS-Core22Temp=0x0
HWiNFO-CPU0-DTS-Core23Temp=0x0
HWiNFO-CPU0-DTS-Core24Temp=0x0
HWiNFO-CPU0-DTS-Core25Temp=0x0
HWiNFO-CPU0-DTS-Core26Temp=0x0
HWiNFO-CPU0-DTS-Core27Temp=0x0
HWiNFO-CPU0-DTS-Core28Temp=0x0
HWiNFO-CPU0-DTS-Core29Temp=0x0
HWiNFO-CPU0-DTS-Core30Temp=0x0
HWiNFO-CPU0-DTS-Core31Temp=0x0


;------------------------------------------------------------------------------
; DIMM Temperature
;

;
; Sensor ID and Instance
;
HWiNFO-DIMM-SensorId=0xf3000002
HWiNFO-DIMM-SensorInstance=0x0

;
; Entry IDs
;
HWiNFO-DIMM0-Temp=0x1000000
HWiNFO-DIMM1-Temp=0x1000001
HWiNFO-DIMM2-Temp=0x1000002
HWiNFO-DIMM3-Temp=0x1000003

;------------------------------------------------------------------------------
; Motherboard
;

;
; Sensor ID and Instance
;
HWiNFO-MOBO-SensorId=0xf7067980
HWiNFO-MOBO-SensorInstance=0x0

;
; Entry IDs
;
HWiNFO-MOBO-SysTemp=0x1000000
HWiNFO-MOBO-Temp2=0x1000002
HWiNFO-MOBO-Temp3=0x1000003
HWiNFO-MOBO-Temp4=0x1000004
HWiNFO-MOBO-Temp5=0x1000005
HWiNFO-MOBO-CPUWeightTemp=0x1000006
HWiNFO-MOBO-CPUPackageTemp=0x1000007
HWiNFO-MOBO-CPUTemp=0x1000008
HWiNFO-MOBO-Temp9=0x1000009
HWiNFO-MOBO-CPUFan=0x3000001

;------------------------------------------------------------------------------
; AIO CPU Cooler
;

;
; Sensor ID and Instance
;
HWiNFO-AIO-SensorId=0xfc04a100
HWiNFO-AIO-SensorInstance=0x8

;
; Entry IDs
;
HWiNFO-AIO-CPUCoolantTemp=0x1000000
HWiNFO-AIO-Fan1=0x3000000
HWiNFO-AIO-Fan2=0x3000001
HWiNFO-AIO-CPUPump=0x3000002

;------------------------------------------------------------------------------
; Fan Controller
;

;
; Sensor ID and Instance
;
HWiNFO-FANC-SensorId=0xfc04a100
HWiNFO-FANC-SensorInstance=0x0

;
; Entry IDs
;
HWiNFO-FANC-Fan1=0x3000000
HWiNFO-FANC-Fan2=0x3000001
HWiNFO-FANC-Fan3=0x3000002
HWiNFO-FANC-Fan4=0x3000003
HWiNFO-FANC-Fan5=0x3000004
HWiNFO-FANC-Fan6=0x3000005

;------------------------------------------------------------------------------
; GPU #0
; (For AMD GPUs, see the special note in instruction step #4 above.)
; (HWiNFO and the Shared Memory Viewer may not show GPU #0 in cases where you 
; have a dedicated graphics card.)
;

;
; Sensor ID and Instance
;
HWiNFO-GPU0-SensorId=0xe0002000
HWiNFO-GPU0-SensorInstance=0x0

;
; Entry IDs
;

; GPU temperature (degrees)
HWiNFO-GPU0-Temp=0x1000000

HWiNFO-GPU0-CoreVoltage=0x2000000
HWiNFO-GPU0-GPUFan1=0x3000000
HWiNFO-GPU0-GPUFan2=0x3000001
HWiNFO-GPU0-Clock=0x6000000
HWiNFO-GPU0-MemoryClock=0x6000004

; GPU load (percent)
HWiNFO-GPU0-CoreLoad=0x7000000

; GPU memory usage (percent)
;   NOTE: for nVidia GPUs ONLY, this sensor reports the percentage of RAM in use
;   NOTE: for all AMD and Intel GPUs, you MUST set this value to 0x0 since this sensor does not exist
HWiNFO-GPU0-MemoryUsage=0x7000008

; GPU memory allocated (MB)
;   NOTE: for nVidia GPUs, set the following value to the ID of the "GPU Memory Allocated" sensor (i.e., amount of VRAM allocated, in megabytes)
;   NOTE: for *some* AMD GPUs, set the following value to the ID of the "GPU Memory Usage" sensor (i.e., amount of VRAM allocated, in megabytes)
;   NOTE: for *most* AMD GPUs, set the following value to 0x0 since there is no sensor available to report allocated VRAM
;   NOTE: for Intel GPUs, set the following value to 0x0 since there is no sensor available to report allocated VRAM
HWiNFO-GPU0-MemoryAlloc=0x80000fc

; GPU fan usage (percent, not RPM!)
;   IMPORTANT:  If your GPU sensor does not report fan usage, see below to set FanCalcMethod=1
HWiNFO-GPU0-FanSpeed=0x8000000

; GPU #0 RAM: for AMD GPUs, enter the total amount of dedicated RAM in megabytes (1 GB = 1024 MB)
;             for nVidia GPUs, you MUST set this value to 0 (zero)
;             for Intel GPUs, you MUST set this value to 0 (zero), as these GPUs have no dedicated RAM.
GPU0-MemoryTotal=0

;------------------------------------------------------------------------------
; GPU #1
; (For AMD GPUs, see the special note in instruction step #4 above.)
;

;
; Sensor ID and Instance
;
HWiNFO-GPU1-SensorId=0xe0002000
HWiNFO-GPU1-SensorInstance=0x14

;
; Entry IDs
;
; GPU core clock frequency (MHz)
HWiNFO-GPU1-Clock=0x6000000
; GPU temperature (degrees)
HWiNFO-GPU1-Temp=0x1000000
; GPU load (percent)
HWiNFO-GPU1-CoreLoad=0x7000000
; GPU memory clock frequency (MHz)
HWiNFO-GPU1-MemoryClock=0x6000004
; GPU memory usage (percent)
;   NOTE: for nVidia GPUs ONLY, this sensor reports the percentage of RAM in use
;   NOTE: for all AMD and Intel GPUs, you MUST set this value to 0x0 since this sensor does not exist
HWiNFO-GPU1-MemoryUsage=0x7000008
; GPU memory allocated (MB)
;   NOTE: for nVidia GPUs, set the following value to the ID of the "GPU Memory Allocated" sensor (i.e., amount of VRAM allocated, in megabytes)
;   NOTE: for *some* AMD GPUs, set the following value to the ID of the "GPU Memory Usage" sensor (i.e., amount of VRAM allocated, in megabytes)
;   NOTE: for *most* AMD GPUs, set the following value to 0x0 since there is no sensor available to report allocated VRAM
;   NOTE: for Intel GPUs, set the following value to 0x0 since there is no sensor available to report allocated VRAM
HWiNFO-GPU1-MemoryAlloc=0x80000fc
; GPU fan usage (percent, not RPM!)
;   IMPORTANT:  If your GPU sensor does not report fan usage, see below to set FanCalcMethod=1
HWiNFO-GPU1-FanSpeed=0x8000000
; GPU core voltage (volts)
HWiNFO-GPU1-CoreVoltage=0x2000000
; GPU fan speed (RPM) as reported by the GPU1 sensor
;   IMPORTANT:  If your GPU sensor reports fan speed, see the motherboard GPU fan sensor note above.
HWiNFO-GPU1-GPUFan=0x3000000

; GPU #1 RAM: for AMD GPUs, enter the total amount of dedicated RAM in megabytes (1 GB = 1024 MB)
;             for nVidia GPUs, you MUST set this value to 0 (zero)
;             for Intel GPUs, you MUST set this value to 0 (zero), as these GPUs have no dedicated RAM.
GPU1-MemoryTotal=0

;------------------------------------------------------------------------------
; SSD #0
;

;
; Sensor ID and Instance
;
HWiNFO-SSD0-SensorId=0xf0000100
HWiNFO-SSD0-SensorInstance=0x0

;
; Entry IDs
;
HWiNFO-SSD0-Temp=0x1000000


;------------------------------------------------------------------------------
; SSD #1
;

;
; Sensor ID and Instance
;
HWiNFO-SSD1-SensorId=0xf0000100
HWiNFO-SSD1-SensorInstance=0x1

;
; Entry IDs
;
HWiNFO-SSD1-Temp=0x1000000


;------------------------------------------------------------------------------
;
; maximum fan speeds (used for hardware that cannot report fan usage as a percentage)
;
; NOTE: If higher fan speeds than shown here are encountered, GPU Meter/All CPU Meter will
;       automatically correct these values to the new maximum speed if FanMaxAutoUpdate is set to 1.
;
; NOTE: Set FanMaxAutoUpdate=0 to prevent GPU Meter/All CPU Meter from adjusting the maximum values.
;
; NOTE: Some systems do not report GPU fan usage (i.e., the percentage of the maximum fan speed).
;       The GPU Meter will calculate the percent utilization for you using the maximum fan speed
;       values.  The calculation is controlled by the FanCalcMethod variable.  Note that this
;       applies to the GPU Meter gadget only; the All CPU Meter gadget must always calculate the
;       percent usage for the CPU fan since neither HWiNFO nor SpeedFan can report this value.
;
;       FanCalcMethod 0 = Hardware/HWiNFO reports percentages.
;       FanCalcMethod 1 = GPU Meter will calculate percentages.
;
FanCalcMethod=1
FanCpuMax=500
FanGpuMax=500
FanMaxAutoUpdate=1
