module switch PrgEnv-pgi PrgEnv-gnu
module load fftw
module load scorep/.4.0-dev-libwrap

export PE_PKGCONFIG_PRODUCTS="$(echo $PE_PKGCONFIG_PRODUCTS | sed "s/PE_FFTW//g")" # switches off auto include and link for fftw in cc
