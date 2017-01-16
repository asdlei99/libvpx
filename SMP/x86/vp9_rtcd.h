#ifndef VP9_RTCD_H_
#define VP9_RTCD_H_

#ifdef RTCD_C
#define RTCD_EXTERN
#else
#define RTCD_EXTERN extern
#endif

/*
 * VP9
 */

#include "vpx/vpx_integer.h"
#include "vp9/common/vp9_common.h"
#include "vp9/common/vp9_enums.h"

struct macroblockd;

/* Encoder forward decls */
struct macroblock;
struct vp9_variance_vtable;
struct search_site_config;
struct mv;
union int_mv;
struct yv12_buffer_config;

#ifdef __cplusplus
extern "C" {
#endif

int64_t vp9_block_error_c(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
#define vp9_block_error vp9_block_error_c

int vp9_diamond_search_sad_c(const struct macroblock *x, const struct search_site_config *cfg,  struct mv *ref_mv, struct mv *best_mv, int search_param, int sad_per_bit, int *num00, const struct vp9_variance_vtable *fn_ptr, const struct mv *center_mv);
int vp9_diamond_search_sad_avx(const struct macroblock *x, const struct search_site_config *cfg,  struct mv *ref_mv, struct mv *best_mv, int search_param, int sad_per_bit, int *num00, const struct vp9_variance_vtable *fn_ptr, const struct mv *center_mv);
RTCD_EXTERN int (*vp9_diamond_search_sad)(const struct macroblock *x, const struct search_site_config *cfg,  struct mv *ref_mv, struct mv *best_mv, int search_param, int sad_per_bit, int *num00, const struct vp9_variance_vtable *fn_ptr, const struct mv *center_mv);

void vp9_fdct8x8_quant_c(const int16_t *input, int stride, tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void vp9_fdct8x8_quant_ssse3(const int16_t *input, int stride, tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
RTCD_EXTERN void (*vp9_fdct8x8_quant)(const int16_t *input, int stride, tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);

void vp9_fht16x16_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void vp9_fht16x16_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
RTCD_EXTERN void (*vp9_fht16x16)(const int16_t *input, tran_low_t *output, int stride, int tx_type);

void vp9_fht4x4_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void vp9_fht4x4_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
RTCD_EXTERN void (*vp9_fht4x4)(const int16_t *input, tran_low_t *output, int stride, int tx_type);

void vp9_fht8x8_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
void vp9_fht8x8_sse2(const int16_t *input, tran_low_t *output, int stride, int tx_type);
RTCD_EXTERN void (*vp9_fht8x8)(const int16_t *input, tran_low_t *output, int stride, int tx_type);

int vp9_full_search_sad_c(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct vp9_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);
int vp9_full_search_sadx3(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct vp9_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);
int vp9_full_search_sadx8(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct vp9_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);
RTCD_EXTERN int (*vp9_full_search_sad)(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct vp9_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);

void vp9_fwht4x4_c(const int16_t *input, tran_low_t *output, int stride);
void vp9_fwht4x4_sse2(const int16_t *input, tran_low_t *output, int stride);
RTCD_EXTERN void (*vp9_fwht4x4)(const int16_t *input, tran_low_t *output, int stride);

int64_t vp9_highbd_block_error_c(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz, int bd);
int64_t vp9_highbd_block_error_sse2(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz, int bd);
RTCD_EXTERN int64_t (*vp9_highbd_block_error)(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz, int bd);

int64_t vp9_highbd_block_error_8bit_c(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
int64_t vp9_highbd_block_error_8bit_sse2(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
int64_t vp9_highbd_block_error_8bit_avx(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
RTCD_EXTERN int64_t (*vp9_highbd_block_error_8bit)(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);

void vp9_highbd_fht16x16_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define vp9_highbd_fht16x16 vp9_highbd_fht16x16_c

void vp9_highbd_fht4x4_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define vp9_highbd_fht4x4 vp9_highbd_fht4x4_c

void vp9_highbd_fht8x8_c(const int16_t *input, tran_low_t *output, int stride, int tx_type);
#define vp9_highbd_fht8x8 vp9_highbd_fht8x8_c

void vp9_highbd_fwht4x4_c(const int16_t *input, tran_low_t *output, int stride);
#define vp9_highbd_fwht4x4 vp9_highbd_fwht4x4_c

void vp9_highbd_iht16x16_256_add_c(const tran_low_t *input, uint8_t *output, int pitch, int tx_type, int bd);
#define vp9_highbd_iht16x16_256_add vp9_highbd_iht16x16_256_add_c

void vp9_highbd_iht4x4_16_add_c(const tran_low_t *input, uint8_t *dest, int stride, int tx_type, int bd);
#define vp9_highbd_iht4x4_16_add vp9_highbd_iht4x4_16_add_c

void vp9_highbd_iht8x8_64_add_c(const tran_low_t *input, uint8_t *dest, int stride, int tx_type, int bd);
#define vp9_highbd_iht8x8_64_add vp9_highbd_iht8x8_64_add_c

void vp9_highbd_quantize_fp_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define vp9_highbd_quantize_fp vp9_highbd_quantize_fp_c

void vp9_highbd_quantize_fp_32x32_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define vp9_highbd_quantize_fp_32x32 vp9_highbd_quantize_fp_32x32_c

void vp9_highbd_temporal_filter_apply_c(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);
#define vp9_highbd_temporal_filter_apply vp9_highbd_temporal_filter_apply_c

void vp9_iht16x16_256_add_c(const tran_low_t *input, uint8_t *output, int pitch, int tx_type);
void vp9_iht16x16_256_add_sse2(const tran_low_t *input, uint8_t *output, int pitch, int tx_type);
RTCD_EXTERN void (*vp9_iht16x16_256_add)(const tran_low_t *input, uint8_t *output, int pitch, int tx_type);

void vp9_iht4x4_16_add_c(const tran_low_t *input, uint8_t *dest, int stride, int tx_type);
void vp9_iht4x4_16_add_sse2(const tran_low_t *input, uint8_t *dest, int stride, int tx_type);
RTCD_EXTERN void (*vp9_iht4x4_16_add)(const tran_low_t *input, uint8_t *dest, int stride, int tx_type);

void vp9_iht8x8_64_add_c(const tran_low_t *input, uint8_t *dest, int stride, int tx_type);
void vp9_iht8x8_64_add_sse2(const tran_low_t *input, uint8_t *dest, int stride, int tx_type);
RTCD_EXTERN void (*vp9_iht8x8_64_add)(const tran_low_t *input, uint8_t *dest, int stride, int tx_type);

void vp9_quantize_fp_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define vp9_quantize_fp vp9_quantize_fp_c

void vp9_quantize_fp_32x32_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define vp9_quantize_fp_32x32 vp9_quantize_fp_32x32_c

void vp9_temporal_filter_apply_c(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);
void vp9_temporal_filter_apply_sse2(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);
RTCD_EXTERN void (*vp9_temporal_filter_apply)(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);

void vp9_rtcd(void);

#ifdef RTCD_C
#include "vpx_ports/x86.h"
static void setup_rtcd_internal(void)
{
    int flags = x86_simd_caps();

    (void)flags;

    vp9_diamond_search_sad = vp9_diamond_search_sad_c;
    if (flags & HAS_AVX) vp9_diamond_search_sad = vp9_diamond_search_sad_avx;
    vp9_fdct8x8_quant = vp9_fdct8x8_quant_c;
    if (flags & HAS_SSSE3) vp9_fdct8x8_quant = vp9_fdct8x8_quant_ssse3;
    vp9_fht16x16 = vp9_fht16x16_c;
    if (flags & HAS_SSE2) vp9_fht16x16 = vp9_fht16x16_sse2;
    vp9_fht4x4 = vp9_fht4x4_c;
    if (flags & HAS_SSE2) vp9_fht4x4 = vp9_fht4x4_sse2;
    vp9_fht8x8 = vp9_fht8x8_c;
    if (flags & HAS_SSE2) vp9_fht8x8 = vp9_fht8x8_sse2;
    vp9_full_search_sad = vp9_full_search_sad_c;
    if (flags & HAS_SSE3) vp9_full_search_sad = vp9_full_search_sadx3;
    if (flags & HAS_SSE4_1) vp9_full_search_sad = vp9_full_search_sadx8;
    vp9_fwht4x4 = vp9_fwht4x4_c;
    if (flags & HAS_SSE2) vp9_fwht4x4 = vp9_fwht4x4_sse2;
    vp9_highbd_block_error = vp9_highbd_block_error_c;
    if (flags & HAS_SSE2) vp9_highbd_block_error = vp9_highbd_block_error_sse2;
    vp9_highbd_block_error_8bit = vp9_highbd_block_error_8bit_c;
    if (flags & HAS_SSE2) vp9_highbd_block_error_8bit = vp9_highbd_block_error_8bit_sse2;
    if (flags & HAS_AVX) vp9_highbd_block_error_8bit = vp9_highbd_block_error_8bit_avx;
    vp9_iht16x16_256_add = vp9_iht16x16_256_add_c;
    if (flags & HAS_SSE2) vp9_iht16x16_256_add = vp9_iht16x16_256_add_sse2;
    vp9_iht4x4_16_add = vp9_iht4x4_16_add_c;
    if (flags & HAS_SSE2) vp9_iht4x4_16_add = vp9_iht4x4_16_add_sse2;
    vp9_iht8x8_64_add = vp9_iht8x8_64_add_c;
    if (flags & HAS_SSE2) vp9_iht8x8_64_add = vp9_iht8x8_64_add_sse2;
    vp9_temporal_filter_apply = vp9_temporal_filter_apply_c;
    if (flags & HAS_SSE2) vp9_temporal_filter_apply = vp9_temporal_filter_apply_sse2;
}
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif
