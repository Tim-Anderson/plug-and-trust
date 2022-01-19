.. title:

OP-TEE Enabled Plug and Trust
=============================

This repository provides the functionality required by the OP-TEE Trusted Execution Environment to access the NXP EdgeLock™ SE05X_: Plug & Trust Secure Element 

The relevant OP-TEE driver can be found at https://github.com/OP-TEE/optee_os/tree/master/core/drivers/crypto/se050

The stack has been validated on iMX8mm and iMX6ull platforms fitted with the ARD SE050 https://www.nxp.com/products/security-and-authentication/authentication/edgelock-se050-development-kit:OM-SE050X for the following operations::

   * RSA 2048, 4096 encrypt/decrypt/sign/verify
   * ECC sign/verify
   * AES CTR 
   * RNG
   * SCP03 (i2c communications between the processor and the device are encrypted)
   * DieID generation
   * cryptoki integration

Using the Plug and Trust Repository
===================================


There are two distinct ways of using this repository depening on the target OP-TEE version.
For sample build lines check OP-TEE/ .azure-pipelines.yml


From Release Plug-and-Trust v0.1.0 and OP-TEE 3.16
--------------------------------------------------


Follow the instructions in OP-TEE/core/drivers/crypto/se050/README.txt



From Release Plug-and-Trust v0.0.1 and OP-TEE 3.11
---------------------------------------------------


From the optee_lib directory do as follows:

For arm64::
 
 $ mkdir build
 $ cd build
 $ cmake -DCMAKE_C_FLAGS="-mstrict-align -mgeneral-regs-only" -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc -DOPTEE_TREE=/path/to/optee/ ..
 $ make 

For arm::

 $ mkdir build
 $ cd build
 $ cmake -DCMAKE_C_COMPILER=arm-linux-gnueabi-gcc -DOPTEE_TREE=/path/to/optee/ ..
 $ make


Then build OP-TEE linking against the library generated with the above cmake command. 



.. _SE05X: https://www.nxp.com/docs/en/data-sheet/SE050-DATASHEET.pdf 


Have fun::

            _  _
           | \/ |
        \__|____|__/
          |  o  o|           Thumbs Up
          |___\/_|_____||_
          |       _____|__|
          |      |
          |______|
          | |  | |
          | |  | |
          |_|  |_|


Foundries.io

