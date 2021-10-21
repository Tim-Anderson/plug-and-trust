/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (C) Foundries Ltd. 2020 - All Rights Reserved
 * Author: Jorge Ramirez <jorge@foundries.io>
 */

#ifndef ADAPTORS_H
#define ADAPTORS_H

#include <der.h>
#include <fsl_sss_api.h>
void add_ecc_header(uint8_t *, size_t *, uint8_t **, size_t *, uint32_t id);
void get_ecc_raw_data(uint8_t *, size_t, uint8_t **, size_t *, uint32_t id);

#endif /* ADAPTORS_H */
