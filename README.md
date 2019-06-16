# Eigen in Intel SGX 

A sample code of how to use Eigen (C++ linear algebra template headers) in Intel SGX. This sample code modifies `linux-sgx`'s [SampleEnclave](https://github.com/intel/linux-sgx/tree/master/SampleCode/SampleEnclave).

## How to Build/Execute the Sample Code
1. Install Intel(R) SGX SDK for Linux* OS

2. Make sure your environment is set:
    ```$ source ${sgx-sdk-install-path}/environment```
    
3. Locate the following files in system directories and copy them over to `Include/intrinsic`. Usually, they are located in gcc's include directory (e.g. `/usr/lib/gcc/x86_64-linux-gnu/6.5.0/include`).
    * `emmintrin.h`  
    * `mmintrin.h`  
    * `mm_malloc.h`  
    * `xmmintrin.h`
4. Download [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) and copy the header templates directory (i.e. `Eigen/`) into `Include/`.
5. Build the project with the prepared Makefile:

    a. Hardware Mode, Debug build:
        ```$ make```
        
    b. Hardware Mode, Pre-release build:
        ```$ make SGX_PRERELEASE=1 SGX_DEBUG=0```
        
    c. Hardware Mode, Release build:
        ```$ make SGX_DEBUG=0```
        
    d. Simulation Mode, Debug build:
        ```$ make SGX_MODE=SIM```
        
    e. Simulation Mode, Pre-release build:
        ```$ make SGX_MODE=SIM SGX_PRERELEASE=1 SGX_DEBUG=0```
        
    f. Simulation Mode, Release build:
        ```$ make SGX_MODE=SIM SGX_DEBUG=0```
        
6. Execute the binary directly:
    ```$ ./app```
    
7. Remember to `make clean` before switching build mode

## How to Use Eigen in any SGX Projects
Copy `Enclave/shim.hpp` to your project. Make sure `shim.hpp`, `Eigen`, and the files listed in step 3 are all visible during compilation. Any time an Eigen header is `#include`'d in a file, make sure to include `shim.hpp` *above* it. 
