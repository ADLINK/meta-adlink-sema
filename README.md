<div style="text-align:right"><img src ="https://material.adlinktech.com/en/Upload/ProductNews/logo_sema.png" width="300" /></div>


## Smart Embedded Management Agent ##
### SEMA 3.5 R9 offers a broad spectrum of enhanced functionality to improve system reliability and ease system integration.###


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
 

If need more details about SEMA 3.5.9, please refer the following link: <a href="https://www.adlinktech.com/Products/Industrial_IoT_and_Cloud_solutions/SEMA_Smart_Embedded_Management_Agent/SEMA?lang=en" title="Title">click me!</a>  


 

<br>
<br>


#### Guideline to add meta-adlink-seam into your BSP:  ####
**1) Fetch the source from various git location:**
>git clone http://git.adlinktech.com/sema/meta-adlink-sema

<br>**2) Add the following script into your Yocto configuration:**

2.1) Add "meta-adlink-sema" layer into bblayers.conf file.

2.2) Add SEMA application into local.conf file:
>IMAGE_INSTALL_append = " sema semagui-desktop libstdc++ trolltech"


**Note**: <br> Support Linux kernel version >= 3.2.x for 32/64 bit <br> current support platform: x86_32bit/x86_64bit/arm_32bit



<br>
<br>
**Please feel free to send us (email: ryanzj.huang@adlinktech.com) patches for this layer and report bugs of this layer. <br>For hardware support, please contact your local representative.**