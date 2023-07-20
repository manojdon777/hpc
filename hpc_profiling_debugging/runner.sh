#!/bin/bash

set -e
# source /opt/intel/oneapi/setvars.sh

COMPILERS=('gcc icx')
OPTIONS=('-O0 -O1 -O2 -O3 -Ofast')
CBLAS_LIB="/home/hpcap/WRF_TARS_DIR/lapack-3.11.0/"
CBLAS_INC="/home/hpcap/WRF_TARS_DIR/lapack-3.11.0/CBLAS/include/"

for comp in ${COMPILERS}
do
	for opt in ${OPTIONS}
	do
		if [ "${comp}" = "icx" ];
		then
			source /opt/intel/oneapi/setvars.sh	--force 2>&1 > /dev/null
			OPT_FLAG="${opt} -DINTEL"
			LIB="-qmkl"
		else
			OPT_FLAG="${opt} -L${CBLAS_LIB} -I${CBLAS_INC}"
			LIB="-lcblas -lrefblas -lgfortran"
			
		fi
		echo "Executing : ${comp} ${OPT_FLAG} matmul_vinit_sir_blas_dgemm.c ${LIB}"
		${comp} ${OPT_FLAG} matmul_vinit_sir_blas_dgemm.c ${LIB}
		echo "Running executable:"
		./a.out
	done
done

