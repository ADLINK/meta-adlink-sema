<img src ="https://material.adlinktech.com/en/Upload/ProductNews/logo_sema.png" width="200" align="right" />


<br>

## Smart Embedded Management Agent ##
### SEMA 3.6 R0 offers a broad spectrum of enhanced functionality to improve system reliability and ease system integration


At the heart of SEMA is the Board Management Controller (BMC) supporting SEMA functions. The SEMA Extended EAPI provides access to all functions and can be integrated into the user’s own applications. The SEMA GUI and SEMA Command Line Interface allow monitoring, control and use of the SEMA parameters and functions directly on your device for test and demonstration purposes. 


#### Comprised of the following components:  ####
- Board Management Controller HW and FW
- Extended EAPI Library
- SEMA GUI
- SEMA Command Line Interface (CLI)

#### Provides the following functions and information: ####
- CPU Operation Modes
- Memory Information
- Network Information
- ACPI Power Management
- HDD S.M.A.R.T
- BIOS Updates
- Heartbeat
- Power Consumption
- User Area Access
- I2C Bus Control
- Temperatures(CPU and Board)
- Board Information (Serial Number, Part Number, Firmware Version...)
- Fan Control
- GPIO Control
- 1-Wire Bus
- A/D Conversion


|      **The SEMA GUI graphical interface**                  |       **The SEMA command line interface**                    |
|:---: |:---: |
|<div style="text-align:right"><img src ="https://material.adlinktech.com/products/images/1274/SEMA_Graphics_Interface.png" width="300" /></div>|<div style="text-align:right"><img src ="https://material.adlinktech.com/products/images/1274/SEMA_Command_Interface.png" width="300" /></div>|
 

If need more details about SEMA 3.6.0, please refer the following link: <a href="https://www.adlinktech.com/Products/Industrial_IoT_and_Cloud_solutions/SEMA_Smart_Embedded_Management_Agent/SEMA?lang=en" title="Title">click me!</a>  


 

<br>


Guideline to add layer into your BSP: 
----

**1. fetch the source from the following git location:**

	git clone https://github.com/adlink/meta-adlink-sema


**2. add the following script into your configuration:**

&nbsp;&nbsp;2.1 add "meta-adlink-sema" layer into bblayers.conf file.

&nbsp;&nbsp;2.2 add application & library into local.conf file:

	IMAGE_INSTALL_append = " sema semagui-desktop libstdc++ trolltech"


&nbsp;&nbsp;**Note**: <br>&nbsp;&nbsp;&nbsp;&nbsp;-  Linux kernel  >= 3.2.x (32 bit & 64 bit) <br>&nbsp;&nbsp;&nbsp;&nbsp;-  support platform: x86 32bit & 64bit, ARM 32bit & 64bit



<br>
<br>
Please feel free to send us (email: ryanzj.huang@adlinktech.com) patches for this layer and report bugs of this layer. <br>For hardware support, please contact your local representative.
