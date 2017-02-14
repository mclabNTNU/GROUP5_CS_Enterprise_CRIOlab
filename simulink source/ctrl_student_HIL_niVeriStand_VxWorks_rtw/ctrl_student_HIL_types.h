/*
 * ctrl_student_HIL_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.128
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Feb 14 15:58:29 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_HIL_types_h_
#define RTW_HEADER_ctrl_student_HIL_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef _DEFINED_TYPEDEF_FOR_struct_WEndDd5z8WjUYRTCKDNizF_
#define _DEFINED_TYPEDEF_FOR_struct_WEndDd5z8WjUYRTCKDNizF_

typedef struct {
  real_T Enable;
  real_T length;
  real_T threshold;
} struct_WEndDd5z8WjUYRTCKDNizF;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_iTdVtkn32GXKLcWyghsjmG_
#define _DEFINED_TYPEDEF_FOR_struct_iTdVtkn32GXKLcWyghsjmG_

typedef struct {
  real_T c_u;
  real_T c_v;
  real_T c_psi;
} struct_iTdVtkn32GXKLcWyghsjmG;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_O1cG5VeM3Vq2W5nll3MmiD_
#define _DEFINED_TYPEDEF_FOR_struct_O1cG5VeM3Vq2W5nll3MmiD_

typedef struct {
  struct_iTdVtkn32GXKLcWyghsjmG omega;
} struct_O1cG5VeM3Vq2W5nll3MmiD;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_J8CQbjffsDnivVbE7QRY9_
#define _DEFINED_TYPEDEF_FOR_struct_J8CQbjffsDnivVbE7QRY9_

typedef struct {
  real_T SensNoiseEnabled;
  struct_WEndDd5z8WjUYRTCKDNizF Freeze;
  real_T Step_size;
  real_T Sample_time;
  real_T Sample_rate;
  real_T Thrust_lim[3];
  struct_O1cG5VeM3Vq2W5nll3MmiD Lowpass;
} struct_J8CQbjffsDnivVbE7QRY9;

#endif

/* Parameters (auto storage) */
typedef struct P_ctrl_student_HIL_T_ P_ctrl_student_HIL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ctrl_student_HIL_T RT_MODEL_ctrl_student_HIL_T;

#endif                                 /* RTW_HEADER_ctrl_student_HIL_types_h_ */
