Build Instructions of LINALG examples:

1. Following environment vaialbes must be set in order to build LINALG (version numbers are used as examples):
      export CGTROOT="<TI_CGT_INSTALLATION_ROOT>/cgt-c6x"
      export PDK_DIR="<COMPONENTS_INSTALLATION_ROOT>/pdk_c667x_2_0_1"
      export FC_DIR="<COMPONENTS_INSTALLATION_ROOT>/framework_components_3_40_01_04"
      export XDAIS_DIR="<COMPONENTS_INSTALLATION_ROOT>/xdais_7_24_00_04"
      export BIOS_DIR="<COMPONENTS_INSTALLATION_ROOT>/bios_6_45_01_29"
      export OMP_DIR="<COMPONENTS_INSTALLATION_ROOT>/openmp_dsp_c667x_2_02_00_02"
      export XDC_DIR="<COMPONENTS_INSTALLATION_ROOT>/xdctools_3_32_00_06_core"
      export IPC_DIR="<COMPONENTS_INSTALLATION_ROOT>/ipc_3_42_00_02"
      export EDMA3_DIR="<COMPONENTS_INSTALLATION_ROOT>/edma3_lld_02_12_01_23"
      export LIBARCH_DIR="<COMPONENTS_INSTALLATION_ROOT>/libarch_1_0_0_0"
      export LINALG_DIR="<COMPONENTS_INSTALLATION_ROOT>/linalg_1_2_0_0"
      export PATH=<TI_CGT_INSTALLATION_ROOT>/cgt-c6x/bin:$PATH
2. Issue command to build the examples:
      make TARGET=<target_name>
      where: <target_name> must be one of SOC_K2H, SOC_C6678, or SOC_AM572x

