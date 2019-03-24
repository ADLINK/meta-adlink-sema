
SEMA 3.5 R9, Release Feb/ 2018    
===============================

A. History
----------
2014-07-31: (mg) Initial release
2014-11-27: (sb) Added 2.5 changes
2015-08-28: (fk) Added 3.0 changes
2016-05-17: (fk) Added 3.0 R7 changes
2016-08-24: (fk) Added 3.5 changes
2016-12-08: (at) Added 3.5 R7 changes
2017-06-15: (at) Added 3.5 R8 changes
2018-02-02: (at) Added 3.5 R9 changes
----------

B. Introduction
---------------
SEMA (Smart Embedded Management Agent) is ADLINK's intelligent middleware to 
enable you to speed up your system design and to help you monitoring your 
system's health condition at any time.

SEMA 3.X introduces a new API interface called SemaEAPI. It extended the PICMG 
EAPI spec and adds the remote function call. For more detailed information, 
please refer to "SEMA3.5_Extended_EAPI_Programming_Guide.pdf".
The old SEMA API and libraries still kept for the backward compatibility. 

Please note that some features supported in SEMA 2.x will be remove from 
SEMA3.5.
	1.The SMBus is not support in SemaEAPI

If customer's design already implements them, please keep using the old API.

Old sema libraries, dlls and include files still remained for backward compatible.
Customer could use them after installing the SEMA 3.5 package.

This document will talk about supported operating systems, CPU / chipsets as well 
as how to use the binaries, libraries and header files.
---------------

C. Getting Help
---------------
If you need any assistance or support, please contact your local sales or support representative.
You may also insert any incident into our global support system, calls Ask An Expert (AAE).
http://askanexpert.adlinktech.com/AAE/Login2.aspx?ReturnUrl=%2fAAE%2fAskAQuestion.aspx
---------------

D. Supported Operating Systems
------------------------------
X86:
	.Windows 7 (32/64bit) System Service Pack1
	.Windows 8/8.1 (32/64bit)
	.Windows 10 IoT Enterprise (32/64bit)
	.Linux (32/64bit, kernel 3.2.x or higher)


------------------------------
		
E. Supported CPUs / Chipsets
----------------------------
Intel:
	.Intel(R) Calistoga Family (945GSE)
	.Intel(R) Montevina Family (GS45/GM45)
	.Intel(R) Calpella Family (QM57)
	.Intel(R) SandyBridge Family (QM67)
	.Intel(R) IvyBridge Family (QM77)
	.Intel(R) Haswell Family (QM87)
	.Intel(R) Broadwell Family (QM97)
	.Intel(R) Menlow Family (Atom 1st Gen)
	.Intel(R) TunnelCreek Family (Atom 2nd Gen)
	.Intel(R) CedarView Family (Atom 3rd Gen)
	.Intel(R) BayTrail Family (Atom 4th Gen)
	.Intel(R) Braswell Family
	.Intel(R) Skylake  Family
	.Intel(R) Apollolake Family
	.Intel(R) Cannon Lake and Coffee Lake Family
	.Intel(R) Denverton Product Family (Cormorant Lake)

AMD:
	.AMD(R) LX800 Family (Geode)
	.AMD(R) G-Series Family (Fusion)
	.AMD(R) BaldEagle Family

ARM:
	Freescale i.MX6
----------------------------

F. Installing the Binary Applications
--------------------------------------
Linux (32/64bit)
		Please refer to "SEMA 3.5 Software Installation Guide.pdf"
		Note:If SEMA is operated in a Linux environment, the standard SMBus 
		driver must be unloaded. Otherwise, this driver and SEMA will conflict.
	
Windows 7 / 8 / 8.1 /10 (32/64bit)
		Please refer to "SEMA 3.5 Software Installation Guide.pdf"
		

--------------------------------------

G. Using the Libraries in own Projects
--------------------------------------
Linux:
	a. Copy the headers files you need to your project directory
	Note: You will have to include all header files in "include/" .
 
	b. Copy all libraries to /usr/local/lib on your development environment
	c. Add sema libraries to config path:
		i. echo /usr/local/lib/ > /etc/ld.so.conf.d/libsema.conf
		ii. ldconfig
		Note: Step (c.) may vary depending on your distribution.
		
Windows 7 / 8 /10:
	a. Copy the header files you need to your project directory
	b. Copy the libraries and DLLs (can be found inside the lib\ folder)
	   into your project directory
	c. Setup the correct PATH for include file and libraries in Visual Studio or CMake files

--------------------------------------

