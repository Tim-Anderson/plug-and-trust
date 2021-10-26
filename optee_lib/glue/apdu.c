// SPDX-License-Identifier: BSD-3-Clause
/*
 * Copyright (C) Foundries Ltd. 2021 - All Rights Reserved
 * Author: Jorge Ramirez <jorge@foundries.io>
 */

#include <apdu.h>
#include <string.h>

sss_status_t sss_se05x_do_apdu(Se05xSession_t *ctx,
			       enum se050_apdu_type type,
			       uint8_t *header, size_t hdr_len,
			       uint8_t *src_data, size_t src_len,
			       uint8_t *dst_data, size_t *dst_len)
{
	smStatus_t status = SM_NOT_OK;
	tlvHeader_t hdr = { 0 };

	if (hdr_len != 4)
		return kStatus_SSS_Fail;

	hdr.hdr[0] = *(header + 0);
	hdr.hdr[1] = *(header + 1);
	hdr.hdr[2] = *(header + 2);
	hdr.hdr[3] = *(header + 3);

	switch (type) {
	case SE050_APDU_NONE:
		status = DoAPDUTxRx(ctx, src_data, src_len, dst_data, dst_len);
		break;
	case SE050_APDU_TYPE_0:
	case SE050_APDU_TYPE_1:
	case SE050_APDU_TYPE_2:
		status = DoAPDUTxRx_s_Case2(ctx, &hdr, src_data, src_len,
					    dst_data, dst_len);
		break;
	case SE050_APDU_TYPE_3:
	case SE050_APDU_TYPE_5:
		status = DoAPDUTxRx_s_Case4(ctx, &hdr, src_data, src_len,
					    dst_data, dst_len);
		break;
	case SE050_APDU_TYPE_4:
	case SE050_APDU_TYPE_6:
		status = DoAPDUTxRx_s_Case4_ext(ctx, &hdr, src_data, src_len,
						dst_data, dst_len);
		break;
	default:
		return kStatus_SSS_Fail;
	}

	if (status != SM_OK)
		return kStatus_SSS_Fail;

	return kStatus_SSS_Success;
}
