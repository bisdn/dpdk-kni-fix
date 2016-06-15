/*-
 *   BSD LICENSE
 *
 *   Copyright(c) Broadcom Limited.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Broadcom Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _BNXT_HWRM_H_
#define _BNXT_HWRM_H_

#include <inttypes.h>
#include <stdbool.h>

struct bnxt;
struct bnxt_filter_info;
struct bnxt_cp_ring_info;

#define HWRM_SEQ_ID_INVALID -1U

int bnxt_hwrm_clear_filter(struct bnxt *bp,
			   struct bnxt_filter_info *filter);
int bnxt_hwrm_set_filter(struct bnxt *bp,
			 struct bnxt_vnic_info *vnic,
			 struct bnxt_filter_info *filter);

int bnxt_hwrm_exec_fwd_resp(struct bnxt *bp, void *fwd_cmd);

int bnxt_hwrm_func_driver_register(struct bnxt *bp, uint32_t flags,
				   uint32_t *vf_req_fwd);
int bnxt_hwrm_func_qcaps(struct bnxt *bp);
int bnxt_hwrm_func_driver_unregister(struct bnxt *bp, uint32_t flags);

int bnxt_hwrm_queue_qportcfg(struct bnxt *bp);

int bnxt_hwrm_stat_clear(struct bnxt *bp, struct bnxt_cp_ring_info *cpr);

int bnxt_hwrm_ver_get(struct bnxt *bp);

int bnxt_clear_all_hwrm_stat_ctxs(struct bnxt *bp);
void bnxt_free_hwrm_resources(struct bnxt *bp);
int bnxt_alloc_hwrm_resources(struct bnxt *bp);
int bnxt_set_hwrm_link_config(struct bnxt *bp, bool link_up);

#endif