H. DEMO Projects
----------------
Linux: 
	a. Setup development environment
		1. Make sure the gcc is installed properly
		2. Download the CMake 3.0 and setup
		3. Unzip sample code sema3_samples_linuxXX.zip	(XX = 32 or 64)
		4. Set libraries link 
			Use setlink.sh
			> cd /sema3_samples_linuxXX/lib
			> chmod +x setlink.sh  (Change the access permission to an executable file with chmod command)
			>./setlink.sh
	b. Build the project
		1.Generate makefiles
			use cmake to generate makefiles
			>cd /sema3_samples_linuxXX
			>cmake . -DCMAKE_BUILD_TYPE=Release
		2.Build the sample code
			Use make command to make samples
			>make
ARM: 
	a. Setup development environment
		1. Make sure the gcc is installed properly
		2. Download the CMake 3.0 and setup
		3. Unzip sample code sema3_samples_arm.zip
		4. Set libraries link 
			Use setlink.sh
			> cd /sema3_samples_arm/lib
			> chmod +x setlink.sh  (Change the access permission to an executable file with chmod command)
			>./setlink.sh
	b. Build the project
		1.Generate makefiles
			use cmake to generate makefiles
			>cd /sema3_samples_linuxXX
			>cmake . -DCMAKE_BUILD_TYPE=Release
		2.Build the sample code
			Use make command to make samples
			>make

Windows 7 / 8 /10:
	a. Setup development environment
		1.Download the Visual Studio Express 2012 and setup
		2.Download the CMake 3.0 and setup
		3.Unzip sample code sema3_samples_windowsXX.zip	(XX = 32 or 64)
			C:\sema3_samples_winXX
	b. Build the project
		1.Open Developer Command Prompt for VS2012
			Click Start, point to All Programs, 
			point to Microsoft Visual Studio, 
			point to Visual Studio Tools, and then click Visual Studio Command Prompt.
		2.Generate nmake makefile
			use cmake to generate nmake makefiles
			>cd C:\sema3_samples_winXX
			>cmake . -DCMAKE_BUILD_TYPE=Release -G "NMake Makefiles"
		3.Build the sample code
			Use nmake command to make samples
			>nmake

--------------------------------------

I. Backward compatibility with SEMA 2.5
----------------
.Linux (32/64bit)
	Note: To run "semagui" properly you will have to install the Qt libraries (Qt4 or Qt5) using
	your distribution package manager (e.g. apt for Debian)
	a. Install SEMA 2.5	
		1. Copy "sema" and "semagui_qt(4/5)" (depending on your Qt version) to /usr/local/bin
		2. Copy "libsema.so.2.5" and "libsema_hwlinux.so.1.4" and "libEApiLAT.so.1.0" to /usr/local/lib
		3. Add sema libraries to config path:
			i. echo /usr/local/lib/ > /etc/ld.so.conf.d/libsema.conf
			ii. ldconfig
		Note: Step (3) may vary depending on your distribution.
	b. Updae SEMA new driver from SEMA 3.5
		Copy the "libsema.so.3.5" and "libsema_hwlinux.so.1.7" under SEMA3.5/lib/linuxXX (XX=32 or 64) to /usr/local/lib
		>rm /usr/local/lib/libsema.so.2.5
		>rm /usr/local/lib/libsema_hwlinux.so.1.4
		>cp /SEMA3.5/lib/linuxXX/libsema.so.3.5 /usr/local/lib/		(XX = 32 or 64)
		>cp /SEMA3.5/lib/linuxXX/libsema_hwlinux.so.1.7 /usr/local/lib/    (XX = 32 or 64)
	c. Create symbol link for "libsema.so.3.5" 
		>ln -s /usr/local/lib/libsema.so.3.5 /usr/local/lib/libsema.so.2.5 
		>ln -s /usr/local/lib/libsema_hwlinux.so.1.7 /usr/local/lib/libsema_hwlinux.so.1.4
	d. Add LD_LIBRARY_PATH="/usr/local/lib" to system environment
		edit /etc/bash.bashrc
		add export LD_LIBRARY_PATH="/usr/local/lib" in the last line
		>source /etc/bash.bashrc
		Note: This step may vary depending on your distribution.
	d. Reflash the library configuration
		>ldconfig

Windows 7 / 8 /10:
	[Intel and AMD chipset]
	a. Install the SEMA 2.5 QT5 version.
	b. Install the latest driver
		double click the driver installpackage on \binaries\win32\SEMA_driver_x86.msi or \binaries\win64\SEMA_driver_x64.msi
	c. Copy the "libsema.dll" to C:\Program Files (x86)\Sema 

	note: The windows installation procedure only support the SEMA 2.5 QT5. 

	[Vortex86 chipset (CM1-DX2,CM1-DX3)]
	a. Install the SEMA 2.5 QT4 version.
	b. Install the latest driver
		double click the driver installpackage on \binaries\win32\SEMA_driver_x86.msi or \binaries\win64\SEMA_driver_x64.msi
	
