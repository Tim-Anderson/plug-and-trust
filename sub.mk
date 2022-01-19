include ${CFG_NXP_SE05X_PLUG_AND_TRUST}/cflags.mk

cflags-y += -Wno-error
cflags-y += -Wno-implicit-function-declaration
cflags-y += -Wno-suggest-attribute=format
cflags-y += -Wno-unused-result

incdirs-y += optee_lib/include
incdirs-y += hostlib/hostLib/inc/
incdirs-y += hostlib/hostLib/libCommon/infra/
incdirs-y += hostlib/hostLib/libCommon/smCom/
incdirs-y += hostlib/hostLib/libCommon/smCom/T1oI2C/
incdirs-y += hostlib/hostLib/platform/inc/
incdirs-y += hostlib/hostLib/se05x_03_xx_xx/
incdirs-y += sss/inc/
incdirs-y += sss/ex/inc/
incdirs-y += sss/port/default/

srcs-y += hostlib/hostLib/libCommon/smCom/smComT1oI2C.c
srcs-y += hostlib/hostLib/libCommon/smCom/T1oI2C/phNxpEse_Api.c
srcs-y += hostlib/hostLib/libCommon/smCom/T1oI2C/phNxpEseProto7816_3.c
srcs-y += hostlib/hostLib/libCommon/infra/sm_connect.c
srcs-y += hostlib/hostLib/libCommon/infra/sm_apdu.c
srcs-y += hostlib/hostLib/libCommon/infra/global_platf.c
srcs-y += hostlib/hostLib/libCommon/nxScp/nxScp03_Com.c
srcs-y += hostlib/hostLib/se05x_03_xx_xx/se05x_APDU.c
srcs-y += hostlib/hostLib/se05x/src/se05x_mw.c
srcs-y += hostlib/hostLib/se05x/src/se05x_tlv.c
srcs-y += hostlib/hostLib/se05x/src/se05x_ECC_curves.c
srcs-y += sss/src/fsl_sss_util_rsa_sign_utils.c
srcs-y += sss/src/fsl_sss_util_asn1_der.c
srcs-y += sss/src/se05x/fsl_sss_se05x_policy.c
srcs-y += sss/src/se05x/fsl_sss_se05x_mw.c
srcs-y += sss/src/se05x/fsl_sss_se05x_apis.c
srcs-y += sss/src/se05x/fsl_sss_se05x_scp03.c
srcs-y += optee_lib/glue/stubs.c
srcs-y += optee_lib/glue/wraps.c
srcs-y += optee_lib/glue/i2c.c
srcs-y += optee_lib/glue/smCom.c
srcs-y += optee_lib/glue/user.c
srcs-y += optee_lib/glue/der.c
srcs-y += optee_lib/glue/apdu.c