--------------------------------------	
J. Note
----------------
	a.From 3.0 R7 on the external I2C supports 16bits command. However, this requires a BMC firmware modification. 
    	If the products are released before 2016, please contact ADLINK support team for the BMC firmware customization.
	b. BIOS updates are supported for AMI BIOS and for Windows operating systems environments only. 
	For Linux support or if you have any other questions or problems to update BIOS please contact the ADLINK support team.
    	c.In Windows 7 and Windows Server 2008 R2, please update Service Pack 1 and install Windows Patch KB3033929 for driver digital signature.
    	Link : https://technet.microsoft.com/en-us/en-en/library/security/3033929.aspx	
	d. Some new features introduced with SEMA 3.5, e.g. Logging of Power-Up Errors, A/D Conversion, 1-Wire support or Soft Fan, require corresponding support of updated BMC FW. 
	Please contact ADLINK support team in case your current BMC FW does not support desired features yet.  
	e. S.M.A.R.T. Disk tool doesn't support RAID controller. If operation system has installed RAID controller driver, the information about disk and S.M.A.R.T. will be abnormal.
	f. In Linux, SEMA doesn't support BIOS update. If the customer has already obtained a license  for Linux BIOS update tool from AMI and would like to use the SEMA BIOS update function, the steps are as follows,
		f.1 Modify the file name: afulnx_32 for 32-bit or afulnx_64 for 64-bit
		f.2 Copy file to /usr/local/SEMA/bin
		f.3 Change the access permission to an executable file with chmod command

--------------------------------------	
K. Licenses
----------------
	a.Using SEMA software is subject to SEMA Free Software License Agreement". Please refer to respective file in in the SEMA installation directory
	b.The SEMA Graphical User Interface (SEMA GUI) software is released and provided under the GNU General Public License Version 3 (GPLv3) terms. 
	(https://www.gnu.org/licenses/gpl-3.0.txt) Please contact ADLINK support team, if source code of SEMA GUI is required.   
		b.1 SEMA Graphical User Interface (SEMA GUI) software contains or is accompanied by certain third party open source software. Such third party software is subject to the respective third party license terms. Overview of third party software used by SEMA GUI:
		b.1.1 Python 2.7 (https://www.python.org/download/releases/2.7/), included components, license: Python 2.7 license (https://www.python.org/download/releases/2.7/license/)
		b.1.2 PyQt (https://wiki.python.org/moin/PyQt), included components, license: GPL v3 (https://www.gnu.org/licenses/gpl-3.0.en.html)
		b.1.3 Qt (http://www.qt.io/licensing/), included library, license: GNU Lesser General Public License v. 3 (LGPL) (https://www.gnu.org/licenses/lgpl-3.0.en.html).
	c. SEMA software contains and is accompanied by certain third party software and third party open source software. Such third party software is subject to the respective third party license terms. Overview of third party software used:
		c.1. smartmontools (https://www.smartmontools.org/), accompanying tool, license: GPLv2 (https://www.gnu.org/licenses/gpl-2.0.txt)
		c.2. MQTT client API (http://git.eclipse.org/c/paho/org.eclipse.paho.mqtt.c.git), accompanying library, license: EDL (Eclipse Distribution License Version 1.0, http://www.eclipse.org/org/documents/edl-v10.php )
		c.3. log4cpp (http://log4cpp.sourceforge.net ), accompanying library, license: LGPL (https://www.gnu.org/licenses/lgpl-3.0.en.html )
		c.4. OpenSSL (https://www.openssl.org/); accompanying library; license: OpenSSL specific license (https://www.openssl.org/source/license.txt)
		c.5. Protocolbuffer (https://github.com/google/protobuf/blob/master/LICENSE), included component, license: Google Protocol Buffer license (https://github.com/google/protobuf/blob/master/LICENSE)
		c.6. EAPI header file (https://www.picmg.org/wp-content/uploads/COM_EAPI_R1_0.pdf), accompanying library, license: 2-Clause BSD License (http://opensource.org/licenses/bsd-license.php) 
		c.7. AMI Firmware Update tool for BIOS-updates (https://ami.com/en/?Aptio_V_AMI_Firmware_Update_Utility.zip), accompanying tool, license: see EULA-for-AFUWIN-ADLink-20140902.pdf file in SEMA SW package.

